#include <iostream>
using namespace std;

int main()
{
    float num1, num2, result;
    float *ptr1 = &num1, *ptr2 = &num2, *ptrResult = &result;
    int a;

    do
    {
        cout << "Enter first number: ";
        cin >> *ptr1;
        cout << "Enter second number: ";
        cin >> *ptr2;
        cout << "Enter 1 for addition\n2 for subtraction\n3 for multiplication\n4 for division\n5 to exit\n";
        cin >> a;

        switch (a)
        {
        case 1:
            *ptrResult = *ptr1 + *ptr2;
            cout << "Answer: " << *ptrResult << endl;
            break;

        case 2:
            *ptrResult = *ptr1 - *ptr2;
            cout << "Answer: " << *ptrResult << endl;
            break;

        case 3:
            *ptrResult = *ptr1 * *ptr2;
            cout << "Answer: " << *ptrResult << endl;
            break;

        case 4:
            if (*ptr2 != 0)
            {
                *ptrResult = *ptr1 / *ptr2;
                cout << "Answer: " << *ptrResult << endl;
            }
            else
            {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;

        case 5:
            cout << "Exiting program\n";
            break;

        default:
            cout << "Invalid option\n";
            break;
        }
    } while (a != 5);

    return 0;
}
