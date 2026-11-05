#include "user/DriverLicense.hpp"

bool DriverLicense::isValid(int currentYear) const {
    return !number_.empty() && expiryYear_ >= currentYear;
}

bool DriverLicense::hasCategory(char c) const {
    return categories_.find(c) != std::string::npos;
}
