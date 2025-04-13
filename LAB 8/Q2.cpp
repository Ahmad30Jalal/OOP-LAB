#include <iostream>
#include <string>

using namespace std;

class BallsFaced;

class Runs
{
private:
    int runs_scored;

public:
    Runs(int r)
    {
        runs_scored = r;
    }

    friend float calculate_strike_rate(Runs r, BallsFaced b);
};

class BallsFaced
{
private:
    int balls;

public:
    BallsFaced(int b)
    {
        balls = b;
    }

    friend float calculate_strike_rate(Runs r, BallsFaced b);
};

float calculate_strike_rate(Runs r, BallsFaced b)
{
    if (b.balls == 0)
    {
        return 0.0;
    }
    return (static_cast<float>(r.runs_scored) / b.balls) * 100;
}

int main()
{
    Runs r1(85);
    BallsFaced b1(60);

    float strike_rate = calculate_strike_rate(r1, b1);

    cout << "Batsman's Strike Rate: " << strike_rate << endl;

    return 0;
}
