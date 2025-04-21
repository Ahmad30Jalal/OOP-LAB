#include <iostream>
#include "Q3_Book.h"

using namespace std;

int main()
{
    Book b1("2020", "Hamza", "397634720");

    cout << "Book Details:" << endl;
    cout << "Title: " << b1.get_title() << endl;
    cout << "Author: " << b1.get_author() << endl;
    cout << "ISBN: " << b1.get_isbn() << endl;

    return 0;
}
