// Task 6 - Alternative: ONE Vehicle class with a type code and a switch in charge()
#include <iomanip>
#include <iostream>
#include <string>
enum class VType { Bicycle, TwoWheeler, Car, ElectricCar };

class Vehicle {
public:
    VType type; std::string regNo; double dailyRate;
    double level, batteryKWh; int seats; int serviceDueDay;   // unused by Bicycle (and some by others)
    Vehicle(VType t, std::string r, double rate, double lvl = 0, int s = 0, double kwh = 0)
        : type(t), regNo(r), dailyRate(rate), level(lvl), batteryKWh(kwh), seats(s), serviceDueDay(0) {}
    double charge(int days, double used) const {
        switch (type) {                                       // EVERY new vehicle type edits this switch
            case VType::Bicycle:     return days * dailyRate;
            case VType::TwoWheeler:
            case VType::Car:         return days * dailyRate + used * 105.0;
            case VType::ElectricCar: return days * dailyRate + used * 12.0;
        }
        return 0;
    }
};
int main() {
    std::cout << std::fixed << std::setprecision(2);
    Vehicle b(VType::Bicycle, "BI-001", 150), e(VType::ElectricCar, "TN-09-EV-3", 2200, 90, 5, 40);
    std::cout << "Bicycle     : " << b.charge(2, 0) << "\n";
    std::cout << "ElectricCar : " << e.charge(2, 18) << "\n";
    std::cout << "sizeof(Vehicle) = " << sizeof(Vehicle) << " bytes for EVERY object, even a bicycle (unused fields)\n";
    std::cout << "Adding ElectricBus -> edit enum + switch + constructor in the existing class.\n";
}
