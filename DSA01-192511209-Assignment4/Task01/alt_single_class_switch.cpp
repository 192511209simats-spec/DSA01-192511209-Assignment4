// Task 1 - Alternative concept: ONE Staff class + type field + switch in pay()
#include <iostream>
#include <string>
using namespace std;

enum class Type { Professor, LabAssistant, Guest };

class Staff {
public:
    Type type; string name; int id;
    double basic, research, hours, rate;      // many fields unused by each type
    Staff(Type t, string n, int i, double b, double r, double h, double rt)
        : type(t), name(n), id(i), basic(b), research(r), hours(h), rate(rt) {}
    double pay() const {
        switch (type) {                        // EVERY new type edits this switch
            case Type::Professor:    return basic + basic * 0.42 + research;
            case Type::LabAssistant: return basic + basic * 0.42;
            case Type::Guest:        return hours * rate;
        }
        return 0;
    }
};

int main() {
    Staff a(Type::Professor, "Dr. Meena", 101, 80000, 15000, 0, 0);
    Staff b(Type::LabAssistant, "Ravi", 102, 30000, 0, 0, 0);
    Staff c(Type::Guest, "Anita", 103, 0, 0, 20, 1500);
    cout << a.pay() << "\n" << b.pay() << "\n" << c.pay() << "\n";
    cout << "sizeof(Staff) = " << sizeof(Staff) << " bytes (same for every type)\n";
    cout << "A new type means editing: the enum, the switch in pay(), and possibly the fields -> existing class modified\n";
}
