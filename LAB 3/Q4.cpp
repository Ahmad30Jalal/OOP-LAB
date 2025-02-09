#include <iostream>
using namespace std;

class Shop
{

public:
    string items[20];
    double price[20];
    int count;

    void add()
    {

        cout << "Enter item name: ";
        cin >> items[count];
        cout << "Enter item price: ";
        cin >> price[count];
        cout << "item added succesfully" << endl;
        count++;
    }

    void display()
    {

        if (count == 0)
        {
            cout << "No items avaialbe" << endl;
            return;
        }

        for (int i = 1; i < count; i++)
        {
            cout << i << "." << "Item name: " << items[i] << "  " << "Price: " << price[i] << endl;
        }
    }

    void edit()
    {
        int n;
        double p;

        if (count == 0)
        {
            cout << "No items available" << endl;
            return;
        }

        cout << "Enter item number to update price: ";
        cin >> n;
        cout << "Enter new price: ";
        cin >> p;
        price[n] = p;
        cout << "Price updated succesfully" << endl;
    }

    void receipt()
    {
        int num;
        int total = 0;
        cout << "How many items you want to add: ";
        cin >> num;
        if (num > count)
        {
            cout << "Not enough items" << endl;
            return;
        }
        int arr[num];

        cout << "Enter item number to select the item" << endl;

        for (int i = 0; i < num; i++)
        {
            cout << "Enter item number " << i + 1 << ": ";
            cin >> arr[i];
        }

        for (int i = 0; i < num; i++)
        {
            total += price[arr[i]];
        }

        cout << "Items purchased" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << i + 1 << "." << "Item name: " << items[arr[i]] << "  " << "Price: " << price[arr[i]] << endl;
        }
        cout << "Total amount = " << total << endl;
    }
};

int main()
{
    int choice;
    Shop s;

    do
    {
        cout << "Enter 1 to add item\n2 to display\n3 to edit\n4 to generate receipt\n5 to end: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.add();
            break;

        case 2:
            s.display();
            break;

        case 3:
            s.edit();
            break;

        case 4:
            s.receipt();
            break;

        case 5:
            cout << "Ending program";
            break;

        default:
            cout << "Invalid input";
            break;
        }
    } while (choice != 4);
    return 0;
}