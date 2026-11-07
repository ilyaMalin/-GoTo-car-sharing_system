#pragma once
#include "user/IUser.hpp"

class Guest : public IUser {
public:
    int getId() const override { return 0; }
    const std::string& getLogin() const override { return login_; }
    UserRole getRole() const override { return UserRole::User; }
    bool checkPassword(const std::string&) const override { return false; }
    bool canRent() const override { return false; }
    bool canManageVehicles() const override { return false; }
    bool canManageUsers() const override { return false; }
    double rentalDiscount() const override { return 0.0; }
    std::string describe() const override { return "Guest"; }

private:
    std::string login_ = "guest";
};
