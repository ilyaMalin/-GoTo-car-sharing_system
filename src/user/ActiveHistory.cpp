#include "user/ActiveHistory.hpp"

bool ActiveHistory::hasActive() const { return current() != nullptr; }

const RentalRecord* ActiveHistory::current() const {
    for (const auto& r : records_)
        if (r.active()) return &r;
    return nullptr;
}

bool ActiveHistory::start(int vehicleId, std::time_t now) {
    if (hasActive()) return false;
    RentalRecord r;
    r.vehicleId = vehicleId;
    r.start = now;
    records_.push_back(r);
    return true;
}

bool ActiveHistory::finish(std::time_t now, double cost) {
    for (auto& r : records_) {
        if (r.active()) {
            r.end = now;
            r.cost = cost;
            return true;
        }
    }
    return false;
}

double ActiveHistory::totalSpent() const {
    double sum = 0;
    for (const auto& r : records_) sum += r.cost;
    return sum;
}
