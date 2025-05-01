#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    fstream file("draft.txt", ios::in | ios::out | ios::binary);
    if (!file.is_open())
    {
        cout << "Error opening file";
        return 1;
    }

    string search = "teh";
    string find = "the";

    bool found = false;
    streampos position;

    char buffer[3];
    while (file.read(buffer, 3))
    {
        if (buffer[0] == 't' && buffer[1] == 'e' && buffer[3] == 'h')
        {
            position = file.tellg();
            position -= 3;
            found = true;
        }

        file.seekg(-2, ios::cur);
    }

    if (found)
    {
        file.seekp(position);
        file.write(find.c_str(), 3);
        cout << "String corrected at position: " << position << endl;
    }
    else
    {
        cout << "Not found";
    }

    file.close();
    return 0;
}