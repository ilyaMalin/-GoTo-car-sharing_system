#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>

bool initializeDatabase();
bool registerUser(const std::string& login,
                  const std::string& password,
                  const std::string& phone);
bool loginUser(const std::string& login,
               const std::string& password);

#endif
