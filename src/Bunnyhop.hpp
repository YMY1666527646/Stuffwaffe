#pragma once

#include "Stuffwaffe.hpp"
#include "Client.hpp"

namespace sw {
    class Bunnyhop {
    public:
        Bunnyhop(std::shared_ptr<Client> client = nullptr);
        virtual ~Bunnyhop() = default;

        virtual void Jump();
        static void ThreadedJump(std::shared_ptr<Client> client, std::shared_ptr<Status> status);

    private:
        std::shared_ptr<Client> m_client;
        Player m_player;

    };  
};