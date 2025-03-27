#include <iostream>
#include <string>

using namespace std;

class Media
{
protected:
    string title;
    string publication_date;
    string unique_id;
    string publisher;

public:
    Media(string title, string pub_date, string id, string publisher)
        : title(title), publication_date(pub_date), unique_id(id), publisher(publisher) {}

    virtual void display_info()
    {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publication_date << endl;
        cout << "ID: " << unique_id << endl;
        cout << "Publisher: " << publisher << endl;
    }

    virtual void check_out()
    {
        cout << "Checking out: " << title << endl;
    }

    virtual void return_item()
    {
        cout << "Returning: " << title << endl;
    }

    string get_title()
    {
        return title;
    }
    string get_publication_date()
    {
        return publication_date;
    }
    string get_unique_id()
    {
        return unique_id;
    }
    string get_publisher()
    {
        return publisher;
    }
};

class Book : public Media
{
private:
    string author;
    string isbn;
    int number_of_pages;

public:
    Book(string title, string pub_date, string id,
         string publisher, string author, string isbn, int pages)
        : Media(title, pub_date, id, publisher), author(author), isbn(isbn), number_of_pages(pages) {}

    void display_info() override
    {
        cout << "=== Book ===" << endl;
        Media::display_info();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Pages: " << number_of_pages << endl;
    }

    string get_author()
    {
        return author;
    }
    string get_isbn()
    {
        return isbn;
    }
    int get_number_of_pages()
    {
        return number_of_pages;
    }
};

class DVD : public Media
{
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string title, string pub_date, string id,
        string publisher, string director, int duration, string rating)
        : Media(title, pub_date, id, publisher), director(director), duration(duration), rating(rating) {}

    void display_info() override
    {
        cout << "=== DVD ===" << endl;
        Media::display_info();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }

    string get_director()
    {
        return director;
    }
    int get_duration()
    {
        return duration;
    }
    string get_rating()
    {
        return rating;
    }
};

class CD : public Media
{
private:
    string artist;
    int number_of_tracks;
    string genre;

public:
    CD(string title, string pub_date, string id,
       string publisher, string artist, int tracks, string genre)
        : Media(title, pub_date, id, publisher), artist(artist), number_of_tracks(tracks), genre(genre) {}

    void display_info() override
    {
        cout << "=== CD ===" << endl;
        Media::display_info();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << number_of_tracks << endl;
        cout << "Genre: " << genre << endl;
    }

    string get_artist()
    {
        return artist;
    }
    int get_number_of_tracks()
    {
        return number_of_tracks;
    }
    string get_genre()
    {
        return genre;
    }
};

class Magazine : public Media
{
private:
    string editor;
    int issue_number;
    string category;

public:
    Magazine(string title, string pub_date, string id,
             string publisher, string editor, int issue, string category)
        : Media(title, pub_date, id, publisher), editor(editor), issue_number(issue), category(category) {}

    void display_info() override
    {
        cout << "=== Magazine ===" << endl;
        Media::display_info();
        cout << "Editor: " << editor << endl;
        cout << "Issue: " << issue_number << endl;
        cout << "Category: " << category << endl;
    }

    string get_editor()
    {
        return editor;
    }
    int get_issue_number()
    {
        return issue_number;
    }
    string get_category()
    {
        return category;
    }
};

void search_by_title(Media *media, string title)
{
    if (media->get_title() == title)
    {
        media->display_info();
    }
}

void search_by_author(Book *book, string author)
{
    if (book->get_author() == author)
    {
        book->display_info();
    }
}

void search_by_publication_year(Media *media, string year)
{
    if (media->get_publication_date().substr(0, 4) == year)
    {
        media->display_info();
    }
}

int main()
{
    Book book("Deepwork", "1930-04-11", "B001", "BIll", "Ghalib", "65632", 180);
    DVD dvd("Inception", "2010-07-16", "D001", "Warner Bros", "Bahadur Shah Zafar", 148, "PG-13");
    CD cd("Thriller", "1982-11-30", "C001", "Epic Records", "Umar Akmal", 9, "Pop");
    Magazine magazine("National Geographic", "2023-05-01", "M001", "National Geographic Society", "Shehzad", 245, "Science");

    book.display_info();
    cout << endl;
    dvd.display_info();
    cout << endl;
    cd.display_info();
    cout << endl;
    magazine.display_info();
    cout << endl;

    book.check_out();
    dvd.return_item();
    cout << endl;

    cout << "Search by title 'Inception':" << endl;
    search_by_title(&dvd, "Inception");
    cout << endl;

    cout << "Search by author 'F. Scott Fitzgerald':" << endl;
    search_by_author(&book, "F. Scott Fitzgerald");
    cout << endl;

    cout << "Search by publication year '1982':" << endl;
    search_by_publication_year(&cd, "1982");

    return 0;
}