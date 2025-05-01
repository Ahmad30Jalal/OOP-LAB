#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Student
{
    char name[50];
    int id;
    float gpa;
};

void write(ofstream *file, const Student *s)
{
    file->write(s->name, sizeof(s->name));
    file->write((char *)&s->id, sizeof(s->id));
    file->write((char *)&s->gpa, sizeof(s->gpa));
}

bool read(ifstream *file, Student *s)
{
    file->read(s->name, sizeof(s->name));
    file->read((char *)&s->id, sizeof(s->id));
    file->read((char *)&s->gpa, sizeof(s->gpa));
    return file->good();
}

void add(ofstream *outFile)
{
    int count;
    cout << "Enter number of students: ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        Student s;
        cout << "\nStudent: " << i + 1 << ":\n";

        cout << "Name: ";
        cin.getline(s.name, 50);

        cout << "ID: ";
        cin >> s.id;

        cout << "GPA: ";
        cin >> s.gpa;
        cin.ignore();

        write(outFile, &s);
    }
}

void displayStudents(ifstream *inFile)
{
    Student s;
    int count = 1;

    while (read(inFile, &s))
    {
        cout << count++ << ".   " << s.name << endl;
        cout << s.id << endl;
        cout << s.gpa << endl;
        cout << endl;
        }
}

int main()
{
    const char *filename = "students.data";

    ofstream outFile(filename, ios::binary);
    if (!outFile)
    {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    add(&outFile);
    outFile.close();

    ifstream inFile(filename, ios::binary);
    if (!inFile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    displayStudents(&inFile);
    inFile.close();

    return 0;
}