#include "user/User.hpp"
#include "user/PasswordHasher.hpp"
#include "user/UserValidator.hpp"
#include <ctime>

static int currentYear() {
    std::time_t t = std::time(nullptr);
    return std::localtime(&t)->tm_year + 1900;
}

User::User(int id, std::string login, std::string passwordHash)
    : id_(id), login_(std::move(login)), passwordHash_(std::move(passwordHash)) {}

bool User::create(const std::string& login, const std::string& plain, User& out) {
    if (!UserValidator::isValidLogin(login)) return false;
    if (!UserValidator::isValidPassword(plain)) return false;
    out = User(0, login, PasswordHasher::hash(plain));
    return true;
}

bool User::checkPassword(const std::string& plain) const {
    return PasswordHasher::verify(plain, passwordHash_);
}

bool User::canRent() const {
    return license_.isValid(currentYear()) && wallet_.balance() > 0
           && !history_.hasActive();
}

bool User::changePassword(const std::string& oldPlain, const std::string& newPlain) {
    if (!checkPassword(oldPlain) || !UserValidator::isValidPassword(newPlain))
        return false;
    passwordHash_ = PasswordHasher::hash(newPlain);
    return true;
}

std::string User::describe() const {
    return "User #" + std::to_string(id_) + " " + login_ + " (" + profile_.fullName() + ")";
}
