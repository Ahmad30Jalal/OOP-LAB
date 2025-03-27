#include <iostream>
#include <string>
using namespace std;

class Currency
{
protected:
    double amount;
    string currency_code, currency_symbol;

public:
    Currency(double amt, string code, string symbol) : amount(amt), currency_code(code), currency_symbol(symbol)
    {
        this->amount = amount;
        this->currency_code = currency_code;
        this->currency_symbol = currency_symbol;
    }

    virtual double convert_to_base()
    {
        return amount;
    }
    virtual void convert_to(string target_currency) = 0;
    void display()
    {
        cout << "Amount: " << amount << endl;
        cout << "Currency code: " << currency_code << endl;
        cout << "Currency symbol: " << currency_symbol << endl;
    }
};

class Dollar : public Currency
{
    double convert;

public:
    Dollar(double amt, string code, string symbol) : Currency(amt, code, symbol) {}

    void convert_to(string target_currency) override
    {
        if (target_currency == "pkr")
        {
            convert = amount * 281;
        }

        else if (target_currency == "euro")
        {
            convert = amount * 0.93;
        }
        else
        {
            cout << "Exchange not availble" << endl;
        }
    }

    void dollar_display()
    {
        Currency::display();
        cout << "Amount converted: " << convert << endl;
        cout << endl;
    }
};

class Rupee : public Currency
{
    double convert;

public:
    Rupee(double amt, string code, string symbol) : Currency(amt, code, symbol) {}

    void convert_to(string target_currency) override
    {
        if (target_currency == "usd")
        {
            convert = amount / 281;
        }
        else if (target_currency == "euro")
        {
            convert = amount / 302;
        }
    }

    double convert_to_base() override
    {
        return amount / 281;
    }

    void Rupee_display()
    {
        Currency::display();
        cout << "Converted amount: " << convert << endl;
        cout << endl;
    }
};

class Euro : public Currency
{
    double convert;

public:
    Euro(double amt, string code, string symbol) : Currency(amt, code, symbol) {}

    void convert_to(string target_currency) override
    {
        if (target_currency == "usd")
        {
            convert = amount / 1.08;
        }
        else if (target_currency == "pkr")
        {
            convert = amount * 302;
        }
    }

    double convert_to_base() override
    {
        return amount / 1.08;
    }

    void Euro_display()
    {
        Currency::display();
        cout << "Converted amount: " << convert << endl;
        cout << endl;
    }
};

int main()
{
    Dollar d(1100, "3345", "$");
    Rupee r(250000, "53w5", "pkr");
    Euro e(1298, "655342", "€");

    d.convert_to("pkr");
    d.dollar_display();

    r.convert_to("euro");
    r.convert_to_base();
    r.Rupee_display();

    e.convert_to("usd");
    e.convert_to_base();
    e.Euro_display();
}