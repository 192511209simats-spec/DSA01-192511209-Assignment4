// Task 5 - What if add() returned Cart instead of Cart&?  Each call returns a COPY.
#include <iostream>
#include <string>
class Cart {
    double prices[10]; int n = 0;
public:
    Cart add(double price) { prices[n++] = price; return *this; }   // returns a copy
    int count() const { return n; }
};
int main() {
    Cart c;
    c.add(60).add(120).add(180);        // 1st add changes c; 2nd and 3rd change TEMPORARY copies
    std::cout << "items in c = " << c.count() << "  (expected 3 with Cart&, but it is 1)\n";
}
