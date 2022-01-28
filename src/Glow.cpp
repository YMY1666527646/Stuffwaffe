#include "Glow.hpp"

namespace sw {
    void Glow::GlowFor(std::shared_ptr<Memory> memory, std::shared_ptr<Player> target, unsigned long glow, float value) {
        GlowProps props = memory->Read<GlowProps>(glow + (target->GetGlowIndex() * 0x38));
        props.red = 1.0f - value / 2.0f;
        props.green = value;
        props.blue = 0.0f;
        props.alpha = 0.9f;
        props.occluded = true;
        props.unoccluded = false;
        memory->Write<GlowProps>(glow + (target->GetGlowIndex() * 0x38), props);
        target->SetSpotted(true);
    }

    void Glow::ThreadedGlow(std::shared_ptr<Memory> memory, std::shared_ptr<Player> player, std::shared_ptr<Status> status) {
        unsigned long object;
        for(;;) {
            if(status->game) {
                if(status->glow) {
                    object = memory->Read<unsigned long>(memory->GetClient().base + offset::dwGlowObjectManager);

                    for(auto i = 0; i < 32; ++i) {
                        std::shared_ptr<Player> enemy = std::make_shared<Player>(memory, memory->Read<unsigned long>(memory->GetClient().base + offset::dwEntityList + (short)0x10 * i));

                        if(enemy->IsValid()) {
                            if(player->GetTeam() != enemy->GetTeam()) {
                                float diff = enemy->GetHealth() / 100.0f;
                                GlowFor(memory, enemy, object, diff);
                            }
                        }
                    }
                }
            } else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
};