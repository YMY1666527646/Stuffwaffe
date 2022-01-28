#include "Memory.hpp"

namespace sw {
    Memory::Memory() {
        HandleProcess("csgo.exe");

        m_client = FindModule("client.dll");
        m_engine = FindModule("engine.dll");
    }

    int Memory::IsOk() {
        if(m_process != nullptr && m_client.base && m_engine.base) {
            return 1;
        } else {
            return 0;
        }
    }

    void* Memory::HandleProcess(std::string_view name) {
        void* handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 entry;
        entry.dwSize = sizeof(entry);

        while(Process32Next(handle, &entry)) {
            if(std::string_view((const char*)entry.szExeFile) == name) {
                m_pid = entry.th32ProcessID;
                CloseHandle(handle);
                m_process = OpenProcess(PROCESS_ALL_ACCESS, false, m_pid);
                return m_process;
            }
        }

        CloseHandle(handle);
        return nullptr;
    }

    bool Memory::Dump(Module mod) {
        m_dumpedRegion = new unsigned char[mod.size];
        if(ReadProcessMemory(m_process, (LPVOID)mod.base, m_dumpedRegion, mod.size, nullptr) == 0) {
            return false;
        }

        return true;
    }
    
    bool Memory::CheckMask(int offset, const unsigned char* pattern, std::string_view mask) {
        for(unsigned int i = 0; i < mask.length(); ++i) {
            if(mask.at(i) == '?') {
                continue;
            }

            if(mask.at(i) == 'x' && pattern[i] != m_dumpedRegion[offset + i]) {
                return false;
            }
        }

        return false;
    }
    
    Module Memory::FindModule(std::string_view name) {
        void* mod = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, m_pid);
        MODULEENTRY32 entry;
        entry.dwSize = sizeof(entry);
        
        while(Module32Next(mod, &entry)) {
            if(std::string_view((const char*)entry.szModule) == name) {
                CloseHandle(mod);
                return { (unsigned long)entry.modBaseAddr, entry.modBaseSize, entry.hModule };
            }
        }

        CloseHandle(mod);
        return { 0, 0, 0 };
    }

    unsigned long Memory::FindPattern(Module mod, const unsigned char* pattern, std::string_view mask, unsigned long value, bool substract) {
        if(m_dumpedRegion == nullptr) {
            if(!Dump(mod)) {
                return 0;
            }
        }

        for(unsigned long i = 0; i < mod.base + mod.size; ++i) {
            if(CheckMask(i, pattern, mask)) {
                return substract ? i + value : mod.base + i + value;
            }
        }

        return 0;
    }

    unsigned long Memory::GetPID() {
        return m_pid;
    }
    
    void* Memory::GetProcess() {
        return m_process;
    }
    
    Module Memory::GetClient() {
        return m_client;
    }
    
    Module Memory::GetEngine() {
        return m_engine;
    }
};