#pragma once
#include "user/User.hpp"

class VipUser : public User {
public:
    VipUser() = default;
    VipUser(int id, std::string login, std::string passwordHash)
        : User(id, std::move(login), std::move(passwordHash)) {}

    double rentalDiscount() const override { return 0.15; }
    std::string describe() const override;
};
