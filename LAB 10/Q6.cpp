#include <iostream>
#include <fstream>
using namespace std;

bool is_upper_case(char a)
{
    return (a >= 'A' && a <= 'Z');
}

void create_file()
{
    ofstream file1("file.txt");
    if (file1.is_open())
    {
        file1 << "The Code is 123, FOR yoUr Mobile";
        file1.close();
    }
    else
    {
        cout << "Error opening file";
    }
}

int main()
{
    ifstream file2("file.txt");
    if (!file2.is_open())
    {
        create_file();
    }
    else
    {
        file2.close();
    }

    ifstream file("file.txt");
    char ch;
    int count;

    if (!file.is_open())
    {
        cout << "Error opening file";
        return 1;
    }

    while (file.get(ch))
    {
        if (is_upper_case(ch))
        {
            count++;
        }
    }
    file.close();
    cout << "Uppercase letters: " << count;
    return 0;
}