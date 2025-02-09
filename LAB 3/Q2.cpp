#include <iostream>
using namespace std;

class Circle
{

private:
    double radius;
    double pi = 3.14159;

public:
    void set_radius(double r)
    {
        radius = r;
    }

    void get_radius()
    {
        cout << "Radius = " << radius << endl;
    }

    void get_area()
    {
        double area = pi * radius * radius;
        cout << "Area = " << area << endl;
    }

    void get_diameter()
    {
        double dm = radius * 2;
        cout << "Diameter = " << dm << endl;
    }

    void get_circumference()
    {
        double cm = 2 * pi * radius;
        cout << "Circumference = " << cm << endl;
    }
};

int main()
{
    Circle c;
    double rd;
    cout << "Enter radius of circle (in cm): ";
    cin >> rd;

    c.set_radius(rd);
    c.get_radius();
    c.get_area();
    c.get_diameter();
    c.get_circumference();

    return 0;
}
