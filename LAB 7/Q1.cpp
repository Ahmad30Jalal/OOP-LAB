#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    string account_number;
    string type;
    string holder_name;
    double balance;
    string history[10];
    int count;

public:
    Account(string account, string type, string name, double balance)
        : account_number(account), type(type), holder_name(name), balance(balance), count(0) {}

    virtual ~Account() {}

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Amount must be positive" << endl;
        }
        else
        {
            balance += amount;
            cout << amount << " deposited in your account" << endl;
            if (count < 10)
            {
                history[count++] = "Deposit: " + to_string(amount);
            }
            else
            {
                cout << "Transaction history is full. Cannot record this deposit." << endl;
            }
        }
    }

    virtual void withdraw(double w_amount)
    {
        if (w_amount <= 0)
        {
            cout << "Amount must be positive" << endl;
        }
        else if (balance >= w_amount)
        {
            balance -= w_amount;
            cout << "You withdrew " << w_amount << endl;
            if (count < 10)
            {
                history[count++] = "Withdrawn: " + to_string(w_amount);
            }
            else
            {
                cout << "Transaction history is full. Cannot record this withdrawal." << endl;
            }
        }
        else
        {
            cout << "Not enough balance" << endl;
        }
    }

    virtual void calculate_interest() = 0;

    void get_account_info()
    {
        cout << "Account Number: " << account_number << endl;
        cout << "Account Type: " << type << endl;
        cout << "Account Holder Name: " << holder_name << endl;
        cout << "Available Balance: " << balance << endl;
    }

    void print_statement()
    {
        cout << "Transaction History:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << history[i] << endl;
        }
        cout << "Available Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account
{
    float interest_rate;
    double minimum_balance;

public:
    SavingsAccount(string account, string type, string name, double balance, float rate, double minimum)
        : Account(account, type, name, balance), interest_rate(rate), minimum_balance(minimum) {}

    void withdraw(double amount) override
    {
        if (amount <= 0)
        {
            cout << "Amount cannot be less than zero" << endl;
        }
        else if (balance - amount < minimum_balance)
        {
            cout << "You cannot have balance less than the required minimum balance" << endl;
        }
        else
        {
            Account::withdraw(amount);
        }
    }

    void calculate_interest() override
    {
        double interest = balance * interest_rate / 100;
        balance += interest;
        if (count < 10)
        {
            history[count++] = "Interest Credited: " + to_string(interest);
        }
        else
        {
            cout << "Transaction history is full. Cannot record interest." << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(string account, string name, double balance)
        : Account(account, "Checking", name, balance) {}

    void calculate_interest() override
    {
        cout << "No interest is calculated for checking accounts." << endl;
    }
};

class FixedDepositAccount : public Account
{
    string maturity_date;
    float interest_rate;

public:
    FixedDepositAccount(string account, string name, double balance, string date, float rate)
        : Account(account, "Fixed Deposit", name, balance), maturity_date(date), interest_rate(rate) {}

    void withdraw(double amount) override
    {
        cout << "Withdrawals are not allowed before maturity date." << endl;
    }

    void calculate_interest() override
    {
        double interest = balance * interest_rate / 100;
        balance += interest;
        if (count < 10)
        {
            history[count++] = "Interest Credited: " + to_string(interest);
        }
        else
        {
            cout << "Transaction history is full. Cannot record interest." << endl;
        }
    }

    void print_statement()
    {
        Account::print_statement();
        cout << "Maturity date: " << maturity_date << endl;
    }
};

int main()
{
    SavingsAccount s1("46476", "Savings", "Ali", 89000, 2.5, 50000);

    s1.deposit(5000);
    s1.withdraw(20000);
    s1.calculate_interest();
    s1.get_account_info();
    s1.print_statement();

    FixedDepositAccount f1("566363454", "Ahmed", 103200, "2025-3-22", 4.4);
    f1.deposit(10000);
    f1.withdraw(11000);
    f1.calculate_interest();
    f1.get_account_info();
    f1.print_statement();

    CheckingAccount c1("67890", "Hamud", 320000);
    c1.deposit(12000);
    c1.withdraw(20000);
    c1.calculate_interest();
    c1.get_account_info();
    c1.print_statement();

    return 0;
}