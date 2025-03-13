#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string make, string model, int year) : make(make), model(model), year(year) {}

    void display_info()
    {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
};

class Car : public Vehicle
{
protected:
    int num_doors;
    double fuel_efficiency;

public:
    Car(string make, string model, int year, int num_doors, double fuel_efficiency) : Vehicle(make, model, year), num_doors(num_doors), fuel_efficiency(fuel_efficiency) {}

    void display_car_info()
    {
        display_info();
        cout << "Number of Doors: " << num_doors << ", Fuel Efficiency: " << fuel_efficiency << " mpg" << endl;
    }
};

class ElectricCar : public Car
{
protected:
    double battery_life;

public:
    ElectricCar(string make, string model, int year, int num_doors, double battery_life) : Car(make, model, year, num_doors, 0.0), battery_life(battery_life) {}

    void display_electric_car_info()
    {
        display_car_info();
        cout << "Battery Life: " << battery_life << " miles" << endl;
    }
};

int main()
{
    ElectricCar e1("Tesla", "Model Y", 2021, 4, 410.0);
    ElectricCar e2("BYD", "Graf", 2023, 4, 390);
    e1.display_electric_car_info();
    e2.display_electric_car_info();

    return 0;
}