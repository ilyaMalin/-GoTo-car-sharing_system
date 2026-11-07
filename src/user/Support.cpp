#include "user/Support.hpp"

std::string Support::describe() const {
    return "Support #" + std::to_string(id_) + " " + login_;
}
