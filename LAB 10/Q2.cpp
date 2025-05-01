#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream diary;
    string text;

    diary.open("diary.txt", ios::app);
    if (!diary.is_open())
    {
        cout << "Failed to open file";
        return 1;
    }

    cout << "Enter your diary entry (type exit to finsh): ";
    while (true)
    {
        getline(cin, text);

        if (text == "exit")
        {
            break;
        }

        diary << text << endl;
    }

    diary.close();
    cout << "Diary entry saved to file";

    return 0;
}