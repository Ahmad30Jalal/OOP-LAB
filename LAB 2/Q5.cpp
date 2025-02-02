#include <iostream>
using namespace std;

int main()
{

    int rows1, columns1, rows2, columns2, choice;

    cout << "Enter number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter number of columns for matrix 1: ";
    cin >> columns1;

    int **arr1 = new int *[rows1];
    for (int i = 0; i < rows1; i++)
    {
        arr1[i] = new int[columns1];
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            cout << "Enter value " << "[" << i << "]" << " [" << j << "]: ";
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter number of columns for matrix 2: ";
    cin >> columns2;

    int **arr2 = new int *[rows2];
    for (int i = 0; i < rows2; i++)
    {
        arr2[i] = new int[columns2];
    }

    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            cout << "Enter value " << "[" << i << "]" << " [" << j << "]: ";
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    int result[rows1][columns1];

    cout << "Enter 1 to add matrices\n2 to subtract \n3 to multiply: ";
    cin >> choice;

    if (choice == 1)
    {
        if (rows1 == rows2 && columns1 == columns2)
        {
            for (int i = 0; i < rows1; i++)
            {
                for (int j = 0; j < columns1; j++)
                {
                    result[i][j] = arr1[i][j] + arr2[i][j];
                }
            }
        }
        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    else if (choice == 2)
    {
        if (rows1 == rows2 && columns1 == columns2)
        {
            for (int i = 0; i < rows1; i++)
            {
                for (int j = 0; j < columns1; j++)
                {
                    result[i][j] = arr1[i][j] - arr2[i][j];
                }
            }
        }
        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    else if (choice == 3)
    {
        if (columns1 == rows2)
        {
            for (int i = 0; i < columns1; i++)
            {
                for (int j = 0; j < columns1; j++)
                {
                    result[i][j] = 0;
                    for (int k = 0; k < columns1; k++)
                    {
                        result[i][j] += arr1[i][k] * arr2[k][j];
                    }
                }
            }

            for (int i = 0; i < rows2; i++)
            {
                for (int j = 0; j < columns2; j++)
                {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        }
        else if (columns1 != rows2)
        {
            cout << "Multiplication not possible";
        }
    }

    for (int i = 0; i < rows1; i++)
    {
        delete[] arr1[i];
        delete[] arr2[i];
    }

    delete[] arr1;
    delete[] arr2;

    return 0;
}