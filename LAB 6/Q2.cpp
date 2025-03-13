#include <iostream>
#include <string>
using namespace std;

class Character
{

    float health, damage;

public:
    Character(float health, float damage)
    {
        this->health = health;
        this->damage = damage;
    }

    void display()
    {
        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
    }
};

class Player : public Character
{
    string name;

public:
    Player(float health, float damage, string name) : Character(health, damage), name(name) {}

    void display()
    {
        Character::display();
        cout << "Player name: " << name << endl;
    }
};

class Enemy : public Character
{

    string type;

public:
    Enemy(float health, float damage, string type) : Character(health, damage), type(type) {}

    void display()
    {
        Character::display();
        cout << "Enemy type: " << type << endl;
    }
};

class Wizard : public Player
{
    string spell;

public:
    Wizard(float health, float damage, string name, string spell) : Player(health, damage, name), spell(spell) {}

    void display()
    {
        Player::display();
        cout << "Spell: " << spell << endl;
        cout << endl;
    }
};

int main()
{
    Wizard w1(100, 13, "Poba", "Water waves");
    Wizard w2(100, 19, "Wasde", "Fireball");

    w1.display();
    w2.display();
}