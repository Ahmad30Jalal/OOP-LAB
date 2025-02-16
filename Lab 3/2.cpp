#include <iostream>
#include <string>
using namespace std;

class WeekDays {

private:
    string days[7];
    int current_day;

public:
    WeekDays() {
        days[0] = "Monday";
        days[1] = "Tuesday";
        days[2] = "Wednesday";
        days[3] = "Thursday";
        days[4] = "Friday";
        days[5] = "Saturday";
        days[6] = "Sunday";
        current_day = 0; 
    }

    
    WeekDays(int current_day) {
        days[0] = "Monday";
        days[1] = "Tuesday";
        days[2] = "Wednesday";
        days[3] = "Thursday";
        days[4] = "Friday";
        days[5] = "Saturday";
        days[6] = "Sunday";

        if (current_day > 7) {
            current_day = current_day % 7;
        }
        this->current_day = current_day - 1; 
    }

    void get_current_day() {
        cout << "Current day: " << days[current_day] << endl;
    }

    void get_next_day() {
        int next_day = (current_day + 1) % 7;
        cout << "Next day: " << days[next_day] << endl;
    }

    void get_previous_day() {
        int previous_day = (current_day - 1 + 7) % 7;
        cout << "Previous day: " << days[previous_day] << endl;
    }

    void get_nday() {
        int n;
        cout << "Current day: " << days[current_day] << endl;
        cout << "Enter value of n: ";
        cin >> n;
        int new_day = (current_day + n) % 7;
        cout << "Day after N days: " << days[new_day] << endl;
    }
};

int main() {
    WeekDays w1(5); 
    w1.get_current_day();
    w1.get_next_day();
    w1.get_previous_day();
    w1.get_nday();

    return 0;
}
