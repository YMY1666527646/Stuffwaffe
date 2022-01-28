#pragma once

#include "Stuffwaffe.hpp"
#include "Logger.hpp"
#include "Memory.hpp"
#include "Client.hpp"

namespace sw {
    enum weapon {
        WEAPON_AWP = 9,
        WEAPON_G3SG1 = 11,
        WEAPON_SCAR20 = 38,
        WEAPON_SSG = 40,
        WEAPON_AK47 = 7,
        WEAPON_AUG = 8,
        WEAPON_FAMAS = 10,
        WEAPON_GALILAR = 13,
        WEAPON_M4A1 = 60,
        WEAPON_M4A4 = 16,
        WEAPON_SG553 = 39,
        WEAPON_USP = 61,
        WEAPON_REVOLVER = 64,
        WEAPON_CZ75 = 63,
        WEAPON_DEAGLE = 1,
        WEAPON_BERETTAS = 2,
        WEAPON_FIVESEVEN = 3,
        WEAPON_GLOCK = 4,
        WEAPON_P2000 = 32,
        WEAPON_P250 = 36,
        WEAPON_TEC9 = 30,
        WEAPON_MAC10 = 17,
        WEAPON_MP7 = 33,
        WEAPON_MP9 = 34,
        WEAPON_MP5 = 23,
        WEAPON_PPBIZON = 26,
        WEAPON_P90 = 19,
        WEAPON_UMP45 = 24,
        WEAPON_MAG7 = 27,
        WEAPON_NOVA = 35,
        WEAPON_SAWEDOFF = 29,
        WEAPON_XM1014 = 25,
        WEAPON_M249 = 14,
        WEAPON_NEGEV = 28,

        WEAPON_KNIFE_T = 59,
        WEAPON_KNIFE_CT = 42,
        WEAPON_KNIFE_KARAM = 507,
        WEAPON_KNIFE_BAYONET = 500,
        WEAPON_KNIFE_CLASSIC = 503,
        WEAPON_KNIFE_FLIP = 505,
        WEAPON_KNIFE_GUT = 506,
        WEAPON_KNIFE_M9 = 508,
        WEAPON_KNIFE_HUNTSMAN = 509,
        WEAPON_KNIFE_FALCHION = 512,
        WEAPON_KNIFE_BOWIE = 514,
        WEAPON_KNIFE_BUTTERFLY = 515,
        WEAPON_KNIFE_DAGGERS = 516,
        WEAPON_KNIFE_PARACORD = 517,
        WEAPON_KNIFE_SURVIVAL = 518,
        WEAPON_KNIFE_URSUS = 519,
        WEAPON_KNIFE_NAVAJA = 520,
        WEAPON_KNIFE_NOMAD = 521,
        WEAPON_KNIFE_STILETTO = 522,
        WEAPON_KNIFE_TALON = 523,
        WEAPON_KNIFE_SKELETON = 525,
    };

    class Skinchanger {
    public:
        Skinchanger() = default;
        virtual ~Skinchanger() = default;

        static void ForceUpdate(std::shared_ptr<Memory> memory);
        static void Skin(std::shared_ptr<Memory> memory, std::shared_ptr<Client> client);
    };
};