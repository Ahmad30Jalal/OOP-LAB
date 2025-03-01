#include <iostream>
using namespace std;

class LoanHelper
{
private:
    const double rate;
    double amount;
    int months;

public:
    LoanHelper(double r, double a, int m)
        : rate(r), amount(a), months(m)
    {
        if (rate < 0.0 || rate > 0.5)
        {
            cout << "Invalid interest rate! It must be between 0% and 0.5%." << endl;
            exit(1);
        }
    }

    void calculate() const
    {
        double monthly_principal = amount / months;
        double monthlyInterest = monthly_principal * rate;
        double payment = monthly_principal + monthlyInterest;

        cout << "You have to pay " << payment << " every month for "
             << months << " months to repay your loan." << endl;
    }
};

int main()
{
    LoanHelper l1(0.005, 120000, 12);
    l1.calculate();

    LoanHelper l2(0.004, 55000, 6);
    l2.calculate();

    LoanHelper l3(0.008, 9900, 5);
    l3.calculate();

    return 0;
}