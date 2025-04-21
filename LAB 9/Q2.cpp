#include <iostream>
#include <string>

using namespace std;

class SmartDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() const = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice
{
private:
    bool is_on;
    int brightness;

public:
    LightBulb() : is_on(false), brightness(100) {}

    void turnOn() override
    {
        is_on = true;
        cout << "LightBulb is turned ON." << endl;
    }

    void turnOff() override
    {
        is_on = false;
        cout << "LightBulb is turned OFF." << endl;
    }

    string getStatus() const override
    {
        string status = "LightBulb ";
        if (is_on)
        {
            status += "ON, ";
        }
        else
        {
            status += "OFF, ";
        }
        status += to_string(brightness) + "%";
        return status;
    }

    void set_brightness(int level)
    {
        if (level >= 0 && level <= 100)
        {
            brightness = level;
            cout << "LightBulb brightness set to " << brightness << "%" << endl;
        }
        else
        {
            cout << "Invalid brightness level." << endl;
        }
    }
};

class Thermostat : public SmartDevice
{
private:
    bool is_on;
    double temperature;

public:
    Thermostat() : is_on(false), temperature(22.0) {}

    void turnOn() override
    {
        is_on = true;
        cout << "Thermostat is turned ON." << endl;
    }

    void turnOff() override
    {
        is_on = false;
        cout << "Thermostat is turned OFF." << endl;
    }

    string getStatus() const override
    {
        string status = "Thermostat ";
        status += (is_on ? "ON, " : "OFF, ");
        status += to_string(temperature) + "C";
        return status;
    }

    void set_temperature(double temp)
    {
        temperature = temp;
        cout << "Thermostat temperature set to " << temperature << "C" << endl;
    }
};

int main()
{
    LightBulb l1;
    Thermostat t1;

    l1.turnOn();
    l1.set_brightness(75);
    l1.getStatus();

    t1.turnOn();
    t1.set_temperature(24.5);
    t1.getStatus();

    l1.turnOff();
    l1.getStatus();

    t1.turnOff();
    t1.getStatus();

    return 0;
}
