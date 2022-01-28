#include "Player.hpp"

namespace sw {
    Player::Player(std::shared_ptr<Memory> memory, unsigned long base) {
        m_memory = memory;
        m_base = base;
    }

    bool Player::IsValid() {
        if(!m_memory || !m_base) {
            return false;
        }

        unsigned long health = GetHealth();
        return (health > 0 && health <= 100) && !GetDormant();
    }

    bool Player::IsSpotted() {
        return m_memory->Read<bool>(m_base + offset::m_bSpotted);
    }

    bool Player::IsMoving() {
        Vec3<float> vector = GetVelocity();
        float sum = vector.GetX() + vector.GetY() + vector.GetZ();
        return sum < -0.003 || sum > 0;
    }

    void Player::SetAttackState(unsigned long value) {
        m_memory->Write<unsigned long>(m_memory->GetClient().base + offset::dwForceAttack, value);
    }

    void Player::SetJumpState(unsigned long value) {
        m_memory->Write<unsigned long>(m_memory->GetClient().base + offset::dwForceJump, value);
    }

    void Player::SetFlashDuration(float value) {
        m_memory->Write<float>(m_base + offset::m_flFlashDuration, value);
    }

    void Player::SetSpotted(bool value) {
        m_memory->Write<bool>(m_base + offset::m_bSpotted, value);
    }

    unsigned long Player::GetHealth() {
        return m_memory->Read<unsigned long>(m_base + offset::m_iHealth);
    }

    bool Player::GetDormant() {
        return m_memory->Read<bool>(m_base + offset::m_bDormant);
    }

    int Player::GetTeam() {
        return m_memory->Read<int>(m_base + offset::m_iTeamNum);
    }

    unsigned char Player::GetFlags() {
        return m_memory->Read<unsigned char>(m_base + offset::m_fFlags);
    }

    float Player::GetFlashDuration() {
        return m_memory->Read<float>(m_base + offset::m_flFlashDuration);
    }

    int Player::GetGlowIndex() {
        return m_memory->Read<int>(m_base + offset::m_iGlowIndex);
    }

    unsigned long Player::GetBaseAddress() {
        return m_base;
    }

    Vec3f Player::GetVelocity() {
        return m_memory->Read<Vec3f>(m_base + offset::m_vecVelocity);
    }

    Vec3f Player::GetOrigin() {
        return m_memory->Read<Vec3f>(m_base + offset::m_vecOrigin);
    }
};