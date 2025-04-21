#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string model;
    double rate;

public:
    Vehicle(string m, double r) : model(m), rate(r) {}

    virtual double get_daily_rate() = 0;
    virtual void display_details() = 0;
};

class Car : public Vehicle
{
protected:
    int seating_capacity;

public:
    Car(string m, double r, int sc) : Vehicle(m, r), seating_capacity(sc) {}

    double get_daily_rate() override
    {
        return rate;
    }

    void display_details() override
    {
        cout << "Car Model: " << model << endl;
        cout << "Rate: " << rate << endl;
        cout << "Seating Capacity: " << seating_capacity << endl
             << endl;
    }
};

class Bike : public Vehicle
{
protected:
    int engine_cc;

public:
    Bike(string m, double r, int cc) : Vehicle(m, r), engine_cc(cc) {}

    double get_daily_rate() override
    {
        return rate;
    }

    void display_details() override
    {
        cout << "Bike Model: " << model << endl;
        cout << "Rate: " << rate << endl;
        cout << "Engine CC: " << engine_cc << endl
             << endl;
    }
};

int main()
{
    Car c1("Civic", 2300, 4);
    Car c2("Hijet", 1500, 7);
    Bike b1("Honda", 500, 125);
    Bike b2("Suzuki", 700, 150);

    c1.display_details();
    c2.display_details();

    b1.display_details();
    b2.display_details();

    return 0;
}
