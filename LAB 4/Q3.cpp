#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
    string device_name;
    string device_type;
    string status;

public:
    SmartDevice(string name, string type, string s)
    {
        device_name = name;
        device_type = type;
        status = s;

        cout << device_name << " (" << device_type << ")" << " has been created and is " << status << endl;
    }

    ~SmartDevice()
    {
        cout << device_name << " (" << device_type << ")" << " is powering off" << endl;
    }

    void display()
    {
        cout << "Device: " << device_name << endl;
        cout << "Device type: " << device_type << endl;
        cout << "Status: " << status << endl;
    }
};

int main()
{
    SmartDevice s1("Panasonic Juicer", "Juicer", "off");
    SmartDevice s2("Iphone 14", "Mobile", "On");
    SmartDevice s3("Door Light", "Smart Light", "On");

    s1.display();
    s2.display();
    s3.display();

    return 0;
}