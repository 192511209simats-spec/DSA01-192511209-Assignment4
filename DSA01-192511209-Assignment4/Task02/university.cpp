// Tasks 2.1 / 2.3 - University hierarchy (hybrid inheritance with a virtual base)
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name; int id; string phone;
public:
    Person(const string& n = "", int i = 0, const string& p = "") : name(n), id(i), phone(p) {}
    virtual ~Person() = default;
    virtual void show() const { cout << id << " " << name << " " << phone; }
};

class Student : virtual public Person {            // is-a Person
protected:
    string programme; double cgpa;
public:
    Student(const string& n = "", int i = 0, const string& p = "", const string& prog = "", double c = 0)
        : Person(n, i, p), programme(prog), cgpa(c) {}
    void show() const override { Person::show(); cout << " | " << programme << " CGPA " << cgpa; }
};

class Staff : virtual public Person {              // is-a Person
protected:
    string dept; double salary;
public:
    Staff(const string& n = "", int i = 0, const string& p = "", const string& d = "", double s = 0)
        : Person(n, i, p), dept(d), salary(s) {}
    void show() const override { Person::show(); cout << " | " << dept << " Rs." << salary; }
};

class TeachingAssistant : public Student, public Staff {   // is-a Student AND is-a Staff
public:
    TeachingAssistant(const string& n, int i, const string& p, const string& prog, double c,
                      const string& d, double s)
        : Person(n, i, p), Student(n, i, p, prog, c), Staff(n, i, p, d, s) {}  // most-derived builds Person
    void show() const override {
        Person::show();
        cout << " | " << programme << " CGPA " << cgpa << " | " << dept << " Rs." << salary;
    }
};

class ResearchScholar : public Student {           // multilevel: Person -> Student -> ResearchScholar
    double fellowship;
public:
    ResearchScholar(const string& n, int i, const string& p, const string& prog, double c, double f)
        : Person(n, i, p), Student(n, i, p, prog, c), fellowship(f) {}
    void show() const override { Student::show(); cout << " | Fellowship Rs." << fellowship; }
};

int main() {
    Student s("Kavya", 1, "9000000001", "B.E. CSE", 8.7);
    Staff f("Dr. Rao", 2, "9000000002", "CSE", 90000);
    TeachingAssistant ta("Arun", 3, "9000000003", "M.E. CSE", 9.1, "CSE", 25000);
    ResearchScholar rs("Divya", 4, "9000000004", "Ph.D. CSE", 9.4, 31000);
    Person* all[] = { &s, &f, &ta, &rs };
    for (Person* p : all) { p->show(); cout << "\n"; }
}
