#ifndef Q3_BOOK_H
#define Q3_BOOK_H

#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string isbn;

public:
    Book(string title, string author, string isbn);

    string get_title() const;
    string get_author() const;
    string get_isbn() const;
};

#endif
