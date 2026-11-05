#pragma once
#include <string>

class DriverLicense {
public:
    DriverLicense() = default;
    DriverLicense(std::string number, std::string categories, int expiryYear)
        : number_(std::move(number)), categories_(std::move(categories)),
          expiryYear_(expiryYear) {}

    const std::string& number() const { return number_; }
    const std::string& categories() const { return categories_; }
    int expiryYear() const { return expiryYear_; }

    bool isValid(int currentYear) const;
    bool hasCategory(char category) const;

private:
    std::string number_;
    std::string categories_;
    int expiryYear_ = 0;
};
