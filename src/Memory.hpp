#pragma once

#include "Stuffwaffe.hpp"

namespace sw {
    struct Module {
        unsigned long base;
        unsigned long size;
        HMODULE hModule;
    };

    class Memory {
    public:
        Memory();
        virtual ~Memory() = default;

        virtual int IsOk();
        
        template<typename T>
        T Read(unsigned long address) {
            T value;
            ReadProcessMemory(m_process, (LPCVOID)address, &value, sizeof(value), nullptr);
            return value;
        }

        template<typename T>
        bool Write(unsigned long address, T value) {
            return WriteProcessMemory(m_process, (LPVOID)address, &value, sizeof(value), nullptr);
        }

        virtual void* HandleProcess(std::string_view name);
        virtual bool Dump(Module mod);
        virtual bool CheckMask(int offset, const unsigned char* pattern, std::string_view mask);
        virtual Module FindModule(std::string_view name);
        virtual unsigned long FindPattern(Module mod, const unsigned char* pattern, std::string_view mask, unsigned long value = 0, bool substract = false);

        virtual unsigned long GetPID();
        virtual void* GetProcess();
        virtual Module GetClient();
        virtual Module GetEngine();

    private:
        unsigned long m_pid;
        void* m_process;
        Module m_client;
        Module m_engine;
        unsigned char* m_dumpedRegion;

    };
};