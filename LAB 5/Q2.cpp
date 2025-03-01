#include <iostream>
#include <string>
using namespace std;

class Battery
{
    int capacity;

public:
    Battery(int cap) : capacity(cap) {}

    int get_capacity()
    {
        return capacity;
    }
};

class SmartPhone
{
    string company;
    string model;
    string color;
    Battery bat;

public:
    SmartPhone(string com, string mod, string col, int cap) : company(com), model(mod), color(col), bat(cap) {}

    void display()
    {
        cout << "Company: " << company << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Battery capacity: " << bat.get_capacity() << endl;
        cout << endl;
    }
};

int main()
{
    SmartPhone phone1("Apple", "Iphone 11", "Black", 4000);
    SmartPhone phone2("Samsung", "S24", "White", 5000);

    phone1.display();
    phone2.display();

    return 0;
}