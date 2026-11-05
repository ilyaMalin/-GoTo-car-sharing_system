#pragma once

class Wallet {
public:
    explicit Wallet(double balance = 0.0) : balance_(balance) {}

    double balance() const { return balance_; }
    bool topUp(double amount);
    bool charge(double amount);
    bool hasEnough(double amount) const { return balance_ >= amount; }

private:
    double balance_;
};
