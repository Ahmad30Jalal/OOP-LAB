#include <iostream>
#include <string>
using namespace std;

class Book{
    string title;
    string author;
    int price;

    public:
        Book() {
            title = "Unknwon";
            author = "Anonymus";
            price = 0;
        }

        Book(string title, string author, int price) {
            this ->title = title;
            this ->author = author;
            this-> price = price;
        }

        Book(Book &bk){
            title = bk.title;
            author = bk.author;
            price = bk.price;
        }

        Book(string t) {
            title = t;
            author = "Anonymus";
            price = 0;
        }

        void display() {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: " << price << endl;
            cout << endl;
        }
};

int main() {
    
    Book b1("Footvall", "Messi", 1200);
    b1.display();
    Book b3("Suiii");
    b3.display();
    Book bk1("good");
    Book bk2(bk1);
    bk1.display();
    bk2.display();


    return 0;
    
}