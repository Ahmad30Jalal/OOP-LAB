#include <iostream>
using namespace std;

template <typename T>
T divide(T numerator, T denominator)
{
    if (denominator == 0)
    {
        throw "Error: Division by zero is not allowed!";
    }
    return numerator / denominator;
}

int main()
{
    int num, den;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try
    {

        int result_int = divide<int>(num, den);
        cout << "Result (int): " << result_int << endl;

        double result_double = divide<double>(num, den);
        cout << "Result (double): " << result_double << endl;
    }
    catch (const char *errorMsg)
    {
        cout << errorMsg << endl;
    }

    return 0;
}