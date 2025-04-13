#include <iostream>
#include <string>

using namespace std;

class Student;

float calculate_avg_grade(Student);

class Student
{
private:
    string name;
    int grade1, grade2, grade3;

public:
    Student(string name, int g1, int g2, int g3)
    {
        name = name;
        grade1 = g1;
        grade2 = g2;
        grade3 = g3;
    }

    void display_grades()
    {
        cout << "Grades for " << name << ": "
             << grade1 << ", " << grade2 << ", " << grade3 << endl;
    }

    friend class Teacher;
    friend float calculate_avg_grade(Student);
};

class Teacher
{
public:
    void update_grade(Student s, int grade_number, int new_grade)
    {
        if (grade_number == 1)
            s.grade1 = new_grade;
        else if (grade_number == 2)
            s.grade2 = new_grade;
        else if (grade_number == 3)
            s.grade3 = new_grade;
        else
            cout << "Invalid grade number!" << endl;
    }
};

float calculate_avg_grade(Student s)
{
    return (s.grade1 + s.grade2 + s.grade3) / 3.0;
}

int main()
{
    Student s1("Ali", 65, 70, 60);
    Teacher t1;

    s1.display_grades();
    cout << "Original Average: " << calculate_avg_grade(s1) << endl;

    t1.update_grade(s1, 2, 85);

    cout << "After Teacher's Update:" << endl;
    s1.display_grades();
    cout << "New Average: " << calculate_avg_grade(s1) << endl;

    return 0;
}
