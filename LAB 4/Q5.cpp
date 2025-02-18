#include <iostream>
#include <string>
using namespace std;

class FootballPlayer
{
    string name;
    string position;
    int goal_count;
    string team;

public:
    FootballPlayer()
    {
        this->name = "Unknown";
        this->position = "Bench warmer";
        this->goal_count = 0;
        this->team = "None";
    }

    FootballPlayer(string name, string position, int goal_count, string team)
    {
        this->name = name;
        this->position = position;
        this->goal_count = goal_count;
        this->team = team;
    }

    FootballPlayer(const FootballPlayer &player)
    {
        this->name = player.name;
        this->position = player.position;
        this->goal_count = player.goal_count;
        this->team = player.team;
    }

    FootballPlayer(string name)
    {
        this->name = name;
        this->position = "Midfielder";
        this->goal_count = 10;
        this->team = "Barca";
    }

    void boostGoal(int goals)
    {
        goal_count += goals;
    }

    void display()
    {
        cout << "Player Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Goal Count: " << goal_count << endl;
        cout << "Team: " << team << endl;
    }
};

int main()
{
    FootballPlayer p1("Antony", "RW", 33, "Betis");
    FootballPlayer p2("Maguire", "CB", 21, "United");
    FootballPlayer p3("Lewandowski", "ST", 321, "Barca");
    FootballPlayer p4;
    FootballPlayer p5("Suarez");
    FootballPlayer p6 = p2;

    p1.boostGoal(4);
    p3.boostGoal(32);

    p1.display();
    p2.display();
    p3.display();
    p4.display();
    p5.display();
    p6.display();

    return 0;
}
