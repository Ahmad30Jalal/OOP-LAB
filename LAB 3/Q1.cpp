#include <iostream>
using namespace std;

class BoardMarker
{
private:
    string Company;
    string Color;
    bool Refillable;
    bool Ink_status;

public:
    void setInfo(string cp, string cl, bool r, bool i)
    {
        Company = cp;
        Color = cl;
        Refillable = r;
        Ink_status = i;
    }
    void getInfo()
    {
        cout << "Company: " << Company << endl;
        cout << "Color: " << Color << endl;
        cout << "Refillable: " << Refillable << endl;
        cout << "Ink_Status: " << Ink_status << endl;
    }

    void write()
    {
        if (Ink_status == 1)
        {
            cout << "You can start" << endl;
        }
        else
        {
            cout << "Not Enough ink" << endl;
        }
    }

    void refill()
    {
        if (Refillable == 1)
        {
            cout << "Ink can be refilled" << endl;
        }
        else
        {
            cout << "Ink cannot be refilled" << endl;
        }
    }
};

int main()
{
    BoardMarker b1, b2, b3;

    b1.setInfo("Fineliner", "Red", 0, 1);
    b2.setInfo("Dollar", "Black", 1, 0);
    b3.setInfo("HB", "Green", 0, 1);

    b1.getInfo();
    b1.write();
    b1.refill();
    b2.getInfo();
    b2.write();
    b2.refill();
    b3.getInfo();
    b3.write();
    b3.refill();

    return 0;
}