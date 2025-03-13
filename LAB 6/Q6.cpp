#include <iostream>
#include <string>
using namespace std;

class Device
{
protected:
    string brand;
    string model;

public:
    Device(string brand, string model)
        : brand(brand), model(model) {}

    void display_info()
    {
        cout << "Brand: " << brand << ", Model: " << model << endl;
    }
};

class Smartphone : virtual public Device
{
protected:
    int sim_slot_count;

public:
    Smartphone(string brand, string model, int sim_slot_count) : Device(brand, model), sim_slot_count(sim_slot_count) {}

    void display_smartphone_info()
    {
        display_info();
        cout << "SIM Slot Count: " << sim_slot_count << endl;
    }
};

class Tablet : virtual public Device
{
protected:
    bool has_stylus_support;

public:
    Tablet(string brand, string model, bool has_stylus_support)
        : Device(brand, model), has_stylus_support(has_stylus_support) {}

    void display_tablet_info()
    {
        display_info();
        cout << "Stylus Support: " << (has_stylus_support ? "Yes" : "No") << endl;
    }
};

class HybridDevice : public Smartphone, public Tablet
{
public:
    HybridDevice(string brand, string model, int sim_slot_count, bool has_stylus_support) : Device(brand, model), Smartphone(brand, model, sim_slot_count), Tablet(brand, model, has_stylus_support) {}

    void display_hybrid_info()
    {
        display_smartphone_info();
        display_tablet_info();
    }
};

int main()
{
    HybridDevice h1("Techno", "V20", 2, true);
    HybridDevice h2("Oppo", "A18", 2, true);
    h1.display_hybrid_info();

    return 0;
}