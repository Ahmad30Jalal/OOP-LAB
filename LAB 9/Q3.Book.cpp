#include "Q3_Book.h"

Book::Book(string title, string author, string isbn)
    : title(title), author(author), isbn(isbn) {}

string Book::get_title() const
{
    return title;
}

string Book::get_author() const
{
    return author;
}

string Book::get_isbn() const
{
    return isbn;
}
