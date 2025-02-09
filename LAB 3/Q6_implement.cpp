#include "Employee.h"

void Employee::set_info(double s, string n, float t)
{
    salary = s;
    name = n;
    tax = t;
}

void Employee::get_info()
{
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
    cout << "Tax percentage: " << tax << "%" << endl;
}

void Employee::salary_after_tax()
{
    double net_salary1 = salary * ((100 - tax) / 100);
    double net_salary2 = net_salary1 * 0.98;
    cout << "Salary after your tax: " << net_salary1 << endl;
    cout << "Salary after additional 2% tax: " << net_salary2 << endl;
}

void Employee::update_tax(float new_tax)
{
    tax = new_tax;
    double net_salary3 = salary * ((100 - tax) / 100);
    double net_salary4 = net_salary3 * 0.98;
    cout << "Salary after updated tax: " << net_salary3 << endl;
    cout << "Salary after 2% tax deduction: " << net_salary4 << endl;
}
