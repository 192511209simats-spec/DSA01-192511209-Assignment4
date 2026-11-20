// Task 2.4 - Access table. Uncomment ONE commented line at a time to see the compiler error.
#include <iostream>
class Person {
public:    int pub = 1;
protected: int prot = 2;
private:   int priv = 3;
};
class StudentPublic    : public Person    { public: void t() { std::cout << pub << prot; /* priv -> ERROR */ } };
class StudentProtected : protected Person { public: void t() { std::cout << pub << prot; /* priv -> ERROR */ } };
class StudentPrivate   : private Person   { public: void t() { std::cout << pub << prot; /* priv -> ERROR */ } };
int main() {
    StudentPublic a; StudentProtected b; StudentPrivate c;
    a.t(); b.t(); c.t(); std::cout << "\n";
    std::cout << a.pub << "\n";            // OK   : public stays public
    // std::cout << b.pub;                 // ERROR: public became protected
    // std::cout << c.pub;                 // ERROR: public became private
    // std::cout << a.prot;                // ERROR: protected not accessible from outside
}
