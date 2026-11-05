#pragma once
#include <string>

class UserProfile {
public:
    UserProfile() = default;
    UserProfile(std::string firstName, std::string lastName,
                std::string phone, std::string email)
        : firstName_(std::move(firstName)), lastName_(std::move(lastName)),
          phone_(std::move(phone)), email_(std::move(email)) {}

    const std::string& firstName() const { return firstName_; }
    const std::string& lastName()  const { return lastName_; }
    const std::string& phone()     const { return phone_; }
    const std::string& email()     const { return email_; }

    bool setPhone(const std::string& phone);
    bool setEmail(const std::string& email);
    void setName(const std::string& first, const std::string& last);
    std::string fullName() const;

private:
    std::string firstName_, lastName_, phone_, email_;
};
