#include "user/PasswordHasher.hpp"
#include <cstdint>
#include <sstream>
#include <iomanip>

// Учебный хэш (FNV-1a 64 бит с солью). В реальном проекте нужен bcrypt/argon2.
std::string PasswordHasher::hash(const std::string& plain) {
    const std::string salted = "goto_salt_" + plain;
    std::uint64_t h = 1469598103934665603ULL;
    for (unsigned char c : salted) {
        h ^= c;
        h *= 1099511628211ULL;
    }
    std::ostringstream os;
    os << std::hex << std::setw(16) << std::setfill('0') << h;
    return os.str();
}

bool PasswordHasher::verify(const std::string& plain, const std::string& hashed) {
    return hash(plain) == hashed;
}
