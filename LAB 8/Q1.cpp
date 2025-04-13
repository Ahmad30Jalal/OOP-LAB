#include <iostream>
#include <string>

using namespace std;

class Time;

class Speed
{
private:
    float speed;

public:
    Speed(float s)
    {
        speed = s;
    }

    friend float calculate_distance(Speed s, Time t);
};

class Time
{
private:
    float time;

public:
    Time(float t)
    {
        time = t;
    }

    friend float calculate_distance(Speed s, Time t);
};

float calculate_distance(Speed s, Time t)
{
    return s.speed * t.time;
}

int main()
{
    Speed s1(60.0);
    Time t1(2.0);

    float distance = calculate_distance(s1, t1);

    cout << "Total distance traveled: " << distance << " km" << endl;

    return 0;
}
