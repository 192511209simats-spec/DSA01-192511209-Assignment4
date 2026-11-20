// Task 4.3 - Repaired program: virtual functions, virtual destructor, pointers (no slicing copies)
// Build with sanitizer to prove it is clean: g++ -std=c++17 -Wall -Wextra -fsanitize=address -g repaired.cpp
#include <iostream>
class Account {
public:
    virtual ~Account() { std::cout << "~Account\n"; }
    virtual double rate() const { return 3.5; }
};
class SeniorAccount : public Account {
    double* history = new double[100];
public:
    ~SeniorAccount() override { delete[] history; std::cout << "~SeniorAccount (history released)\n"; }
    double rate() const override { return 4.0; }
};
int main() {
    Account* accounts[2] = { new Account, new SeniorAccount };
    for (Account* a : accounts) std::cout << a->rate() << "\n";   // 3.5 then 4
    for (Account* a : accounts) delete a;                         // full destruction chain

    SeniorAccount s;
    Account& ref = s;                                             // reference, not a copy
    std::cout << "via reference: " << ref.rate() << "\n";
}
