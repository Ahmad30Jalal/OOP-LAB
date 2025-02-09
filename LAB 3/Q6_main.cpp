#include "Employee.h"

int main()
{
    Employee e1, e2, e3;

    e1.set_info(120000, "Ahmed", 4);
    e2.set_info(90000, "Ali", 3);
    e3.set_info(150000, "Anas", 3.3);

    cout << "Employee 1" << endl;
    e1.get_info();
    e1.salary_after_tax();
    e1.update_tax(5.5);

    cout << "Employee 2" << endl;
    e2.get_info();
    e2.salary_after_tax();
    e2.update_tax(4.5);

    cout << "Employee 3" << endl;
    e3.get_info();
    e3.salary_after_tax();
    e3.update_tax(6);

    return 0;
}
