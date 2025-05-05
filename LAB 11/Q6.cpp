#include <iostream>
#include <string>
using namespace std;

void validate_user(int age, double salary, double height)
{
    if (age <= 0 || age >= 120)
    {
        throw string("InvalidAgeException: Age must be between 1 and 119");
    }
    if (salary <= 0)
    {
        throw string("InvalidSalaryException: Salary must be positive");
    }
    if (height <= 0)
    {
        throw string("InvalidHeightException: Height must be positive");
    }
}

int main()
{
    int age;
    double salary, height;

    try
    {
        cout << "Enter age: ";
        cin >> age;

        cout << "Enter salary: ";
        cin >> salary;

        cout << "Enter height: ";
        cin >> height;

        validate_user(age, salary, height);

        cout << "User profile is valid!" << endl;
    }
    catch (const string &errorMsg)
    {
        cerr << errorMsg << endl;
    }
    catch (...)
    {
        cerr << "Unknown exception caught" << endl;
    }

    return 0;
}