#include "user/UserValidator.hpp"
#include <cctype>

bool UserValidator::isValidLogin(const std::string& s) {
    if (s.size() < 3 || s.size() > 20) return false;
    for (unsigned char c : s)
        if (!std::isalnum(c) && c != '_') return false;
    return true;
}

bool UserValidator::isValidPassword(const std::string& s) {
    if (s.size() < 6) return false;
    bool letter = false, digit = false;
    for (unsigned char c : s) {
        if (std::isalpha(c)) letter = true;
        if (std::isdigit(c)) digit = true;
    }
    return letter && digit;
}

bool UserValidator::isValidEmail(const std::string& s) {
    auto at = s.find('@');
    if (at == std::string::npos || at == 0) return false;
    auto dot = s.find('.', at);
    return dot != std::string::npos && dot > at + 1 && dot + 1 < s.size();
}

bool UserValidator::isValidPhone(const std::string& s) {
    if (s.size() < 10 || s.size() > 16 || s[0] != '+') return false;
    for (std::size_t i = 1; i < s.size(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
    return true;
}
