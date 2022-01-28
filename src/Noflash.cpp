#include "Noflash.hpp"

namespace sw {
    Noflash::Noflash(std::shared_ptr<Client> client) {
        m_client = client;
        m_player = client->GetLocalPlayer();
    }

    void Noflash::Hide() {
        if(m_player.IsValid() && m_player.GetFlashDuration() > 0.0f) {
            m_player.SetFlashDuration(0.0f);
        }
    }
    
    void Noflash::ThreadedHide(std::shared_ptr<Client> client, std::shared_ptr<Status> status) {
        Player player = client->GetLocalPlayer();

        for(;;) {
            if(status->game) {
                if(status->noflash) {
                    if(player.IsValid() && player.GetFlashDuration() > 0.0f) {
                        player.SetFlashDuration(0.0f);
                    }
                }
            } else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
    }
};