#pragma once
#include <string>

enum class UserRole { User = 0, Admin = 1 };

class IUser {
public:
    virtual ~IUser() = default;
    virtual int getId() const = 0;
    virtual const std::string& getLogin() const = 0;
    virtual UserRole getRole() const = 0;
    virtual bool checkPassword(const std::string& plainPassword) const = 0;
    virtual bool canRent() const = 0;
    virtual bool canManageVehicles() const = 0;
    virtual bool canManageUsers() const = 0;
    virtual double rentalDiscount() const = 0;
    virtual std::string describe() const = 0;
};
