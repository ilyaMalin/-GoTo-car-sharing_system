#pragma once
#include "user/User.hpp"

class Admin : public User {
public:
    Admin() = default;
    Admin(int id, std::string login, std::string passwordHash)
        : User(id, std::move(login), std::move(passwordHash)) {}

    UserRole getRole() const override { return UserRole::Admin; }
    bool canRent() const override { return false; }
    bool canManageVehicles() const override { return true; }
    bool canManageUsers() const override { return true; }
    std::string describe() const override;
};
