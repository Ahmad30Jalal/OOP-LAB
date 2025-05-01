#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

string get_current_time()
{
    time_t now = time(nullptr);
    tm *localTime = localtime(&now);

    char time_str[20];

    strftime(time_str, sizeof(time_str), "%H:%M:%S", localTime);

    return string(time_str);
}

int main()
{
    ofstream logFile("system_log.txt", ios::app);

    if (!logFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string current_time = get_current_time();
    logFile << "System started at: " << current_time << endl;

    logFile.close();
    cout << "Startup logged at " << current_time << endl;

    return 0;
}