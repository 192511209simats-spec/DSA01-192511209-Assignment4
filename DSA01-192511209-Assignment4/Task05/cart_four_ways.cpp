// Tasks 5.1 / 5.2 - four ways to reach an object, this-pointer chaining, array of pointers search
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Cart {
    string owner;
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;                              // percent
public:
    Cart(const string& owner = "guest") { this->owner = owner; }   // this-> separates member from parameter
    Cart& add(const string& item, double price) {
        if (n < 10) { items[n] = item; prices[n] = price; ++n; }
        return *this;                                  // *this is the object the call was made on
    }
    Cart& setDiscount(double discount) { this->discount = discount; return *this; }
    double total() const {
        double t = 0;
        for (int i = 0; i < n; ++i) t += prices[i];
        return t * (100 - discount) / 100;
    }
    const string& getOwner() const { return owner; }
};

void useByReference(Cart& c) { c.add("Milk", 30); }   // (c) through a reference

int main() {
    cout << fixed << setprecision(2);

    Cart a("Asha");                                    // (a) directly by name
    a.add("Rice", 60).add("Dal", 120).setDiscount(10); // chaining
    cout << "(a) direct   : " << a.total() << "\n";

    Cart* p = &a;                                      // (b) pointer with ->
    p->add("Oil", 180);
    cout << "(b) pointer  : " << p->total() << "\n";

    useByReference(a);                                 // (c) reference
    cout << "(c) reference: " << a.total() << "\n";

    Cart* h = new Cart("Heap");                        // (d) new / delete
    h->add("Sugar", 45).add("Tea", 90).setDiscount(5);
    cout << "(d) new      : " << h->total() << "\n";
    delete h;
    h = nullptr;

    // Task 5.2: array of pointers, find highest total
    Cart* carts[4];
    carts[0] = new Cart("C0"); carts[0]->add("A", 100);
    carts[1] = new Cart("C1"); carts[1]->add("B", 500).add("C", 50);
    carts[2] = new Cart("C2"); carts[2]->add("D", 300).setDiscount(50);
    carts[3] = new Cart("C3"); carts[3]->add("E", 20);

    Cart** best = carts;                               // pointer arithmetic over the array
    for (Cart** q = carts + 1; q < carts + 4; ++q)
        if ((*q)->total() > (*best)->total()) best = q;
    cout << "Highest total: " << (*best)->getOwner() << " = " << (*best)->total()
         << " (index " << (best - carts) << ")\n";
    for (Cart* c : carts) delete c;
}
