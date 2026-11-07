#pragma once
#include "user/IUser.hpp"
#include "user/UserProfile.hpp"
#include "user/DriverLicense.hpp"
#include "user/Wallet.hpp"
#include "user/ActiveHistory.hpp"
#include "user/UserSettings.hpp"
#include <string>

class User : public IUser {
public:
    
    static bool create(const std::string& login, const std::string& plainPassword,
                       User& out);

    User() = default;
    User(int id, std::string login, std::string passwordHash);

    int getId() const override { return id_; }
    const std::string& getLogin() const override { return login_; }
    UserRole getRole() const override { return UserRole::User; }
    bool checkPassword(const std::string& plain) const override;
    bool canRent() const override;
    bool canManageVehicles() const override { return false; }
    bool canManageUsers() const override { return false; }
    double rentalDiscount() const override { return 0.0; }
    std::string describe() const override;

    void setId(int id) { id_ = id; }
    const std::string& passwordHash() const { return passwordHash_; }

    UserProfile& profile() { return profile_; }
    const UserProfile& profile() const { return profile_; }
    DriverLicense& license() { return license_; }
    const DriverLicense& license() const { return license_; }
    Wallet& wallet() { return wallet_; }
    const Wallet& wallet() const { return wallet_; }
    ActiveHistory& history() { return history_; }
    const ActiveHistory& history() const { return history_; }
    UserSettings& settings() { return settings_; }

    bool changePassword(const std::string& oldPlain, const std::string& newPlain);

protected:
    int id_ = 0;
    std::string login_;
    std::string passwordHash_;
    UserProfile profile_;
    DriverLicense license_;
    Wallet wallet_;
    ActiveHistory history_;
    UserSettings settings_;
};
