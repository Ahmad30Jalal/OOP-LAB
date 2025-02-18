#include <iostream>
#include <string>
using namespace std;

class CricketPlayer
{

    string name;
    int jersey_number;
    float batting_average;
    int matches_played;
    double total_runs;
    int not_outs;

public:
    CricketPlayer(string n, int number, float average, int matches, double r, int outs)
    {
        this->name = n;
        this->jersey_number = number;
        this->batting_average = average;
        this->matches_played = matches;
        this->total_runs = r;
        this->not_outs = outs;
    }

    void improve_average(int runs)
    {
        batting_average = (runs + total_runs) / (matches_played + 1 - not_outs);
        cout << "Average after improvement (one match): " << batting_average << endl;
    }

    void display_player_stats()
    {
        cout << "Name: " << name << endl;
        cout << "Jersey Number: " << jersey_number << endl;
        cout << "Batting average: " << batting_average << endl;
    }

    void play_match(int runs_scored)
    {

        batting_average = (runs_scored + total_runs) / (matches_played + 1 - not_outs);
        cout << "Batting average after the match: " << batting_average << endl;
    }
};

int main()
{
    CricketPlayer c1("Bobsy", 10, 49.1, 111, 4123, 11);
    CricketPlayer c2("Rana", 21, 22, 40, 760, 4);
    CricketPlayer c3("Harry", 33, 17, 89, 180, 6);

    c1.display_player_stats();
    c2.display_player_stats();
    c3.display_player_stats();

    c1.improve_average(88);
    c2.improve_average(5);
    c3.improve_average(33);

    c1.play_match(129);
    c1.play_match(65);
    c2.play_match(18);
    c3.play_match(21);

    return 0;
}