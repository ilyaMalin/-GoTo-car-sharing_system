#pragma once
#include "user/User.hpp"

class Support : public User {
public:
    Support() = default;
    Support(int id, std::string login, std::string passwordHash)
        : User(id, std::move(login), std::move(passwordHash)) {}

    bool canRent() const override { return false; }
    bool canManageUsers() const override { return true; }
    std::string describe() const override;
};
