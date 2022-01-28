#include "Client.hpp"

namespace sw {
    Client::Client(std::shared_ptr<Memory> memory) {
        m_memory = memory;
        m_defaultSensitivity = GetSensitivity();
    }

    bool Client::IsGame() {
        if(!m_memory->GetProcess() && !m_memory->GetClient().base && !m_memory->GetEngine().base) {
            return false;
        } else {
            return m_memory->Read<unsigned long>(GetClientState() + offset::dwClientState_State) == 6;
        }
    }

    void Client::SetSensitivity(float value) {
        std::uint32_t sensitivityPtr = m_memory->Read<std::uint32_t>(m_memory->GetClient().base + offset::dwSensitivityPtr);
        std::uint32_t sensitivity = m_memory->Read<std::uint32_t>(m_memory->GetClient().base + offset::dwSensitivity);
        m_memory->Write<std::uint32_t>(m_memory->GetClient().base + offset::dwSensitivity, sensitivity);
    }

    void Client::ResetSensitivity() {
        if(m_memory->GetProcess() && m_memory->GetClient().base && m_memory->GetEngine().base) {
            SetSensitivity(m_defaultSensitivity);
        }
    }

    Player Client::GetLocalPlayer() {
        unsigned long id = m_memory->Read<unsigned long>(GetClientState() + offset::dwClientState_GetLocalPlayer);
        return Player(m_memory, m_memory->Read<unsigned long>(m_memory->GetClient().base + offset::dwEntityList + id * 0x10));
    }

    unsigned long Client::GetClientState() {
        return m_memory->Read<unsigned long>(m_memory->GetEngine().base + offset::dwClientState);
    }

    float Client::GetSensitivity() {
        std::uint32_t sensitivityPtr = m_memory->Read<std::uint32_t>(m_memory->GetClient().base + offset::dwSensitivityPtr);
        std::uint32_t sensitivity = m_memory->Read<std::uint32_t>(m_memory->GetClient().base + offset::dwSensitivity);
        sensitivity ^= sensitivityPtr;
        return *reinterpret_cast<float*>(&sensitivity);
    }
};