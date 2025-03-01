#include <iostream>
#include <string>
using namespace std;

class MenuItem
{
public:
    string name;
    float price;

    MenuItem(string n = " ", float p = 0) : name(n), price(p) {}
};

class Menu
{
    MenuItem items[10];
    int count;

public:
    Menu() : count(0) {}

    void add_items(string name, float price)
    {
        if (count < 10)
        {
            items[count] = MenuItem(name, price);
            cout << name << " added" << endl;
            cout << "Price: " << price << endl;
            count++;
        }
        else
        {
            cout << "Cannot add more items" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < count; i++)
        {
            cout << "Item name: " << items[i].name << endl;
            cout << "Price: " << items[i].price << endl;
        }
    }

    void remove(string name)
    {
        for (int i = 0; i < count; i++)
        {
            if (items[i].name == name)
            {
                for (int j = i; j < count - 1; j++)
                {
                    items[j] = items[j + 1];
                }
                count--;
                cout << name << " is removed" << endl;
                return;
            }
        }
        cout << "Item not found" << endl;
    }

    MenuItem get_item(int index)
    {
        if (index >= 0 && index < count)
        {
            return items[index];
        }
        return MenuItem();
    }

    int get_item_count()
    {
        return count;
    }
};

class Payment
{
    float amount;

public:
    Payment(float am) : amount(am) {}

    float get_amount()
    {
        return amount;
    }

    void display_amount()
    {
        cout << "Payment: " << amount << endl;
    }
};

class Order
{
    MenuItem items[10];
    int item_count;
    Payment payment;

public:
    Order(MenuItem ordered_items[], int count) : item_count(count), payment(0)
    {
        float total = 0;
        for (int i = 0; i < count; i++)
        {
            items[i] = ordered_items[i];
            total += ordered_items[i].price;
        }
        payment = Payment(total); // Calculate payment
    }

    void display_order()
    {
        cout << "Order Details:" << endl;
        for (int i = 0; i < item_count; i++)
        {
            cout << "Item: " << items[i].name << " - Price: " << items[i].price << endl;
        }
        payment.display_amount();
    }
};

int main()
{

    Menu menu;
    menu.add_items("Karahi", 1300);
    menu.add_items("Biryani", 400);
    menu.add_items("Pizza", 1200);

    cout << "\nMenu Items:" << endl;
    menu.display();

    MenuItem ordered_items[2];
    ordered_items[0] = menu.get_item(0);
    ordered_items[1] = menu.get_item(1);

    Order order(ordered_items, 2);
    cout << "\nOrder Placed:" << endl;
    order.display_order();

    menu.remove("Pizza");
    cout << "\nUpdated Menu:" << endl;
    menu.display();

    return 0;
}