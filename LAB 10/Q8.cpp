#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    ifstream file("article.txt");
    if (!file.is_open())
    {
        cout << "Error opening file";
        return 1;
    }

    file.seekg(0, ios::end);
    streampos file_size = file.tellg();

    streampos half_size = file_size / 2;

    file.seekg(half_size, ios::beg);

    string lines;
    int line_count;

    while (line_count < 10 && getline(file, lines))
    {
        cout << lines << endl;
        line_count++;
    }

    if (line_count < 10)
    {
        cout << "Only " << line_count << " were available";
    }
    file.close();
    return 0;
}
