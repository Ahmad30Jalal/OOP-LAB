#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ofstream log_file("backup.txt", ios::app);

    if (!log_file.is_open())
    {
        cout << "Error in opening file" << endl;
        return 1;
        }

    string str;

    while (true)
    {
        cout << "Enter message (quit to exit): ";
        getline(cin, str);

        if (str == "quit")
        {
            break;
        }

        log_file << str << endl;

        streampos file_size = log_file.tellp();
        cout << "File size: " << file_size << " bytes" << endl;

        log_file.flush();
    }
    log_file.close();

    return 0;
}
