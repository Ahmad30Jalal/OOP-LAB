#include <iostream>
#include <string>
using namespace std;

class WeekDays{

    private:
        string days[7];
        int current_day;

    public:

    WeekDays (){    
days[0]="Monday";        
        current_day = 1;
    }

    WeekDays(int current_day) {
        days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday" ,"Saturday", "Sunday"};

        if (current_day > 7) {
            current_day = current_day % 7;
        }
    }

    void get_current_day(int current_day) {
        cout << "Current day: " << days[current_day] << endl;
    }

    void get_next_day(int current_day) {
        cout << "Next day: " << days[current_day + 1] << endl;
    }

    void get_previous_day(int current_day) {
        cout << "Previous day: " << days[current_day - 1] << endl;
    }

    void get_nday(int current_day) {
        int n;
        cout << "Current day: " << current_day << endl;
        cout << "Enter value of n: ";
        cin >> n;
        int new_day = n + current_day;
        if ((new_day) <= 7) {
            cout << "Day after N days: " << days[new_day] << endl;
        }
        else {
            do {
                new_day -= 7;
            } while(new_day <= 7);
        }
        cout << "Day after N days: " << days[new_day] << endl;
        }


    

    

};

int main() {

    WeekDays w1(5);
    w1.get_current_day(5);
    w1.get_next_day(5);
    w1.get_previous_day(5);
    w1.get_nday(3);

    return 0;
}
