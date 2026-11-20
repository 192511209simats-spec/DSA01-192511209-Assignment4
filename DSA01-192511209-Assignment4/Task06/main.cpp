// Task 6 Stage 5 - Demonstration: rent every type, return with a late charge, add a new type
#include "Fleet.h"
#include "ElectricBus.h"      // <- the ONLY change needed to support the new type

int main() {
    std::cout << std::fixed << std::setprecision(2);
    Fleet fleet;
    fleet.add(new Bicycle("BI-001", 150));
    fleet.add(new TwoWheeler("TN-22-AB-1", 400, 5.0, Date(15, 12, 2026)));
    fleet.add(new Car("TN-01-CD-2", 1500, 30.0, Date(1, 1, 2027), 5));
    fleet.add(new ElectricCar("TN-09-EV-3", 2200, 90.0, Date(20, 2, 2027), 5, 40.0));

    std::cout << "===== INITIAL FLEET =====\n";
    fleet.list();

    std::cout << "\n===== RENT EACH TYPE =====\n";
    fleet.rent("BI-001", 2);
    fleet.rent("TN-22-AB-1", 3);
    fleet.rent("TN-01-CD-2", 2);
    fleet.rent("TN-09-EV-3", 2);
    fleet.rent("BI-001", 1);                 // already rented -> rejected

    std::cout << "\n===== RETURN ON TIME =====\n";
    fleet.giveBack("BI-001", 2, 0);          // bicycle: no energy
    fleet.giveBack("TN-22-AB-1", 3, 2.5);    // 2.5 litres
    fleet.giveBack("TN-09-EV-3", 2, 18.0);   // 18 kWh

    std::cout << "\n===== RETURN LATE (planned 2, kept 5 -> 3 late days) =====\n";
    fleet.giveBack("TN-01-CD-2", 5, 12.0);   // 12 litres + late fee

    std::cout << "\n===== ADD A NEW TYPE: ElectricBus (no existing class changed) =====\n";
    fleet.add(new ElectricBus("TN-77-EB-9", 6000, 100.0, Date(5, 3, 2027), 40, 200.0));
    fleet.rent("TN-77-EB-9", 1);
    fleet.giveBack("TN-77-EB-9", 3, 60.0);   // 2 late days, bus late rule = 2x rate/day

    std::cout << "\n===== FINAL FLEET =====\n";
    fleet.list();
}
