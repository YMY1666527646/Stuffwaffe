#include "Skinchanger.hpp"

namespace sw {
    void Skinchanger::ForceUpdate(std::shared_ptr<Memory> memory) {
        unsigned long clientState = memory->Read<unsigned long>(memory->GetEngine().base + offset::dwClientState);
        memory->Write<int>(clientState + 0x16C, -1);
    }

    void Skinchanger::Skin(std::shared_ptr<Memory> memory, std::shared_ptr<Client> client) {
        for(;;) {
            for(auto i = 1; i <= 3; ++i) {
                unsigned long weaponIndex = memory->Read<unsigned long>(client->GetLocalPlayer().GetBaseAddress() + offset::m_hMyWeapons + ((i - 1) * 0x4)) & 0xFFF;
                unsigned long weaponEntity = memory->Read<unsigned long>(memory->GetClient().base + offset::dwEntityList + (weaponIndex - 1) * 0x10);
                int currentWeaponId = memory->Read<int>(weaponEntity + offset::m_iItemDefinitionIndex);
                int owner = memory->Read<int>(weaponEntity + offset::m_OriginalOwnerXuidLow);

                Logger::Log(std::to_string(currentWeaponId), Color.at(Colors::Blue));
                unsigned long weaponSkin = 0;
                int seed = 420;

                if(currentWeaponId != 0) {
                    memory->Write<int>(weaponEntity + offset::m_iItemIDHigh, -1);
                }

                if(currentWeaponId == weapon::WEAPON_GLOCK) {
                    weaponSkin = 38;
                    seed = 420;
                    memory->Write<int>(weaponEntity + offset::m_nFallbackPaintKit, weaponSkin);
                    memory->Write<int>(weaponEntity + offset::m_iAccountID, owner);
                    memory->Write<int>(weaponEntity + offset::m_nFallbackSeed, seed);
                    memory->Write<float>(weaponEntity + offset::m_flFallbackWear, 0.001f);
                } else if(currentWeaponId == weapon::WEAPON_USP) {
                    weaponSkin = 654;
                    seed = 420;
                    memory->Write<int>(weaponEntity + offset::m_nFallbackPaintKit, weaponSkin);
                    memory->Write<int>(weaponEntity + offset::m_iAccountID, owner);
                    memory->Write<int>(weaponEntity + offset::m_nFallbackSeed, seed);
                    memory->Write<float>(weaponEntity + offset::m_flFallbackWear, 0.001f);
                }

                if(GetAsyncKeyState(VK_LEFT)) {
                    memory->Write<int>(client->GetClientState() + 0x174, -1);
                }
            }
        }
    }
};