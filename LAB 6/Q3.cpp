#include <iostream>
#include <string>
using namespace std;

class Position
{
    float x, y, z;

public:
    Position(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    void set_position(float x, float y, float z)
    {
        this->x = x;
        this->z = z;
        this->y = y;
    }

    void display_position()
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    }
};

class Health
{
    float health;

public:
    Health(float health = 100) : health(health) {}

    void set_health(float health)
    {
        this->health = health;
    }

    void display_health()
    {
        cout << "Health: " << health << endl;
    }

    void damage(int damage)
    {
        health -= damage;
        if (health < 0)
        {
            health = 0;
        }
    }
};

class Character : public Position, public Health
{
    string name;

public:
    Character(string name, float x = 0, float y = 0, float z = 0, float health = 100) : Position(x, y, z), Health(health), name(name) {}

    void display()
    {
        cout << "Character: " << name << endl;
        display_position();
        display_health();
        cout << endl;
    }
};

int main()
{
    Character c1("Wizard", 3.4, 2.7, 6.1, 100);
    Character c2("Prince", 3, 6.6, 5, 100);

    c1.set_position(3, 1, 6);
    c1.display_position();
    c1.damage(13);
    c1.display_health();
    c1.display();

    c2.set_position(1, 1.4, 4.4);
    c2.display_position();
    c2.damage(30);
    c2.display_health();
    c2.display();
}