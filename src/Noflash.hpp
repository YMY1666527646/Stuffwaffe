#pragma once

#include "Stuffwaffe.hpp"
#include "Client.hpp"

namespace sw {
    class Noflash {
    public:
        Noflash(std::shared_ptr<Client> client = nullptr);
        virtual ~Noflash() = default;

        virtual void Hide();
        static void ThreadedHide(std::shared_ptr<Client> client, std::shared_ptr<Status> status);

    private:
        std::shared_ptr<Client> m_client;
        Player m_player;

    };
};