// Tasks 3.1 - 3.4: constructors in derived classes, member classes, construction/destruction order.
// Default build: virtual bases.   Experiment (3.4): compile with -DNOVIRTUAL to remove "virtual".
#include <iostream>
#include <string>
using namespace std;

#ifdef NOVIRTUAL
  #define VIRT
#else
  #define VIRT virtual
#endif

class Address {                                   // member class of Person (has-a)
    string city; int pin;
public:
    Address(const string& c, int p) : city(c), pin(p) { cout << "Address "; }
    ~Address() { cout << "~Address "; }
    string str() const { return city + "-" + to_string(pin); }
};

class Course {                                    // member class of Student (has-a)
    string title;
public:
    Course(const string& t) : title(t) { cout << "Course "; }
    ~Course() { cout << "~Course "; }
    const string& get() const { return title; }
};

class Person {
protected:
    string name; int id; Address addr;
public:
    Person(const string& n, int i, const string& city, int pin) : name(n), id(i), addr(city, pin) { cout << "Person "; }
    ~Person() { cout << "~Person "; }
};

class Student : public VIRT Person {
protected:
    double cgpa; Course course;
public:
    Student(const string& n, int i, const string& city, int pin, double c, const string& crs)
        : Person(n, i, city, pin), cgpa(c), course(crs) { cout << "Student "; }
    ~Student() { cout << "~Student "; }
};

class Staff : public VIRT Person {
protected:
    double salary;
public:
    Staff(const string& n, int i, const string& city, int pin, double s)
        : Person(n, i, city, pin), salary(s) { cout << "Staff "; }
    ~Staff() { cout << "~Staff "; }
};

class TeachingAssistant : public Student, public Staff {
public:
    // Most-derived class calls the virtual base constructor DIRECTLY.
    TeachingAssistant(const string& n, int i, const string& city, int pin, double c, const string& crs, double s)
#ifdef NOVIRTUAL
        : Student(n, i, city, pin, c, crs), Staff(n, i, city, pin, s)           // Person is no longer a direct-callable base
#else
        : Person(n, i, city, pin), Student(n, i, city, pin, c, crs), Staff(n, i, city, pin, s)
#endif
    { cout << "TA "; }
    ~TeachingAssistant() { cout << "~TA "; }
};

int main() {
    cout << "--- Student ---\n";
    { Student s("Kavya", 1, "Salem", 636001, 8.7, "C++"); cout << "| "; }
    cout << "\n--- Staff ---\n";
    { Staff f("Dr. Rao", 2, "Chennai", 600001, 90000); cout << "| "; }
    cout << "\n--- TeachingAssistant ---\n";
    { TeachingAssistant t("Arun", 3, "Erode", 638001, 9.1, "DSA", 25000); cout << "| "; }
    cout << "\n";
    cout << "sizeof(TeachingAssistant) = " << sizeof(TeachingAssistant) << "\n";
}
