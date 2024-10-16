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


struct Journal
{
	char name[SIZE]{};
	int year;
};


int countSize(fstream& file)
{
	int bytes = 0;
	file.seekg(0, ios_base::end);
	bytes = file.tellg();
	cout << bytes << endl;

	cout << "bytes = " << bytes << endl;
	int size = bytes / sizeof(Book);
	file.seekg(0); // скинути на 0
	return size;
}


// Task 1(book)
void fillDBBook(fstream& file)
{
	int size;
	cout << "Enter a count a books: ";
	cin >> size;
	Book* library_book = new Book[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter a name book" << endl;
		cin.ignore();
		cin.getline(library_book[i].name, SIZE);
		cout << "Enter a author book" << endl;
		cin.getline(library_book[i].author, SIZE);
		cout << "Enter a pusblisher of book" << endl;
		cin.getline(library_book[i].publisher, SIZE);
		cout << "Enter a genre of book" << endl;
		cin.getline(library_book[i].genre, SIZE);
		file.write((char*)&library_book[i], sizeof(Book));
	}
}

// Task 2
void printDBBook(fstream& file)
{
	int read_size = countSize(file);
	Book* library_book_read = new Book[read_size];
	for (int i = 0; i < read_size; i++)
	{
		file.read((char*)&library_book_read[i], sizeof(Book));
		cout << "\n\n ========================================== " << library_book_read[i].name << "======================================== \n";
		cout << "\t\t Author: " << library_book_read[i].author << endl;
		cout << "\t\t Publisher: " << library_book_read[i].publisher << endl;
		cout << "\t\t Genre: " << library_book_read[i].genre << endl;
	}
}

// Task 3
void addnewBook(fstream& file)
{
	Book res;
	cout << "Enter a name book" << endl;
	cin.ignore();
	cin.getline(res.name, SIZE);
	cout << "Enter a author book" << endl;
	cin.getline(res.author, SIZE);
	cout << "Enter a pusblisher of book" << endl;
	cin.getline(res.publisher, SIZE);
	cout << "Enter a genre of book" << endl;
	cin.getline(res.genre, SIZE);
	file.write((char*)&res, sizeof(Book));
}

// Task 4
void deleteBook(fstream& file)
{
	int read_size_4 = countSize(file);
	Book* library_book_read_4 = new Book[read_size_4];
	for (int i = 0; i < read_size_4; i++)
	{
		file.read((char*)&library_book_read_4[i], sizeof(Book));
		cout << "\n\n ========================================== " << library_book_read_4[i].name << "======================================== \n";
		cout << "\t\t Author: " << library_book_read_4[i].author << endl;
		cout << "\t\t Publisher: " << library_book_read_4[i].publisher << endl;
		cout << "\t\t Genre: " << library_book_read_4[i].genre << endl;
	}
	Book* library_book_read_4_new = new Book[--read_size_4];
	int index;
	cout << "Enter a index of book for delete: ";
	cin >> index;
	for (int i = 0; i < read_size_4; i++)
	{
		if (i < index)
		{
			library_book_read_4_new[i] = library_book_read_4[i];
		}
		else
		{
			library_book_read_4_new[i] = library_book_read_4[i + 1];
		}
	}
	delete[] library_book_read_4;
	library_book_read_4 = library_book_read_4_new;
	file.close();
	remove("books.txt");
	file.open("books.txt", ios_base::app);
	for (int i = 0; i < read_size_4; i++)
	{
		file.write((char*)&library_book_read_4[i], sizeof(Book));
	}
	file.close();
}




bool compareBooks(const Book& book1, const Book& book2)
{
	return strcmp(book1.name, book2.name) < 0; // глюк бо воно порівнює по першому символу і маленькі букви більші за великі
}

void bubbleSort(Book* books, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (compareBooks(books[j], books[j + 1]))
			{
				swap(books[j], books[j + 1]);
			}
		}
	}
}

// Task 5
void sortDB(fstream& file)
{
	int read_size_5 = countSize(file);
	Book* library_book_read_5 = new Book[read_size_5];
	for (int i = 0; i < read_size_5; i++)
	{
		file.read((char*)&library_book_read_5[i], sizeof(Book));
	}
	file.close();
	// Sort the books by name using bubble sort
	bubbleSort(library_book_read_5, read_size_5);

	// Print the sorted books
	for (int i = 0; i < read_size_5; i++)
	{
		cout << "\n\n ========================================== " << library_book_read_5[i].name << "======================================== \n";
		cout << "\t\t Author: " << library_book_read_5[i].author << endl;
		cout << "\t\t Publisher: " << library_book_read_5[i].publisher << endl;
		cout << "\t\t Genre: " << library_book_read_5[i].genre << endl;
	}
}

// Task 6
void searchDB(fstream& file)
{
	int read_size_6 = countSize(file);
	Book* library_book_read_6 = new Book[read_size_6];
	for (int i = 0; i < read_size_6; i++)
	{
		file.read((char*)&library_book_read_6[i], sizeof(Book));
	}
	file.close();
	string author = "fig tam";
	string name = "abracadabra";
	bool search = false;
	for (int i = 0; i < read_size_6; i++)
	{
		if (library_book_read_6[i].name == name && library_book_read_6[i].author == author) // якщо не буде робити то прирівняти масив до стрінг
		{
			search = true;
			cout << "Searched: " << endl << endl;
			cout << "\n\n ========================================== " << library_book_read_6[i].name << "======================================== \n";
			cout << "\t\t Author: " << library_book_read_6[i].author << endl;
			cout << "\t\t Publisher: " << library_book_read_6[i].publisher << endl;
			cout << "\t\t Genre: " << library_book_read_6[i].genre << endl;
		}
	}
	if (!search)
	{
		cout << "Book not found" << endl;
	} // дописати ще для журналу
}

// Task 7
void vibyrkaDB(fstream& file)
{
	int read_size_7 = countSize(file);
	Book* library_book_read_7 = new Book[read_size_7];
	for (int i = 0; i < read_size_7; i++)
	{
		file.read((char*)&library_book_read_7[i], sizeof(Book));
	}
	file.close();
	string author_7, genre_7, journal_7;
	char choice_7;
	cout << "Search by author or genre or journal? (a/g/j) ";
	cin >> choice_7;
	if (choice_7 == 'a') // recomended to use switch
	{
		cout << "Enter a author to search: ";
		cin >> author_7;
		for (int i = 0; i < read_size_7; i++)
		{
			if (library_book_read_7[i].author == author_7)
			{
				cout << "\n\n ========================================== " << library_book_read_7[i].name << "======================================== \n";
				cout << "\t\t Author: " << library_book_read_7[i].author << endl;
				cout << "\t\t Publisher: " << library_book_read_7[i].publisher << endl;
				cout << "\t\t Genre: " << library_book_read_7[i].genre << endl;
			}
		}
	}
	else if (choice_7 == 'g')
	{
		cout << "Enter a genre to search: ";
		cin >> genre_7;
		for (int i = 0; i < read_size_7; i++)
		{
			if (library_book_read_7[i].genre == genre_7)
			{
				cout << "\n\n ========================================== " << library_book_read_7[i].name << "======================================== \n";
				cout << "\t\t Author: " << library_book_read_7[i].author << endl;
				cout << "\t\t Publisher: " << library_book_read_7[i].publisher << endl;
				cout << "\t\t Genre: " << library_book_read_7[i].genre << endl;
			}
		}
	}
	/*else if (choice_7 == 'j')
	{
		cout << "Enter a journal to search: ";
		cin >> journal_7;
		for (int i = 0; i < read_size_7; i++)
		{
			if (library_book_read_7[i].genre == journal_7)
			{
				cout << "\n\n ========================================== " << library_book_read_7[i].name << "======================================== \n";
				cout << "\t\t Author: " << library_book_read_7[i].author << endl;
				cout << "\t\t Publisher: " << library_book_read_7[i].publisher << endl;
				cout << "\t\t Genre: " << library_book_read_7[i].genre << endl;
			}
		}
	}*/
}

// Task 8
void countBookForGenre(fstream& file)
{
	int read_size_8 = countSize(file);
	Book* library_book_read_8 = new Book[read_size_8];
	for (int i = 0; i < read_size_8; i++)
	{
		file.read((char*)&library_book_read_8[i], sizeof(Book));
	}
	file.close();
	string genre_8;
	cout << "Enter a genre to count books: ";
	cin >> genre_8;
	int count = 0;
	for (int i = 0; i < read_size_8; i++)
	{
		if (library_book_read_8[i].genre == genre_8)
		{
			count++;
		}
	}
	cout << "Count of books with genre " << genre_8 << " is " << count << endl;
}


int main()
{
	char choice;
	cout << "Choose: book, journal or newspaper (b/j/n) ";
	cin >> choice;
	if (choice == 'b')
	{
		fstream file("books.txt", ios_base::out | ios_base::in);
		/*file.open("books.txt");*/
		if (!file.is_open())
		{
			cout << "error opening file books.txt" << endl;
			fstream create_file("books.txt", ios_base::app); // створюю файл
			create_file.close();
		}
		else
		{
			// Task 1 // можна дописати так щоб писало користувачу чи файл пустий чи ні
			fillDBBook(file);
			// Task 2
			/*fstream file_open;
			file_open.open("books.txt");
			file_open.close();*/
			printDBBook(file);
			file.close();



			// Task 3
			fstream file_open_3("books.txt", ios_base::out | ios_base::app);
			if (!file_open_3.is_open())
			{
				cout << "Error" << endl;
				return 0;
			}
			addnewBook(file_open_3);
			file_open_3.close();

			// Task 4
			fstream file_open_4("books.txt", ios_base::out | ios_base::in);
			if (!file_open_4.is_open())
			{
				cout << "Error" << endl;
				return 0;
			}
			deleteBook(file_open_4);


			// Task 5										
			fstream file_open_5("books.txt", ios_base::out | ios_base::in);
			if (!file_open_5.is_open())
			{
				cout << "Error" << endl;
				return 0;
			}
			sortDB(file_open_5);

			// Task 6
			fstream file_open_6("books.txt", ios_base::out | ios_base::in);
			if (!file_open_6.is_open())
			{
				cout << "Error" << endl;
				return 0;
			}
			searchDB(file_open_6);

			// Task 7
			fstream file_open_7("books.txt", ios_base::out | ios_base::in);
			if (!file_open_7.is_open())
			{
				cout << "Error" << endl;
				return 0;
			}
			vibyrkaDB(file_open_7);

			// Task 8
			fstream file_open_8("books.txt", ios_base::out | ios_base::in);
			if (!file_open_8.is_open())
			{
				cout << "Error" << endl;
				return 0;
			}
			countBookForGenre(file_open_8);

			// Task 9
			// газети треба
		}
	}
}