// Task 3 - Alternative: Student holds Address* (heap) instead of an Address member object.
// Now we must write constructor, copy constructor, copy assignment and destructor ("rule of three").
#include <iostream>
#include <string>
class Person {
protected:
    std::string name; int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {}
};
class Address {
    std::string city; int pin;
public:
    Address(const std::string& c, int p) : city(c), pin(p) {}
    std::string str() const { return city + "-" + std::to_string(pin); }
};
class Student : public Person {
    long long regNo;
    Address* home;                                              // pointer member
public:
    Student(const std::string& n, int a, long long r, const std::string& c, int p)
        : Person(n, a), regNo(r), home(new Address(c, p)) {}     // extra heap allocation
    Student(const Student& o) : Person(o), regNo(o.regNo), home(new Address(*o.home)) {}  // deep copy
    Student& operator=(const Student& o) {
        if (this != &o) { Person::operator=(o); regNo = o.regNo; Address* t = new Address(*o.home); delete home; home = t; }
        return *this;
    }
    ~Student() { delete home; }                                  // must release it
    void print() const { std::cout << regNo << ' ' << name << " (" << age << ") " << home->str() << '\n'; }
};
int main() {
    Student s("Kavya", 19, 192311001, "Salem", 636001);
    Student t = s;                                               // safe because of the deep copy
    s.print(); t.print();
    std::cout << "sizeof(Student) with pointer member = " << sizeof(Student) << "\n";
}
