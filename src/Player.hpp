#pragma once

#include "Stuffwaffe.hpp"
#include "Offsets.hpp"
#include "Memory.hpp"
#include "Math.hpp"

namespace sw {
    class Player {
    public:
        Player(std::shared_ptr<Memory> memory = nullptr, unsigned long base = 0);
        virtual ~Player() = default;

        virtual bool IsValid();
        virtual bool IsSpotted();
        virtual bool IsMoving();

        virtual void SetAttackState(unsigned long value);
        virtual void SetJumpState(unsigned long value);
        virtual void SetFlashDuration(float value);
        virtual void SetSpotted(bool value);

        virtual unsigned long GetHealth();
        virtual bool GetDormant();
        virtual int GetTeam();
        virtual unsigned char GetFlags();
        virtual float GetFlashDuration();
        virtual int GetGlowIndex();
        virtual unsigned long GetBaseAddress();
        virtual Vec3f GetVelocity();
        virtual Vec3f GetOrigin();

    private:
        std::shared_ptr<Memory> m_memory;
        unsigned long m_base;

    };
};