#include <iostream>
using namespace std;

class Bottle
{
private:
    string Company;
    string Color;
    float Water_ml;
    float Water_l;

public:
    void set_info(string cp, string cl, float ml, float l)
    {
        Company = cp;
        Color = cl;
        Water_ml = ml;
        Water_l = l;
    }
    void get_info()
    {
        cout << "Company: " << Company << endl;
        cout << "Color: " << Color << endl;
        cout << "Water in ML: " << Water_ml << endl;
        cout << "Water in L: " << Water_l << endl;
    }
    void drink(float Water)
    {
        if (Water > Water_ml)
        {
            cout << "Not enough water" << endl;
            return;
        }
        Water_ml -= Water;
        Water_l -= Water / 1000;
        cout << "Water in litres:" << Water_l << endl;
        cout << "Water in ML: " << Water_ml << endl;
    }
};

int main()
{

    float W;
    Bottle b1;
    b1.set_info("Fizz", "Red", 1200, 1.2);
    b1.get_info();
    cout << "Enter water in ml: ";
    cin >> W;
    b1.drink(W);
    b1.get_info();
    return 0;
}