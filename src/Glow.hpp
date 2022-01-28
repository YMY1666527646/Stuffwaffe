#pragma once

#include "Stuffwaffe.hpp"
#include "Memory.hpp"
#include "Player.hpp"
#include "Client.hpp"

namespace sw {
    struct GlowProps {
        unsigned char base[8];
        float red;
        float green;
        float blue;
        float alpha;
        unsigned char buffer[16];
        bool occluded;
        bool unoccluded;
        bool bloom;
        unsigned char dump[5];
        int style;
    };

    class Glow {
    public:
        Glow() = default;
        virtual ~Glow() = default;

        static void GlowFor(std::shared_ptr<Memory> memory, std::shared_ptr<Player> target, unsigned long glow, float value = 0.0f);
        static void ThreadedGlow(std::shared_ptr<Memory> memory, std::shared_ptr<Player> player, std::shared_ptr<Status> status);

    };
};