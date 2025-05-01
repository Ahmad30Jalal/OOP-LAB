#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string name, message;

    cout << "Enter recipient's name: ";
    getline(cin, name);

    cout << "Enter your message: ";
    getline(cin, message);

    ofstream output_file("greeting.txt");

    if (output_file.is_open())
    {
        output_file << "Dear " << name << "\n"
                    << message << "\n"
                    << "Best Regards";
        output_file.close();
        cout << "Message has been written" << endl;
    }
    else
    {
        cout << "Unable to open file";
        return 1;
    }

    return 0;
}