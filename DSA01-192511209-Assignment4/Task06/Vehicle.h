// Task 6 - Vehicle Rental Fleet : EXISTING classes (never edited when new types are added)
#ifndef VEHICLE_H
#define VEHICLE_H
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

class Date {                                           // member class (has-a) : service due date
    int d, m, y;
public:
    Date(int dd = 1, int mm = 1, int yy = 2026) : d(dd), m(mm), y(yy) {}
    std::string str() const {
        return (d < 10 ? "0" : "") + std::to_string(d) + "-" + (m < 10 ? "0" : "") + std::to_string(m) + "-" + std::to_string(y);
    }
};

class Vehicle {                                        // ABSTRACT base class
protected:
    std::string regNo;
    double dailyRate;
    bool rented = false;
    int plannedDays = 0;
public:
    Vehicle(const std::string& r, double rate) : regNo(r), dailyRate(rate) {}
    virtual ~Vehicle() = default;

    virtual std::string type() const = 0;                              // pure virtual
    virtual double rentalCharge(int actualDays, double used) const = 0;// pure virtual: differs per type
    virtual double lateCharge(int lateDays) const { return lateDays * dailyRate * 1.5; }  // default, overridable

    const std::string& reg() const { return regNo; }
    bool isRented() const { return rented; }

    bool rent(int days) {                              // RENT
        if (rented || days <= 0) return false;
        rented = true; plannedDays = days;
        return true;
    }
    double giveBack(int actualDays, double used) {     // RETURN (template method: same steps for all types)
        if (!rented) return -1;
        int late = std::max(0, actualDays - plannedDays);
        double bill = rentalCharge(actualDays, used) + lateCharge(late);
        rented = false; plannedDays = 0;
        return bill;
    }
    virtual void print() const {
        std::cout << std::left << std::setw(13) << regNo << std::setw(14) << type()
                  << "Rs." << std::setw(7) << dailyRate << "/day  " << (rented ? "RENTED" : "available");
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& r, double rate) : Vehicle(r, rate) {}
    std::string type() const override { return "Bicycle"; }
    double rentalCharge(int days, double) const override { return days * dailyRate; }
};

class MotorVehicle : public Vehicle {                  // abstract: fuel/charge level + service date
protected:
    double level;                                      // litres or % charge
    Date serviceDue;                                   // member class
public:
    MotorVehicle(const std::string& r, double rate, double lvl, const Date& due)
        : Vehicle(r, rate), level(lvl), serviceDue(due) {}
    virtual double energyPrice() const { return 105.0; }                 // Rs per litre
    double rentalCharge(int days, double used) const override { return days * dailyRate + used * energyPrice(); }
    void print() const override { Vehicle::print(); std::cout << "  level " << level << "  service due " << serviceDue.str(); }
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(const std::string& r, double rate, double lvl, const Date& due) : MotorVehicle(r, rate, lvl, due) {}
    std::string type() const override { return "TwoWheeler"; }
};

class Car : public MotorVehicle {
protected:
    int seats;
public:
    Car(const std::string& r, double rate, double lvl, const Date& due, int s) : MotorVehicle(r, rate, lvl, due), seats(s) {}
    std::string type() const override { return "Car"; }
    void print() const override { MotorVehicle::print(); std::cout << "  seats " << seats; }
};

class ElectricCar : public Car {                       // charged per kWh instead of per litre
    double batteryKWh;
public:
    ElectricCar(const std::string& r, double rate, double lvl, const Date& due, int s, double kwh)
        : Car(r, rate, lvl, due, s), batteryKWh(kwh) {}
    std::string type() const override { return "ElectricCar"; }
    double energyPrice() const override { return 12.0; }                 // Rs per kWh
    void print() const override { Car::print(); std::cout << "  battery " << batteryKWh << " kWh"; }
};
#endif
