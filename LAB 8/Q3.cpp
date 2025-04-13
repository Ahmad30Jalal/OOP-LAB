#include <iostream>
#include <string>

using namespace std;

class ComplexNumber
{
private:
    float real;
    float imaginary;

public:
    ComplexNumber(float r = 0, float i = 0)
    {
        real = r;
        imaginary = i;
    }

    ComplexNumber operator+(ComplexNumber c)
    {
        return ComplexNumber(real + c.real, imaginary + c.imaginary);
    }

    ComplexNumber operator-(ComplexNumber c)
    {
        return ComplexNumber(real - c.real, imaginary - c.imaginary);
    }

    ComplexNumber operator*(ComplexNumber c)
    {
        float real_part = (real * c.real) - (imaginary * c.imaginary);
        float imag_part = (real * c.imaginary) + (imaginary * c.real);
        return ComplexNumber(real_part, imag_part);
    }

    bool operator==(ComplexNumber c)
    {
        return (real == c.real) && (imaginary == c.imaginary);
    }

    void display()
    {
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i" << endl;
        else
            cout << real << " - " << -imaginary << "i" << endl;
    }
};

int main()
{
    ComplexNumber c1(5, 4);
    ComplexNumber c2(6, 2);
    ComplexNumber sum = c1 + c2;
    ComplexNumber diff = ComplexNumber(7, 1) - ComplexNumber(5, 6);
    ComplexNumber product = ComplexNumber(9, 3) * ComplexNumber(1, 4);
    ComplexNumber identical1(3, 0);
    ComplexNumber identical2(3, 5);
    ComplexNumber different(4, 4);

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    cout << "Product: ";
    product.display();

    cout << (identical1 == identical2 ? "True" : "False") << endl;
    cout << (identical1 == different ? "True" : "False") << endl;

    return 0;
}
