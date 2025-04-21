#include <iostream>
#include <string>
using namespace std;

class PaymentMethod
{
public:
    virtual bool processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
    virtual void display() const = 0;
};

class CreditCard : public PaymentMethod
{
private:
    string card_number;
    string card_holder;
    string exp_date;
    string cvv;

    bool validateCard() const
    {
        return (card_number.length() == 16) &&
               (cvv.length() == 3) &&
               !exp_date.empty() &&
               !card_holder.empty();
    }

public:
    CreditCard(string num, string holder, string expiry, string cv)
        : card_number(num), card_holder(holder), exp_date(expiry), cvv(cv) {}

    bool processPayment(double amount) override
    {
        if (!validateCard())
        {
            cout << "Credit card validation failed!\n";
            return false;
        }
        cout << "Processing credit card payment of $" << amount
             << " from card ending with " << card_number.substr(12) << "\n";
        return true;
    }

    void display() const override
    {
        cout << "Credit Card (****-****-****-" << card_number.substr(12) << ")\n";
    }
};

class DigitalWallet : public PaymentMethod
{
private:
    string ID;
    double balance;

public:
    DigitalWallet(string id, double bal) : ID(id), balance(bal) {}

    bool processPayment(double amount) override
    {
        if (balance < amount)
        {
            cout << "Insufficient funds in digital wallet!\n";
            return false;
        }
        balance -= amount;
        cout << "Processed digital wallet payment of $" << amount
             << " from wallet " << ID
             << ". Remaining balance: $" << balance << "\n";
        return true;
    }

    void display() const override
    {
        cout << "Digital Wallet (" << ID << ") - Balance: $" << balance << "\n";
    }
};

int main()
{
    PaymentMethod *payments[2];
    payments[0] = new CreditCard("1234567812345678", "John Doe", "12/25", "123");
    payments[1] = new DigitalWallet("john_wallet_123", 500.0);

    cout << "Available Payment Methods:\n";
    for (int i = 0; i < 2; i++)
    {
        cout << i + 1 << ". ";
        payments[i]->display();
    }

    double amounts[] = {150.0, 75.0, 600.0};
    for (double amount : amounts)
    {
        cout << "\nAttempting to process payment of $" << amount << "\n";

        bool success = false;
        for (int i = 0; i < 2 && !success; i++)
        {
            cout << "Trying payment method " << i + 1 << "...\n";
            success = payments[i]->processPayment(amount);
            if (success)
            {
                cout << "Payment successful!\n";
            }
        }

        if (!success)
        {
            cout << "All payment methods failed for amount $" << amount << "\n";
        }
    }

    // Clean up
    for (int i = 0; i < 2; i++)
    {
        delete payments[i];
    }

    return 0;
}