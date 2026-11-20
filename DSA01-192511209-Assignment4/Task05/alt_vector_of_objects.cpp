// Task 5 - Alternative: std::vector<Cart> (objects) instead of an array of Cart*
#include <iostream>
#include <vector>
class Cart {
    double prices_[10] = {};                 // a realistic cart carries data
    double total_;
public:
    Cart(double t) : total_(t) { prices_[0] = t; }
    double total() const { return total_; }
};
int main() {
    std::vector<Cart> v;
    v.reserve(2);
    v.emplace_back(100); v.emplace_back(500);
    Cart* p = &v[0];
    std::cout << "address before growth: " << p << "\n";
    v.emplace_back(300);                                 // exceeds capacity -> reallocation, objects are MOVED/COPIED
    std::cout << "address of v[0] now    : " << &v[0] << (p == &v[0] ? "  (same)\n" : "  (CHANGED -> p is dangling!)\n");
    // Do NOT dereference p here: undefined behaviour.

    const Cart* best = &v[0];                            // O(n) scan, same as the pointer version
    for (const Cart& c : v) if (c.total() > best->total()) best = &c;
    std::cout << "Highest total = " << best->total() << "\n";
    std::cout << "sizeof(Cart) = " << sizeof(Cart) << " bytes per element copied into the vector, vs "
              << sizeof(Cart*) << " bytes per pointer\n";
}
