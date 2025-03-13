#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title, author, publisher;

public:
    Book(string title, string author, string publisher)
    {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};

class FictionBook : public Book
{
    string genre;

public:
    FictionBook(string title, string author, string publisher, string genre) : Book(title, author, publisher)
    {
        this->genre = genre;
    }

    void display()
    {
        Book::display();
        cout << "Genre: " << genre << endl;
        cout << endl;
    }
};

int main()
{
    FictionBook f1("Robinhood", "Ahmed", "Ali", "Adventure");
    FictionBook f2("Rays", "Hamza", "Daniel", "Mystery");

    f1.display();
    f2.display();
}