#include "user/Admin.hpp"

std::string Admin::describe() const {
    return "Admin #" + std::to_string(id_) + " " + login_;
}
