#include <iostream>
#include <string>
using namespace std;

class Activity
{
public:
    virtual double calculateCaloriesBurned() = 0;
};

class Running : public Activity
{
private:
    double distance;
    double time;

public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() override
    {
        return distance * (time);
    }
};

class Cycling : public Activity
{
private:
    double speed;
    double time;

public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() override
    {
        return speed * (time);
    }
};

int main()
{

    Running r1(5.0, 30.0);
    Cycling c1(20.0, 10);

    cout << "Calories burned running: " << r1.calculateCaloriesBurned() << " kcal" << endl;
    cout << "Calories burned cycling: " << c1.calculateCaloriesBurned() << " kcal" << endl;

    return 0;
}