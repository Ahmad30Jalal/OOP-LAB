#include <iostream>
using namespace std;

class Employee
{
private:
    double salary;
    string name;
    float tax;

public:
    void set_info(double s, string n, float t)
    {
        salary = s;
        name = n;
        tax = t;
    }

    void get_info()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Tax percentage: " << tax << endl;
    }

    void salary_after_tax()
    {
        double net_salary1;
        double net_salary2;
        net_salary1 = salary * ((100 - tax) / 100);
        net_salary2 = net_salary1 * 0.98;
        cout << "Salary after your tax: " << net_salary1 << endl;
        cout << "Salary after 2% tax is added: " << net_salary2 << endl;
    }

    void update_tax(float new_tax)
    {
        double net_salary3;
        double net_salary4;
        net_salary3 = salary * ((100 - new_tax) / 100);
        net_salary4 = net_salary3 * 0.98;
        cout << "Salary after updated tax: " << net_salary3 << endl;
        cout << "Salary after 2% tax deduction: " << net_salary4 << endl;
    }
};

int main()
{
    Employee e;
    e.set_info(120000, "Ahmed", 4);
    e.get_info();
    e.salary_after_tax();
    e.update_tax(5.5);
    return 0;
}