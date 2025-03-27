#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name, id, address, phone_number, email;

public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phone_number(p), email(e) {}

    virtual void display_info()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone_number << endl;
        cout << "Email: " << email << endl;
    }

    void update_info(string n, string a, string p, string e)
    {
        name = n;
        address = a;
        phone_number = p;
        email = e;
    }

    string get_name()
    {
        return name;
    }
};

class Student : public Person
{
private:
    string *courses_enrolled;
    int num_courses;
    float gpa;
    int enrollment_year;

public:
    Student(string n, string i, string a, string p, string e, float g, int ey, string *courses, int num)
        : Person(n, i, a, p, e), gpa(g), enrollment_year(ey), num_courses(num)
    {
        courses_enrolled = new string[num_courses];
        for (int i = 0; i < num_courses; i++)
        {
            courses_enrolled[i] = courses[i];
        }
    }

    ~Student()
    {
        delete[] courses_enrolled;
    }

    void display_info() override
    {
        Person::display_info();
        cout << "Enrollment Year: " << enrollment_year << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Courses Enrolled: ";
        for (int j = 0; j < num_courses; ++j)
        {
            cout << courses_enrolled[j];
            if (j < num_courses - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

class Professor : public Person
{
private:
    string department;
    string *courses_taught;
    int num_courses;
    float salary;

public:
    Professor(string n, string i, string a, string p, string e, string d, float s, string *courses, int num)
        : Person(n, i, a, p, e), department(d), salary(s), num_courses(num)
    {
        courses_taught = new string[num_courses];
        for (int j = 0; j < num_courses; ++j)
        {
            courses_taught[j] = courses[j];
        }
    }

    ~Professor()
    {
        delete[] courses_taught;
    }

    void display_info() override
    {
        Person::display_info();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Courses Taught: ";
        for (int j = 0; j < num_courses; ++j)
        {
            cout << courses_taught[j];
            if (j < num_courses - 1)
                cout << ", ";
        }
        cout << endl;
    }
};

class Staff : public Person
{
private:
    string department;
    string position;
    float salary;

public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, float s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}

    void display_info() override
    {
        Person::display_info();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Course
{
private:
    string course_id;
    string course_name;
    int credits;
    string instructor;
    string schedule;

public:
    Course(string id, string name, int cr, string inst, string sch)
        : course_id(id), course_name(name), credits(cr), instructor(inst), schedule(sch) {}

    void register_student(Student &student)
    {
        cout << "Registering student " << student.get_name() << " for course " << course_name << endl;
    }

    void calculate_grades()
    {
        cout << "Calculating grades for course " << course_name << endl;
    }

    void display_course_info()
    {
        cout << "Course ID: " << course_id << endl;
        cout << "Course Name: " << course_name << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main()
{
    Course c1("CS", "Programming Fundamentals", 3, "Sir Ali", "Mon/Wed 10:00-11:30");
    Course c2("MATH", "Multivariable Calculus", 4, "Sir Danish", "Mon/Thu 13:00-14:30");

    string student_courses[] = {"CS", "MATH"};
    Student student1("Ahmed", "24f", "Karsaz", "555-1234", "ahmed.@gamil.com", 3.8, 2022, student_courses, 2);

    string prof_courses[] = {"CS"};
    Professor prof1("Sir Ali", "325d", "DHA", "555-5678", "Ali@.gmail.com", "Computer Science", 85000.0, prof_courses, 1);

    Staff staff1("Hadi", "E3001", "Korangi", "555-9012", "hadi@gamik.com", "Registrar", "Office Manager", 60000.0);

    student1.display_info();
    cout << endl;

    prof1.display_info();
    cout << endl;

    staff1.display_info();
    cout << endl;

    c1.register_student(student1);
    c1.calculate_grades();
    cout << endl;

    c1.display_course_info();

    return 0;
}