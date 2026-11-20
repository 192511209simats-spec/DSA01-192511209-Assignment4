// Task 4 - Alternative: std::vector<std::unique_ptr<Account>> (no manual delete)
#include <iostream>
#include <memory>
#include <vector>
class Account {
public:
    virtual ~Account() { std::cout << "~Account\n"; }        // still REQUIRED for correct deletion
    virtual double rate() const { return 3.5; }
};
class SeniorAccount : public Account {
    std::unique_ptr<double[]> history = std::make_unique<double[]>(100);   // no manual delete[] either
public:
    ~SeniorAccount() override { std::cout << "~SeniorAccount\n"; }
    double rate() const override { return 4.0; }
};
int main() {
    std::vector<std::unique_ptr<Account>> v;
    v.push_back(std::make_unique<Account>());
    v.push_back(std::make_unique<SeniorAccount>());
    for (const auto& a : v) std::cout << a->rate() << "\n";
    // Auto-released at end of scope. Leak fixed automatically; but if ~Account were NOT virtual,
    // unique_ptr<Account> would still call the wrong destructor, and passing by value (slicing) still compiles.
}
