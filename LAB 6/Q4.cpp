#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display_person()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person
{
protected:
    string id;
    int grade;

public:
    Student(string name, int age, string id, int grade) : Person(name, age), id(id), grade(grade)
    {
        this->id = id;
        this->grade = grade;
    }

    void display_student()
    {
        display_person();
        cout << "ID: " << id << endl;
        cout << "Grade: " << grade << endl;
    }
};

class Teacher : public Person
{
protected:
    string subject;
    int room_number;

public:
    Teacher(string name, int age, string subject, int room_number) : Person(name, age), subject(subject), room_number(room_number)
    {
        this->subject = subject;
        this->room_number = room_number;
    }

    void display_teacher()
    {
        display_person();
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << room_number << endl;
    }
};

class GraduateStudent : public Student, public Teacher
{
public:
    GraduateStudent(string name, int age, string id, int grade, string subject, int room_number)
        : Student(name, age, id, grade), Teacher(name, age, subject, room_number) {}

    void display_graduate()
    {
        display_student();
        display_teacher();
        cout << endl;
    }
};

int main()
{
    GraduateStudent g1("Ali", 25, "24K0011", 11, "Computer Science", 101);
    GraduateStudent g2("Ahmed", 20, "22K0124", 10, "Physics", 102);
    g1.display_graduate();
    g2.display_graduate();
    return 0;
}