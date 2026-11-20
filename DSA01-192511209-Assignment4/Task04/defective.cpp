// Task 4.1 / 4.2 - The DEFECTIVE program with evidence printouts.
// Build with sanitizer:  g++ -std=c++17 -Wall -Wextra -fsanitize=address -g defective.cpp -o defective
// ASan stops at the first error (new-delete-type-mismatch). To see the LEAK report as well, run:
//   ASAN_OPTIONS=new_delete_type_mismatch=0 ./defective
#include <iostream>
#include <vector>
class Account {
public:
    double rate() const { return 3.5; }
    ~Account() { std::cout << "~Account\n"; }
};
class SeniorAccount : public Account {
    double* history = new double[100];
public:
    double rate() const { return 4.0; }
    ~SeniorAccount() { delete[] history; std::cout << "~SeniorAccount (history released)\n"; }
};
int main() {
    Account* accounts[2] = { new Account, new SeniorAccount };
    std::cout << "--- defect 1: rate() is not virtual ---\n";
    for (Account* a : accounts) std::cout << a->rate() << "\n";       // prints 3.5 and 3.5
    std::cout << "--- defect 2: destructor not virtual ---\n";
    for (Account* a : accounts) delete a;                              // ~SeniorAccount never runs -> leak
    std::cout << "--- defect 3: slicing ---\n";
    Account copy = SeniorAccount();                                    // SeniorAccount part sliced off
    std::cout << "copy.rate() = " << copy.rate() << "\n";
    std::cout << "sizeof(Account)=" << sizeof(Account) << " sizeof(SeniorAccount)=" << sizeof(SeniorAccount) << "\n";
}
