#include <iostream>
using namespace std;

template <typename T>
void swap_values(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 4;
    int b = 2;
    swap_values(a, b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    float c = 3.32;
    float d = 4.44;

    swap_values(c, d);
    cout << "After swapping: c = " << c << ", d = " << d << endl;

    char e = 'A';
    char f = 'B';

    swap_values(e, f);
    cout << "After swapping: e = " << e << ", f = " << f << endl;
}
