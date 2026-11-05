#pragma once
#include <string>

class PasswordHasher {
public:
    static std::string hash(const std::string& plain);
    static bool verify(const std::string& plain, const std::string& hashed);
};
