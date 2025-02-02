#include <iostream>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
    string genre;
};

Book b[50];
int count = 0;

void add()
{
    cout << "Enter book title: ";
    cin >> b[count].title;
    cout << "Enter book author: ";
    cin >> b[count].author;
    cout << "Enter publishing year: ";
    cin >> b[count].year;
    cout << "Enter book genre: ";
    cin >> b[count].genre;

    count++;
    cout << "Book added successfully\n";
}

void search()
{
    string find;

    if (count == 0)
    {
        cout << "No books available";
        return;
    }
    cout << "Enter title or author of book: ";
    cin >> find;

    for (int i = 0; i < count; i++)
    {
        if (b[i].title == find || b[i].author == find)
        {
            cout << "Book title: " << b[i].title << endl;
            cout << "Book author: " << b[i].author << endl;
            cout << "Published year: " << b[i].year << endl;
            cout << "Book genre: " << b[i].genre << endl;
        }
        else
        {
            cout << "Book not found";
        }
    }
}

void update()
{
    string a;
    if (count == 0)
    {
        cout << "No books available";
        return;
    }
    cout << "Enter book title to update: ";
    cin >> a;

    for (int i = 0; i < count; i++)
    {
        if (b[i].title == a)
        {
            cout << "Enter updated author: ";
            cin >> b[i].author;
            cout << "Enter updated published year: ";
            cin >> b[i].year;
            cout << "Enter updated book genre: ";
            cin >> b[i].genre;
            cout << "Book details updated successfully\n";
        }
        else
        {
            cout << "Book not found";
        }
    }
}

int main()
{
    int num;
    do
    {
        cout << "\nEnter 1 to add a book\n2 to search a book\n3 to update to book\n4 to exit program: ";
        cin >> num;

        switch (num)
        {
        case 1:
            add();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (num != 4);

    return 0;
}
