#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const short SIZE = 100;
struct Book
{
    char name[SIZE]{};
    char author[SIZE]{};
    char publisher[SIZE]{};
    char genre[SIZE]{};
};


int main()
{
    //Book* books = new Book[3]{
    //   {"Iron Flame","Rebecca Yarros","Entangled: Red Tower Books","Fantasy"},
    //   {"The Ever King","LJ Andrews","Victorious","Fantasy"},
    //   {"Harry Potter and the Philosopher's Stone","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
    //};
    //fstream book("books.txt", ios_base::out || ios_base::in);
    //book.write((char*)&books[0], sizeof(Book));
    //if (!book.is_open())
    //{
    //    cout << "Error open files" << endl;
    //}
    //else
    //{
    //    cout << sizeof(books) << endl;
    //    /*Book books[]*/
    //}

    size_t size = 3;
    Book book = { "Harry Potter and the Chamber of Secrets","J.K. rowling","Pottermore Publishing","Children's Fantasy" };
    Book* library = new Book[size]{
       {"Iron Flame","Rebecca Yarros","Entangled: Red Tower Books","Fantasy"},
       {"The Ever King","LJ Andrews","Victorious","Fantasy"},
       {"Harry Potter and the Philosopher's Stone","J.K. Rowling","Pottermore Publishing","Children's Fantasy"},
    };

    // запис у файл структури
    fstream file("books.txt", ios_base::out || ios_base::in); // створили файловий потік і пов'язали з файлом та налаштували на запис
    if (!file.is_open())
    {
    	cout << "Error" << endl;
    	//return 0;
    }
    else
    {
        //file << book; error
        for (int i = 0; i < size; i++)
        {
            file.write((char*)&library[i], sizeof(library[i]));
        }
        for (int i = 0; i < size; i++)
        {
            Book res;
            file.read((char*)&res, sizeof(Book));
            cout << "\n\n ========================================== " << res.name << " ======================================== \n";
            cout << "\t\t Author: " << res.author << endl;
            cout << "\t\t Publisher: " << res.publisher << endl;
            cout << "\t\t Genre: " << res.genre << endl;
        }
        file.close();
    }
}