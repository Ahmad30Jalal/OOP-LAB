#include <iostream>
#include <string>
using namespace std;

class DayofYear{
    public:

    int number;
    static string months[12];
    
DayofYear(){

}
    
    DayofYear(int number) {
        this-> number = number;
    }

    void convert() {
        if(number >= 1 && number <= 31) {
            cout << "Day: " << months[0] << " " << number  << endl;
        }
        if(number >= 32 && number <= 59) {
            cout << "Day: " << months[1] << " " <<  number - 31 << endl;
        }
        if(number >= 60 && number <= 90) {
            cout << "Day: " << months[2] << " " << number - 59 << endl;
        }
        if(number >= 91 && number <= 120) {
            cout << "Day: " << months[3] << " " << number - 90 << endl;
        }
        if(number >= 121 && number <= 151) {
            cout << "Day: " << months[4] << " " << number - 120 << endl;
        }
        if(number >= 152 && number <= 182) {
            cout << "Day: " << months[5] << " " << number - 151 << endl;
        }
        if(number >= 183 && number <= 212) {
            cout << "Day: " << months[6] << " " << number - 182 << endl;
        }
        if(number >= 213 && number <= 243) {
            cout << "Day: " << months[7] << " " << number - 212 << endl;
        }
        if(number >= 244 && number <= 274) {
            cout << "Day: " << months[8] << " "  << number - 243 << endl;
        }
        if(number >= 275 && number <= 304) {
            cout << "Day: " << months[9] << " " << number - 274 << endl;
        }
        if(number >= 305 && number <= 334) {
            cout << "Day: " << months[10] << " " << number - 304 << endl;
        }
        if(number >= 335 && number <= 365) {
            cout << "Day: " << months[11] << " " << number - 334 << endl;
        }
        if(number > 365) {
            cout << "Invalid input" << endl;
        }
    }
};

string DayofYear :: months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October"
,"November", "December"};

int main() {
    DayofYear d1(5), d2(222), d3(366);
    d1.convert();
    d2.convert();
    d3.convert();

    return 0;

}




