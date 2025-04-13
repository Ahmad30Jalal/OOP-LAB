#include <iostream>
#include <string>

using namespace std;

class TrafficSystem
{
private:
    int car_count;
    int wait_time;

public:
    TrafficSystem(int cars = 0, int wait = 0)
    {
        car_count = cars;
        wait_time = wait;
    }

    TrafficSystem operator+(TrafficSystem t)
    {
        return TrafficSystem(car_count + t.car_count, wait_time);
    }

    TrafficSystem operator-(TrafficSystem t)
    {
        int count = car_count - t.car_count;
        if (count < 0)
            count = 0;
        return TrafficSystem(count, wait_time);
    }

    TrafficSystem operator*(int multiplier)
    {
        return TrafficSystem(car_count, wait_time * multiplier);
    }

    bool operator==(TrafficSystem t)
    {
        return (car_count == t.car_count) && (wait_time == t.wait_time);
    }

    void display()
    {
        cout << "Cars: " << car_count << ", Wait Time: " << wait_time << " min" << endl;
    }
};

int main()
{
    TrafficSystem intersection1(50, 5);
    TrafficSystem more_cars(20, 0);
    TrafficSystem cleared(15, 0);

    TrafficSystem total_traffic = intersection1 + more_cars;
    TrafficSystem after_clearance = total_traffic - cleared;
    TrafficSystem doubled_delay = after_clearance * 2;

    TrafficSystem r1(100, 10);
    TrafficSystem r2(100, 10);
    TrafficSystem r3(90, 8);

    cout << "Initial Traffic: ";
    intersection1.display();

    cout << "After More Cars: ";
    total_traffic.display();

    cout << "After Some Leave: ";
    after_clearance.display();

    cout << "After Signal Failure: ";
    doubled_delay.display();

    cout << "Gridlock Check (A vs B): ";
    if (r1 == r2)
    {
        cout << "it's a gridlock!" << endl;
    }
    else
    {
        cout << "still breathing." << endl;
    }

    cout << "Gridlock Check (A vs C): ";
    if (r1 == r3)
    {
        cout << "it's a gridlock!" << endl;
    }
    else
    {
        cout << "still breathing." << endl;
    }

    return 0;
}
