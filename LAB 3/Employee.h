#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee
{
private:
    double salary;
    string name;
    float tax;

public:
    void set_info(double s, string n, float t);
    void get_info();
    void salary_after_tax();
    void update_tax(float new_tax);
};

#endif
