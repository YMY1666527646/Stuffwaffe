#pragma once

#include "Stuffwaffe.hpp"
#include "Memory.hpp"

namespace sw {
    class VAC {
    public:
        VAC(std::shared_ptr<Memory> memory = nullptr);
        virtual ~VAC() = default;

        virtual void CheckDebug();
        virtual void ErasePEHeaders();

    private:
        HMODULE m_module;
        void* m_process;

    };
};