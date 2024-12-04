#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;
const size_t SIZE = 100;

struct Book
{
    char author[100];
    char name[100];
    int year;
    bool available = true;

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Author: " << book.author << ", Name: " << book.name
            << ", Year: " << book.year << ", Available: " << (book.available ? "Yes" : "No");
        return os;
    }
};

class Library
{
public:
    void addBook(const Book& book)
    {
        lib.push_back(book);
    }

    void printBooks() const
    {
        int counter = 1;
        for (const auto& book : lib)
        {
            cout << "Book #" << counter++ << endl;
            cout << book << "\n\n";
        }
    }

    bool searchBook(const char* author, const char* name) const
    {
        auto it = find_if(lib.begin(), lib.end(), [author, name](const Book& book) {
            return strcmp(book.author, author) == 0 && strcmp(book.name, name) == 0;
        });

        return it != lib.end();
    }

    void searchBooksByAuthor(const char* author) const
    {
        int counter = 0;
        for (const auto& book : lib)
        {
            counter++;
            if (strcmp(book.author, author) == 0)
            {
                cout << "Book #" << counter << endl;
                cout << book << "\n\n";
            }
        }
    }

    void issueBook(const char* author, const char* name)
    {
        auto it = find_if(lib.begin(), lib.end(), [author, name](Book& book) {
            return strcmp(book.author, author) == 0 && strcmp(book.name, name) == 0;
        });

        if (it != lib.end())
        {
            it->available = false;
        }
    }

    void returnBook(const char* author, const char* name)
    {
        auto it = find_if(lib.begin(), lib.end(), [author, name](Book& book) {
            return strcmp(book.author, author) == 0 && strcmp(book.name, name) == 0;
        });

        if (it != lib.end())
        {
            it->available = true;
        }
    }

    void sortBooksByAuthorAndName()
    {
        lib.sort([](const Book& book1, const Book& book2) {
            int authorComparison = strcmp(book1.author, book2.author);
            if (authorComparison != 0)
            {
                return authorComparison < 0;
            }
            else
            {
                return strcmp(book1.name, book2.name) < 0;
            }
        });
    }

    void removeBook(const char* author, const char* name, int year)
    {
        lib.remove_if([author, name, year](const Book& book) {
            return strcmp(book.author, author) == 0 && strcmp(book.name, name) == 0 && book.year == year;
        });
    }

    void removeBookByIndex(int index)
    {
        auto it = lib.begin();
        advance(it, index);
        lib.erase(it);
    }

    void editBook(const char* author, const char* name, int year, const Book& newBook)
    {
        auto it = find_if(lib.begin(), lib.end(), [author, name, year](Book& book) {
            return (strcmp(book.author, author) == 0 && strcmp(book.name, name) == 0) || book.year == year;
        });

        if (it != lib.end())
        {
            strcpy_s(it->author, newBook.author);
            strcpy_s(it->name, newBook.name);
            it->year = newBook.year;
            it->available = newBook.available;
        }
    }

private:
    list<Book> lib;
};

int main()
{
    Library library;

    Book book1 = { "Author1", "Book1", 2021 };
    Book book2 = { "Author2", "Book2", 2022 };
    Book book3 = { "Author1", "Book3", 2020 };


    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.printBooks();

    cout << "Search book: " << library.searchBook("Author1", "Book1") << endl;

    cout << "Books by Author1:" << endl;
    library.searchBooksByAuthor("Author1");

    library.issueBook("Author1", "Book1");

    cout << "After issuing book:" << endl;
    library.printBooks();

    library.returnBook("Author1", "Book1");

    cout << "After returning book:" << endl;
    library.printBooks();

    library.sortBooksByAuthorAndName();

    cout << "After sorting:" << endl;
    library.printBooks();

    library.removeBook("Author1", "Book3", 2020);

    cout << "After removing book:" << endl;
    library.printBooks();

    library.removeBookByIndex(0);

    cout << "After removing book by index:" << endl;
    library.printBooks();

    Book newBook = { "NewAuthor", "NewBook", 2023 };
    library.editBook("Author2", "Book2", 2022, newBook);

    cout << "After editing book:" << endl;
    library.printBooks();
}