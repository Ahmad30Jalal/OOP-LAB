#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{

    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    void display()
    {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

int main()
{
    Pair<int, string> p1(23, "hi");
    p1.display();

    Pair<double, int> p2(23.123, 11);
    p2.display();

    Pair<float, char> p3(1.22, 'a');
    p3.display();
}