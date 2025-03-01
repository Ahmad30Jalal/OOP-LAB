#include <iostream>
#include <string>
using namespace std;

class ValidateString
{
private:
    string str;

public:
    ValidateString(string s) : str(s) {}

    // Making this function const ensures it doesn't modify the object's state.
    // It only reads data and doesn't change anything.
    bool is_valid() const
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
            {
                return false;
            }
        }
        return true;
    }

    // Making this function const ensures it doesn't modify the object's state.
    // It only reads data and doesn't change anything.
    void spill_tea() const
    {
        if (is_valid())
        {
            cout << "The characters " << str << " are all alphabetic" << endl;
        }
        else
        {
            cout << "The string " << str << " is a rebel" << endl;
        }
    }
};

int main()
{
    ValidateString v1("Ahmed");
    ValidateString v2("Ali34324");
    ValidateString v3("Word");
    ValidateString v4("gone$%");

    v1.spill_tea();
    v2.spill_tea();
    v3.spill_tea();
    v4.spill_tea();

    return 0;
}