#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string mk, string md, int yr) : make(mk), model(md), year(yr) {}

    void displayVehicle() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
protected:
    int doors;
    float fuelEfficiency;

public:
    Car(string mk, string md, int yr, int d, float fe)
        : Vehicle(mk, md, yr), doors(d), fuelEfficiency(fe) {}

    void displayCar() {
        displayVehicle();
        cout << "Number of Doors: " << doors << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string mk, string md, int yr, int d, float fe, int bl)
        : Car(mk, md, yr, d, fe), batteryLife(bl) {}

    void display() {
        displayCar();
        cout << "Battery Life: " << batteryLife << endl;
    }
};

int main() {
    ElectricCar e("Tesla", "Model 3", 2024, 4, 0.0, 450);
    e.display();
    return 0;
}
