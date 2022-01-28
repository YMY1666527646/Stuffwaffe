#include "VAC.hpp"

namespace sw {
    VAC::VAC(std::shared_ptr<Memory> memory) {
        m_process = memory->GetProcess();
        CheckDebug();
    }

    void VAC::CheckDebug() {
        bool isDebugPort = true;
        if(IsDebuggerPresent()) {
            ExitProcess(1);
        }

        if(!CheckRemoteDebuggerPresent((HANDLE)m_process, (PBOOL)&isDebugPort)) {
            ExitProcess(1);
        }

        if(isDebugPort) {
            ExitProcess(1);
        }
    }

    void VAC::ErasePEHeaders() {
        unsigned long oldProtect;
        VirtualProtect((char*)m_module, 4096, PAGE_READWRITE, &oldProtect);
        SecureZeroMemory((char*)m_module, 4096);
    }
};