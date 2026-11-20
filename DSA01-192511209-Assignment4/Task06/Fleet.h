// Task 6 - Fleet stored as an ARRAY OF BASE-CLASS POINTERS (works for any current or future type)
#ifndef FLEET_H
#define FLEET_H
#include "Vehicle.h"

class Fleet {
    static const int MAX = 20;
    Vehicle* v[MAX] = {};
    int n = 0;
public:
    Fleet() = default;
    Fleet(const Fleet&) = delete;                      // owns raw pointers -> no copying
    Fleet& operator=(const Fleet&) = delete;
    ~Fleet() { for (int i = 0; i < n; ++i) delete v[i]; }

    bool add(Vehicle* p) { if (n >= MAX) return false; v[n++] = p; return true; }
    Vehicle* find(const std::string& reg) const {
        for (int i = 0; i < n; ++i) if (v[i]->reg() == reg) return v[i];
        return nullptr;
    }
    void list() const { for (int i = 0; i < n; ++i) { v[i]->print(); std::cout << "\n"; } }
    void rent(const std::string& reg, int days) {
        Vehicle* p = find(reg);
        if (!p) std::cout << "RENT   " << reg << ": not found\n";
        else if (!p->rent(days)) std::cout << "RENT   " << reg << ": not available\n";
        else std::cout << "RENT   " << reg << " (" << p->type() << ") for " << days << " day(s)\n";
    }
    void giveBack(const std::string& reg, int actualDays, double used) {
        Vehicle* p = find(reg);
        if (!p) { std::cout << "RETURN " << reg << ": not found\n"; return; }
        double bill = p->giveBack(actualDays, used);
        if (bill < 0) std::cout << "RETURN " << reg << ": was not rented\n";
        else std::cout << "RETURN " << reg << " after " << actualDays << " day(s), used " << used << " -> bill Rs." << bill << "\n";
    }
};
#endif
