#include <iostream>
#include <string>
using namespace std;

class Airport
{
    string name;
    string city;

public:
    Airport(string n, string c) : name(n), city(c) {}

    string get_city() const
    {
        return city;
    }

    string get_name() const
    {
        return name;
    }

    void display() const
    {
        cout << "Airport: " << name << endl;
        cout << "City: " << city << endl;
    }
};

class Flight
{
    string flight_number;
    string plane_type;
    string status;
    Airport *air[10];
    int count;

public:
    Flight(string fn, string pt) : flight_number(fn), plane_type(pt), count(0) {}

    void add_airport(Airport *airport)
    {
        if (count < 10)
        {
            air[count] = airport;
            count++;
        }
        else
        {
            cout << "Cannot add more airports." << endl;
        }
    }

    void set_status(string new_status)
    {
        status = new_status;
    }

    void display()
    {
        cout << "Flight: " << flight_number << endl;
        cout << "Plane type: " << plane_type << endl;
        cout << "Status: " << status << endl;

        if (count == 0)
        {
            cout << "No airports available" << endl;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                cout << air[i]->get_name();
                if (i < count - 1)
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Airport a1("Allama Iqbal international airport", "Lahore");
    Airport a2("Jinnah international airport", "Karachi");
    Airport a3("Gwadar international airport", "Gwadar");

    Flight f1("PK-7860", "Boeing");
    f1.add_airport(&a1);
    f1.add_airport(&a2);
    f1.add_airport(&a3);

    f1.set_status("Taking off");
    f1.display();

    f1.set_status("Diverting to Gwadar");
    f1.display();

    return 0;
}