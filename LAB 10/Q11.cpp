#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_punctuation(char c)
{
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ';' ||
           c == ':' || c == '\'' || c == '"' || c == '(' || c == ')' ||
           c == '[' || c == ']' || c == '{' || c == '}';
}

void analyze(const string &input_file, const string &output_file)
{
    ifstream in_file(input_file);
    ofstream out_file(output_file);

    if (!in_file.is_open())
    {
        cerr << "Error: Could not open input file " << input_file << endl;
        return;
    }

    if (!out_file.is_open())
    {
        cerr << "Error: Could not open output file " << output_file << endl;
        return;
    }

    int characters = 0;
    int words = 0;
    int lines = 0;
    int punct = 0;

    string line;
    while (getline(in_file, line))
    {
        lines++;
        characters += line.length();

        bool inWord = false;
        for (char c : line)
        {
            if (isspace(c))
            {
                if (inWord)
                {
                    words++;
                    inWord = false;
                }
            }
            else
            {
                inWord = true;
            }

            if (is_punctuation(c))
            {
                punct++;
            }
        }

        if (inWord)
        {
            words++;
        }
    }

    out_file << "Total characters: " << characters << endl;
    out_file << "Total words: " << words << endl;
    out_file << "Total lines: " << lines << endl;
    out_file << "Punctuation marks: " << punct << endl;

    in_file.close();
    out_file.close();
}

int main()
{
    string inputFile = "article.txt";
    string outputFile = "report.txt";

    analyze(inputFile, outputFile);

    return 0;
}