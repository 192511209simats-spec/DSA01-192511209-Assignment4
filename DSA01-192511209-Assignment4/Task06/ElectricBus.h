// Task 6 Stage 5 - NEW vehicle type, added in a NEW file. Vehicle.h and Fleet.h are NOT modified.
#ifndef ELECTRICBUS_H
#define ELECTRICBUS_H
#include "Vehicle.h"

class ElectricBus : public MotorVehicle {
    int seats; double batteryKWh;
public:
    ElectricBus(const std::string& r, double rate, double lvl, const Date& due, int s, double kwh)
        : MotorVehicle(r, rate, lvl, due), seats(s), batteryKWh(kwh) {}
    std::string type() const override { return "ElectricBus"; }
    double energyPrice() const override { return 15.0; }                           // Rs per kWh
    double lateCharge(int lateDays) const override { return lateDays * dailyRate * 2.0; }  // its own late rule
    void print() const override { MotorVehicle::print(); std::cout << "  seats " << seats << "  battery " << batteryKWh << " kWh"; }
};
#endif
