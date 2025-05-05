#include <iostream>
using namespace std;

template <typename MoneyType>
class BankAccount
{
    MoneyType balance;

public:
    BankAccount(MoneyType initialBalance) : balance(initialBalance) {}

    MoneyType getBalance() const
    {
        return balance;
    }

    void withdraw(MoneyType amount)
    {
        if (amount <= 0)
        {
            throw "Error: Withdrawal amount must be positive!";
        }
        if (amount > balance)
        {
            throw "Error: Insufficient funds to complete withdrawal!";
        }
        balance -= amount;
    }

    void displayBalance() const
    {
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount<double> account(555000.0);

    try
    {
        account.displayBalance();

        cout << "Enter withdrawal amount: ";
        double amount;
        cin >> amount;

        account.withdraw(amount);
        cout << "Withdrawal successful! New Balance: " << account.getBalance() << endl;
    }
    catch (const char *errorMsg)
    {
        cout << errorMsg << endl;
        account.displayBalance(); // Show balance after failed withdrawal
    }

    return 0;
}