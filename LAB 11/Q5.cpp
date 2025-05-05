#include <iostream>
#include <string>
using namespace std;

template <typename T>
T find(T arr[], int size)
{
    if (size <= 0)
    {
        throw "Error: size must be greater than 0";
    }

    T max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

template <typename T>
void display(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << ", ";
    }
    cout << endl;
}

int main()
{
    int a1[] = {21, 34, 44, 62, 93};
    int size1 = 5;

    display(a1, size1);
    cout << "Max value: " << find(a1, size1) << endl;

    string a2[] = {"What", "Why", "no", "You", "water"};
    int size2 = 5;

    display(a2, size2);
    cout << "Maximum: " << find(a2, size2) << endl;
}