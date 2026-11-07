#include "user/VipUser.hpp"

std::string VipUser::describe() const {
    return "VIP #" + std::to_string(id_) + " " + login_ + " (" + profile_.fullName() + ")";
}
