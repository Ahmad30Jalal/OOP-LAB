#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
    string position, colour;
    float border_thickness;

public:
    Shape(string pos, string col, float thick) : position(pos), colour(col), border_thickness(thick)
    {
        this->position = position;
        this->colour = colour;
        this->border_thickness = border_thickness;
    }

    virtual void draw()
    {
        cout << "Drawing shape" << endl;
    }

    virtual void calculate_area() = 0;

    virtual void calculate_perimeter() = 0;
};

class Circle : public Shape
{
    float radius;
    float x_pos, y_pos;

public:
    Circle(string pos, string col, float thick, float rad, float x, float y) : Shape(pos, col, thick), radius(rad), x_pos(x), y_pos(y)
    {
        this->radius = radius;
        this->x_pos = x_pos;
        this->y_pos = y_pos;
    }

    virtual void draw() override
    {
        cout << "Drawing " << colour << " circle with centre " << x_pos << "," << y_pos << " and thickkness " << border_thickness << endl;
    }

    void calculate_area() override
    {
        cout << "Area: " << radius * radius * 3.142;
    }

    void calculate_perimeter() override
    {
        cout << "Perimeter: " << 2 * 3.142 * radius << endl;
    }
};

class Rectangle : public Shape
{
    float width, height, x_pos, y_pos;

public:
    Rectangle(string pos, string col, float thick, float wth, float hgt, float x, float y) : Shape(pos, col, thick), width(wth), height(hgt), x_pos(x), y_pos(y)
    {
        this->width = width;
        this->height = height;
        this->x_pos = x_pos;
        this->y_pos = y_pos;
    }

    virtual void draw() override
    {
        cout << "Drawing " << colour << " rectangle with top left corner " << x_pos << "," << y_pos << " and border thickness " << border_thickness << endl;
    }

    virtual void calculate_area() override
    {
        cout << "Area: " << width * height << endl;
    }

    virtual void calculate_perimeter() override
    {
        cout << "Perimeter: " << (2 * width) + (2 * height) << endl;
    }
};

class Triangle : public Shape
{
    float base, height, slant_height;

public:
    Triangle(string pos, string col, float thick, float base, float hgt, float slant) : Shape(pos, col, thick), base(base), height(hgt),
                                                                                        slant_height(slant)
    {
        this->base = base;
        this->height = height;
    }

    virtual void draw() override
    {
        cout << "Drawing " << colour << " triangle with border thickness " << border_thickness << endl;
    }

    virtual void calculate_area() override
    {
        cout << "Area: " << 0.5 * base * height << endl;
    }

    void calculate_perimeter() override
    {
        cout << "Perimeter: " << base + slant_height + slant_height << endl;
    }
};

class Polygon : public Shape
{
    int sides_number;
    float length, apothem;

public:
    Polygon(string pos, string col, float thick, int num, float lnt, float ap) : Shape(pos, col, thick), sides_number(num), length(lnt), apothem(ap)
    {
        this->sides_number = sides_number;
        this->length = length;
        this->apothem = apothem;
    }

    virtual void draw() override
    {
        cout << "Drawing " << colour << " polygon with border thickness " << border_thickness << endl;
    }

    virtual void calculate_area() override
    {
        cout << "Area: " << (sides_number * length * apothem) / 2 << endl;
    }

    void calculate_perimeter() override
    {
        cout << "Perimeter: " << sides_number * length << endl;
    }
};

int main()
{
    Circle c("left", "Black", 3.5, 5.5, 7, 9);
    Rectangle r("Centre", "Blue", 4, 11, 12.5, 4, 2);
    Triangle t("right", "Red", 2, 6, 11, 8);
    Polygon p("Bottom", "Green", 1.1, 8, 12, 4);

    c.draw();
    c.calculate_area();
    c.calculate_perimeter();

    r.draw();
    r.calculate_area();
    r.calculate_perimeter();

    t.draw();
    t.calculate_area();
    t.calculate_perimeter();

    p.draw();
    p.calculate_area();
    p.calculate_perimeter();
}