#include "user/Admin.hpp"
#include "user/VipUser.hpp"
#include "user/Support.hpp"
#include "user/Guest.hpp"
#include <cassert>
#include <iostream>
#include <memory>

int main() {
    User u;
    assert(!User::create("ab", "pass123", u));
    assert(!User::create("aleksey", "123", u));
    assert(User::create("aleksey", "pass123", u));
    assert(u.checkPassword("pass123") && !u.checkPassword("wrong"));

    assert(!u.canRent());
    u.license() = DriverLicense("AB123456", "B", 2030);
    u.wallet().topUp(50);
    assert(u.canRent());
    u.history().start(7, 1000);
    assert(!u.canRent());
    u.history().finish(4600, 12.5);
    u.wallet().charge(12.5);
    assert(u.wallet().balance() == 37.5);

    assert(u.profile().setPhone("+375291234567"));
    assert(!u.profile().setEmail("bad"));

    std::unique_ptr<IUser> a = std::make_unique<Admin>(1, "root", "x");
    assert(a->canManageVehicles() && !a->canRent());
    std::unique_ptr<IUser> v = std::make_unique<VipUser>(2, "vip", "x");
    std::unique_ptr<IUser> sp = std::make_unique<Support>(3, "sup", "x");
    Guest g;
    assert(v->rentalDiscount() == 0.15 && sp->canManageUsers() && !sp->canManageVehicles());
    assert(!g.canRent() && !g.checkPassword("any"));
    assert(a->canManageUsers() && !u.canManageUsers());
    std::cout << u.describe() << "\n" << a->describe() << "\nALL OK\n";
}
