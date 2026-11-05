#pragma once
#include <string>

class UserValidator {
public:
    static bool isValidLogin(const std::string& login);
    static bool isValidPassword(const std::string& password);
    static bool isValidEmail(const std::string& email);
    static bool isValidPhone(const std::string& phone);
};
