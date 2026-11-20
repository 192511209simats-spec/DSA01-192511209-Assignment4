// Task 1.2 - Repaired design: common base class + overridden pay()
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr double DA_RATE = 0.42;          // no more magic number

class Staff {                              // abstract base: common data written once
    string name_;
    int id_;
public:
    Staff(const string& n, int i) : name_(n), id_(i) {}
    virtual ~Staff() = default;
    virtual double pay() const = 0;        // each category supplies its own rule
    const string& name() const { return name_; }
    int id() const { return id_; }
};

class SalariedStaff : public Staff {       // shared by Professor and LabAssistant
protected:
    double basic_;
public:
    SalariedStaff(const string& n, int i, double b) : Staff(n, i), basic_(b) {}
    double basicPlusDA() const { return basic_ + basic_ * DA_RATE; }
};

class Professor : public SalariedStaff {
    double research_;
public:
    Professor(const string& n, int i, double b, double r) : SalariedStaff(n, i, b), research_(r) {}
    double pay() const override { return basicPlusDA() + research_; }
};

class LabAssistant : public SalariedStaff {
public:
    LabAssistant(const string& n, int i, double b) : SalariedStaff(n, i, b) {}
    double pay() const override { return basicPlusDA(); }
};

class GuestFaculty : public Staff {
    double hours_, rate_;
public:
    GuestFaculty(const string& n, int i, double h, double r) : Staff(n, i), hours_(h), rate_(r) {}
    double pay() const override { return hours_ * rate_; }
};

// ---- Task 1.3 demo: a NEW category added WITHOUT touching any class above ----
class Administrator : public SalariedStaff {
    double allowance_;
public:
    Administrator(const string& n, int i, double b, double a) : SalariedStaff(n, i, b), allowance_(a) {}
    double pay() const override { return basicPlusDA() + allowance_; }
};

int main() {
    vector<Staff*> all;                    // ONE loop for ALL staff
    all.push_back(new Professor("Dr. Meena", 101, 80000, 15000));
    all.push_back(new LabAssistant("Ravi", 102, 30000));
    all.push_back(new GuestFaculty("Anita", 103, 20, 1500));
    all.push_back(new Administrator("Suresh", 104, 50000, 8000));

    double total = 0;
    for (const Staff* s : all) {
        cout << s->id() << " " << s->name() << " -> " << s->pay() << "\n";
        total += s->pay();
    }
    cout << "Total payroll = " << total << "\n";
    for (Staff* s : all) delete s;         // virtual destructor makes this safe
}
