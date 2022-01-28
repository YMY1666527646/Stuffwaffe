#pragma once

#include "Stuffwaffe.hpp"
#include "Memory.hpp"
#include "Player.hpp"

namespace sw {
    class Client {
    public:
        Client(std::shared_ptr<Memory> memory = nullptr);
        virtual ~Client() = default;

        virtual bool IsGame();

        virtual void SetSensitivity(float value);
        virtual void ResetSensitivity();

        virtual Player GetLocalPlayer();
        virtual unsigned long GetClientState();
        virtual float GetSensitivity();

    private:
        std::shared_ptr<Memory> m_memory;
        float m_defaultSensitivity;
    
    };
};