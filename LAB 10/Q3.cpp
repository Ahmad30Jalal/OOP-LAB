#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ofstream signup_file;
    string name, email;
    string choice = "y";

    signup_file.open("signup.txt", ios::app);
    if (!signup_file.is_open())
    {
        cout << "Error opening file";
        return 1;
    }

    while (choice == "y")
    {
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter email: ";
        getline(cin, email);

        signup_file << "Name: " << name << "Email: " << email << endl;
        cout << "Registration recorded" << endl;

        cout << "Do you want to add another participant (y / n): ";
        cin >> choice;
        cin.ignore();
    }
    signup_file.close();
    cout << "Registration has been saved";

    return 0;
}