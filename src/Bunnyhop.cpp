#include "Bunnyhop.hpp"

namespace sw {
    Bunnyhop::Bunnyhop(std::shared_ptr<Client> client) {
        m_client = client;
        m_player = client->GetLocalPlayer();
    }

    void Bunnyhop::Jump() {
        if(m_player.GetFlags() & 1 << 0 && m_player.IsMoving()) {
            m_player.SetJumpState(6);
        }
    }
    
    void Bunnyhop::ThreadedJump(std::shared_ptr<Client> client, std::shared_ptr<Status> status) {
        Player player = client->GetLocalPlayer();

        for(;;) {
            if(status->game) {
                bool space = GetAsyncKeyState(VK_SPACE);
                if(status->bunnyhop && space) {
                    if(player.GetFlags() & 1 << 0 && player.IsMoving()) {
                        player.SetJumpState(6);
                    }
                }
            } else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
    }
};