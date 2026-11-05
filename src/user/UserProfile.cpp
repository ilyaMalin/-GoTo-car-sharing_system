#include "user/UserProfile.hpp"
#include "user/UserValidator.hpp"

bool UserProfile::setPhone(const std::string& phone) {
    if (!UserValidator::isValidPhone(phone)) return false;
    phone_ = phone;
    return true;
}

bool UserProfile::setEmail(const std::string& email) {
    if (!UserValidator::isValidEmail(email)) return false;
    email_ = email;
    return true;
}

void UserProfile::setName(const std::string& first, const std::string& last) {
    firstName_ = first;
    lastName_ = last;
}

std::string UserProfile::fullName() const {
    return firstName_ + " " + lastName_;
}
