#pragma once
#include <ctime>
#include <vector>

struct RentalRecord {
    int vehicleId = 0;
    std::time_t start = 0;
    std::time_t end = 0;
    double cost = 0.0;
    bool active() const { return end == 0; }
};

class ActiveHistory {
public:
    bool start(int vehicleId, std::time_t now);
    bool finish(std::time_t now, double cost);
    bool hasActive() const;
    const RentalRecord* current() const;
    const std::vector<RentalRecord>& records() const { return records_; }
    double totalSpent() const;
    void add(const RentalRecord& r) { records_.push_back(r); }

private:
    std::vector<RentalRecord> records_;
};
