#include <iostream>
using namespace std;

int main()
{
    int cap = 5, size = 0, num;
    int *arr = new int[cap];

    do
    {
        cout << "Enter number (0 to stop): ";
        cin >> num;

        if (num == 0)
            break;

        if (size == cap)
        {
            cap *= 2;
            int *arr1 = new int[cap];

            for (int i = 0; i < size; i++)
            {
                arr1[i] = arr[i];
            }

            delete[] arr;
            arr = arr1;
        }

        arr[size++] = num;

    } while (true);

    int *arr2 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    delete[] arr;

    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }
    delete[] arr2;

    return 0;
}
