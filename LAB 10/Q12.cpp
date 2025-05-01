#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void display_file_section(istream &file, streampos position)
{
    const int display_size = 100;
    char buffer[display_size + 1] = {0};

    streampos before = file.tellg();

    if (!file.seekg(position))
    {
        cerr << "Error: Failed to seek to position " << position << endl;
        return;
    }

    file.read(buffer, display_size);
    streamsize chars_read = file.gcount();
    buffer[chars_read] = '\0';

    streampos after = file.tellg();

    cout << "\nPointer position before: " << before << endl;
    cout << "Pointer position after: " << after << endl;
    cout << "Characters read: " << chars_read << endl;
    cout << "Content preview:\n";

    cout << buffer << endl;
}

void clear_cin()
{
    cin.clear();
    while (cin.get() != '\n')
        continue;
}

int main()
{
    string filename;
    cout << "Enter filename to inspect: ";
    getline(cin, filename);

    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    file.seekg(0, ios::end);
    streampos file_size = file.tellg();
    file.seekg(0, ios::beg);

    cout << "File opened successfully. Size: " << file_size << " bytes\n";

    while (true)
    {
        cout << "Enter byte offset (0-" << file_size - 1 << "), or -1 to quit: ";
        long offset;
        cin >> offset;

        if (cin.fail())
        {
            cerr << "Invalid input. Please enter a number.\n";
            clear_cin();
            continue;
        }

        if (offset == -1)
        {
            break;
        }

        if (offset < 0 || offset >= file_size)
        {
            cerr << "Error: Offset out of range\n";
            clear_cin();
            continue;
        }

        clear_cin();
        display_file_section(file, offset);
    }

    file.close();
    cout << "File debugger closed.\n";
    return 0;
}