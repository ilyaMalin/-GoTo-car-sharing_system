#include "user/Wallet.hpp"

bool Wallet::topUp(double amount) {
    if (amount <= 0) return false;
    balance_ += amount;
    return true;
}

bool Wallet::charge(double amount) {
    if (amount <= 0 || amount > balance_) return false;
    balance_ -= amount;
    return true;
}
