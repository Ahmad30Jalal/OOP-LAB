#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void create_story()
{
    ofstream out_file("story.txt");
    if (out_file.is_open())
    {
        out_file << "The little red riding hood";
        out_file.close();
    }
}

int main()
{

    ifstream story_file("story.txt");
    if (!story_file.is_open())
    {
        create_story();
    }
    else
    {
        story_file.close();
    }

    ifstream input_file("story.txt");
    string paragraph;

    if (getline(input_file, paragraph))
    {
        istringstream iss(paragraph);
        string word;

        while (iss >> word)
        {
            cout << word << endl;
        }
    }
    else
    {
        cout << "could not read from story.txt";
    }

    input_file.close();
    return 0;
}