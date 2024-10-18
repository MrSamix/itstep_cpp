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

struct Newspaper
{
	char name[SIZE]{};
	int year;
};


int countSize(fstream& file)
{
	int bytes = 0;
	file.seekg(0, ios_base::end);
	bytes = file.tellg();
	/*cout << bytes << endl;*/

	/*cout << "bytes = " << bytes << endl;*/
	int size = bytes / sizeof(Book);
	file.seekg(0); // скинути на 0
	return size;
}

int countSize2(fstream& file)
{
	int bytes = 0;
	file.seekg(0, ios_base::end);
	bytes = file.tellg();
	//cout << bytes << endl;

	/*cout << "bytes = " << bytes << endl;*/
	int size = bytes / sizeof(Journal);
	file.seekg(0); // скинути на 0
	return size;
}

// Books:

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
		cout << "\n\n ========================================== " << library_book_read[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
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
		cout << "\n\n ========================================== " << library_book_read_4[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
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
	return strcmp(book1.name, book2.name) > 0;
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
void sortDBBook(fstream& file)
{
	int read_size_5 = countSize(file);
	Book* library_book_read_5 = new Book[read_size_5];
	for (int i = 0; i < read_size_5; i++)
	{
		file.read((char*)&library_book_read_5[i], sizeof(Book));
	}
	file.close();

	bubbleSort(library_book_read_5, read_size_5);

	for (int i = 0; i < read_size_5; i++)
	{
		cout << "\n\n ========================================== " << library_book_read_5[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
		cout << "\t\t Author: " << library_book_read_5[i].author << endl;
		cout << "\t\t Publisher: " << library_book_read_5[i].publisher << endl;
		cout << "\t\t Genre: " << library_book_read_5[i].genre << endl;
	}

	remove("books.txt");
	file.open("books.txt", ios_base::app);
	for (int i = 0; i < read_size_5; i++)
	{
		file.write((char*)&library_book_read_5[i], sizeof(Book));
	}
	file.close();
}

// Task 6
void searchDBBook(fstream& file)
{
	int read_size_6 = countSize(file);
	Book* library_book_read_6 = new Book[read_size_6];
	for (int i = 0; i < read_size_6; i++)
	{
		file.read((char*)&library_book_read_6[i], sizeof(Book));
	}
	file.close();
	char author[SIZE];
	cin.ignore();
	cout << "Enter author of search: ";
	cin.getline(author, SIZE);
	char name[SIZE];
	cout << "enter name of search: ";
	cin.getline(name, SIZE);

	bool search = false;
	for (int i = 0; i < read_size_6; i++)
	{
		if (strcmp(library_book_read_6[i].name, name) == 0 && strcmp(library_book_read_6[i].author, author) == 0)
		{
			search = true;
			cout << "Searched: " << endl << endl;
			cout << "\n\n ========================================== " << library_book_read_6[i].name << " ======================================== \n";
			cout << "\t\t Index: " << i << endl;
			cout << "\t\t Author: " << library_book_read_6[i].author << endl;
			cout << "\t\t Publisher: " << library_book_read_6[i].publisher << endl;
			cout << "\t\t Genre: " << library_book_read_6[i].genre << endl;
		}
	}
	if (!search)
	{
		cout << "Book not found" << endl;
	}
}

// Task 7
void vibyrkaDBBook(fstream& file)
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
	cout << "Search by author or genre? (a/g) ";
	cin >> choice_7;
	if (choice_7 == 'a') // recomended to use switch
	{
		cout << "Enter a author to search: ";
		cin >> author_7;
		for (int i = 0; i < read_size_7; i++)
		{
			if (library_book_read_7[i].author == author_7)
			{
				cout << "\n\n ========================================== " << library_book_read_7[i].name << " ======================================== \n";
				cout << "\t\t Index: " << i << endl;
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
				cout << "\n\n ========================================== " << library_book_read_7[i].name << " ======================================== \n";
				cout << "\t\t Index: " << i << endl;
				cout << "\t\t Author: " << library_book_read_7[i].author << endl;
				cout << "\t\t Publisher: " << library_book_read_7[i].publisher << endl;
				cout << "\t\t Genre: " << library_book_read_7[i].genre << endl;
			}
		}
	}
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


// Journal
// Task 1
void fillDBJournal(fstream& file)
{
	int size;
	cout << "Enter a count a journals: ";
	cin >> size;
	Journal* library_journal = new Journal[size] ;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter a name journal" << endl;
		cin.ignore();
		cin.getline(library_journal[i].name, SIZE);
		cout << "Enter a year of journal" << endl;
		cin >> library_journal[i].year;
		file.write((char*)&library_journal[i], sizeof(Journal));
	}
}

// Task 2
void printDBJournal(fstream& file)
{
	file.seekg(0);
	int read_size = countSize2(file);
	Journal* library_book_journal = new Journal[read_size] ;
	for (int i = 0; i < read_size; i++)
	{
		file.read((char*)&library_book_journal[i], sizeof(Journal));
		cout << "\n\n ========================================== " << library_book_journal[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
		cout << "\t\t Year: " << library_book_journal[i].year << endl;
	}
}

// Task 3
void addnewJournal(fstream& file)
{
	Journal res;
	cout << "Enter a name journal" << endl;
	cin.ignore();
	cin.getline(res.name, SIZE);
	cout << "Enter a year journal" << endl;
	cin >> res.year;
	file.write((char*)&res, sizeof(Journal));
}

// Task 4
void deleteJournal(fstream& file)
{
	int read_size_4 = countSize2(file);
	Journal *library_journal_read_4 = new Journal[read_size_4];
	for (int i = 0; i < read_size_4; i++)
	{
		file.read((char*)&library_journal_read_4[i], sizeof(Journal));
		cout << "\n\n ========================================== " << library_journal_read_4[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
		cout << "\t\t Year: " << library_journal_read_4[i].year << endl;
	}
	Journal* library_journal_read_4_new = new Journal[--read_size_4];
	int index;
	cout << "Enter a index of journal for delete: ";
	cin >> index;
	for (int i = 0; i < read_size_4; i++)
	{
		if (i < index)
		{
			library_journal_read_4_new[i] = library_journal_read_4[i];
		}
		else
		{
			library_journal_read_4_new[i] = library_journal_read_4[i + 1];
		}
	}
	delete[] library_journal_read_4;
	library_journal_read_4 = library_journal_read_4_new;
	file.close();
	remove("journals.txt");
	file.open("journals.txt", ios_base::app);
	for (int i = 0; i < read_size_4; i++)
	{
		file.write((char*)&library_journal_read_4[i], sizeof(Journal));
	}
	file.close();
}

// Task 5
bool compareJournals(const Journal& journal1, const Journal& journal2)
{
	return strcmp(journal1.name, journal2.name) > 0;
}

void bubbleSort(Journal* journals, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (compareJournals(journals[j], journals[j + 1]))
			{
				swap(journals[j], journals[j + 1]);
			}
		}
	}
}

void sortDBJournal(fstream& file)
{
	int read_size_5 = countSize2(file);
	Journal* library_journal_read_5 = new Journal[read_size_5];
	for (int i = 0; i < read_size_5; i++)
	{
		file.read((char*)&library_journal_read_5[i], sizeof(Journal));
	}
	file.close();
	
	bubbleSort(library_journal_read_5, read_size_5);

	
	for (int i = 0; i < read_size_5; i++)
	{
		cout << "\n\n ========================================== " << library_journal_read_5[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
		cout << "\t\t Year: " << library_journal_read_5[i].year << endl;
	}

	remove("journals.txt");
	file.open("journals.txt", ios_base::app);
	for (int i = 0; i < read_size_5; i++)
	{
		file.write((char*)&library_journal_read_5[i], sizeof(Journal));
	}
	file.close();
}


// Task 6
void searchDBJournal(fstream& file)
{
	int read_size_6 = countSize2(file);
	Journal* library_journal_read_6 = new Journal[read_size_6];
	for (int i = 0; i < read_size_6; i++)
	{
		file.read((char*)&library_journal_read_6[i], sizeof(Journal));
	}
	file.close();
	char name[SIZE];
	cout << "Enter name of search: ";
	cin.ignore();
	cin.getline(name, SIZE);

	bool search = false;
	for (int i = 0; i < read_size_6; i++)
	{
		if (strcmp(library_journal_read_6[i].name, name) == 0)
		{
			search = true;
			cout << "Searched: " << endl << endl;
			cout << "\n\n ========================================== " << library_journal_read_6[i].name << " ======================================== \n";
			cout << "\t\t Index: " << i << endl;
			cout << "\t\t Year: " << library_journal_read_6[i].year << endl;
		}
	}
	if (!search)
	{
		cout << "Journal not found" << endl;
	}
}

// Task 7
void vibyrkaDBJournal(fstream& file)
{
	int read_size_7 = countSize2(file);
	Journal* library_journal_read_7 = new Journal[read_size_7];
	for (int i = 0; i < read_size_7; i++)
	{
		file.read((char*)&library_journal_read_7[i], sizeof(Journal));
	}
	file.close();
	string journal_7;
	bool search = false;
	cout << "Enter a name journal to search: ";
	cin >> journal_7;
	for (int i = 0; i < read_size_7; i++)
	{
		if (library_journal_read_7[i].name == journal_7)
		{
			search = true;
			cout << "\n\n ========================================== " << library_journal_read_7[i].name << " ======================================== \n";
			cout << "\t\t Index: " << i << endl;
			cout << "\t\t Year: " << library_journal_read_7[i].year << endl;
		}
	}
	if (!search)
	{
		cout << "Journal not found!" << endl;
	}
}

// Newspaper

// Task 1
void fillDBNewspaper(fstream& file)
{
	int size;
	cout << "Enter a count a newspapers: ";
	cin >> size;
	Newspaper* library_newspaper = new Newspaper[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter a name newspaper" << endl;
		cin.ignore();
		cin.getline(library_newspaper[i].name, SIZE);
		cout << "Enter a year of newspaper" << endl;
		cin >> library_newspaper[i].year;
		file.write((char*)&library_newspaper[i], sizeof(Newspaper));
	}
}

// Task 2
void printDBNewspaper(fstream& file)
{
	int read_size = countSize2(file);
	Newspaper* library_book_newspaper = new Newspaper[read_size];
	for (int i = 0; i < read_size; i++)
	{
		file.read((char*)&library_book_newspaper[i], sizeof(Newspaper));
		cout << "\n\n ========================================== " << library_book_newspaper[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
		cout << "\t\t Year: " << library_book_newspaper[i].year << endl;
	}
}

// Task 3
void addnewNewspaper(fstream& file)
{
	Newspaper res;
	cout << "Enter a name newspaper" << endl;
	cin.ignore();
	cin.getline(res.name, SIZE);
	cout << "Enter a year newspaper" << endl;
	cin >> res.year;
	file.write((char*)&res, sizeof(Newspaper));
}

// Task 4
void deleteNewspaper(fstream& file)
{
	int read_size_4 = countSize2(file);
	Newspaper* library_newspaper_read_4 = new Newspaper[read_size_4];
	for (int i = 0; i < read_size_4; i++)
	{
		file.read((char*)&library_newspaper_read_4[i], sizeof(Newspaper));
		cout << "\n\n ========================================== " << library_newspaper_read_4[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
		cout << "\t\t Year: " << library_newspaper_read_4[i].year << endl;
	}
	Newspaper* library_newspaper_read_4_new = new Newspaper[--read_size_4];
	int index;
	cout << "Enter a index of journal for delete: ";
	cin >> index;
	for (int i = 0; i < read_size_4; i++)
	{
		if (i < index)
		{
			library_newspaper_read_4_new[i] = library_newspaper_read_4[i];
		}
		else
		{
			library_newspaper_read_4_new[i] = library_newspaper_read_4[i + 1];
		}
	}
	delete[] library_newspaper_read_4;
	library_newspaper_read_4 = library_newspaper_read_4_new;
	file.close();
	remove("newspapers.txt");
	file.open("newspapers.txt", ios_base::app);
	for (int i = 0; i < read_size_4; i++)
	{
		file.write((char*)&library_newspaper_read_4[i], sizeof(Newspaper));
	}
	file.close();
}

// Task 5
bool compareNewspapers(const Newspaper& newspaper1, const Newspaper& newspaper2)
{
	return strcmp(newspaper1.name, newspaper2.name) > 0; // Compare in reverse order
}

void bubbleSort(Newspaper* newspapers, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (compareNewspapers(newspapers[j], newspapers[j + 1]))
			{
				swap(newspapers[j], newspapers[j + 1]);
			}
		}
	}
}

void sortDBNewspaper(fstream& file)
{
	int read_size_5 = countSize2(file);
	Newspaper* library_newspaper_read_5 = new Newspaper[read_size_5];
	for (int i = 0; i < read_size_5; i++)
	{
		file.read((char*)&library_newspaper_read_5[i], sizeof(Newspaper));
	}
	file.close();
	
	bubbleSort(library_newspaper_read_5, read_size_5);

	
	for (int i = 0; i < read_size_5; i++)
	{
		cout << "\n\n ========================================== " << library_newspaper_read_5[i].name << " ======================================== \n";
		cout << "\t\t Index: " << i << endl;
		cout << "\t\t Year: " << library_newspaper_read_5[i].year << endl;
	}

	remove("newspapers.txt");
	file.open("newspapers.txt", ios_base::app);
	for (int i = 0; i < read_size_5; i++)
	{
		file.write((char*)&library_newspaper_read_5[i], sizeof(Newspaper));
	}
	file.close();
}

// Task 6
void searchDBNewspaper(fstream& file)
{
	int read_size_6 = countSize2(file);
	Newspaper* library_newspaper_read_6 = new Newspaper[read_size_6];
	for (int i = 0; i < read_size_6; i++)
	{
		file.read((char*)&library_newspaper_read_6[i], sizeof(Newspaper));
	}
	file.close();
	char name[SIZE];
	cin.ignore();
	cout << "Enter name of search: ";
	cin.getline(name, SIZE);

	bool search = false;
	for (int i = 0; i < read_size_6; i++)
	{
		if (strcmp(library_newspaper_read_6[i].name, name) == 0)
		{
			search = true;
			cout << "Searched: " << endl << endl;
			cout << "\n\n ========================================== " << library_newspaper_read_6[i].name << " ======================================== \n";
			cout << "\t\t Index: " << i << endl;
			cout << "\t\t Year: " << library_newspaper_read_6[i].year << endl;
		}
	}
	if (!search)
	{
		cout << "Newspaper not found" << endl;
	}
}

// Task 7
void deleteNewspaperForYear(fstream& file)
{
	int read_size_7 = countSize2(file);
	Newspaper* library_newspaper_read_7 = new Newspaper[read_size_7];
	for (int i = 0; i < read_size_7; i++)
	{
		file.read((char*)&library_newspaper_read_7[i], sizeof(Newspaper));
	}
	file.close();
	int year, counter = 0;
	cout << "Enter a year to delete all newspaper for this year: ";
	cin >> year;
	//counter
	for (int i = 0; i < read_size_7; i++)
	{
		if (library_newspaper_read_7[i].year == year)
		{
			counter++;
		}
	}
	if (counter==0)
	{
		cout << "Nothing to delete" << endl;
		return;
	}
	// write a new arr
	int new_size = read_size_7 - counter;
	Newspaper* new_arr = new Newspaper[new_size]	;
	int index = 0;
	for (int i = 0; i < read_size_7; i++)
	{
		if (library_newspaper_read_7[i].year != year)
		{
			new_arr[index] = library_newspaper_read_7[i];
			index++;
		}
	}
	remove("newspapers.txt");
	file.open("newspapers.txt", ios_base::app);
	if (!file.is_open())
	{
		cout << "Error write in file" << endl;
		return;
	}
	for (int i = 0; i < new_size; i++)
	{
		file.write((char*)&new_arr[i], sizeof(Newspaper));
	}
	file.close();
}



void checkFileIsOpen(fstream& file, const string filepath, bool in = true, bool out = true, bool app = false)
{
	if (!file.is_open())
	{
		if (app)
		{
			file.open(filepath, ios_base::app | ios_base::out | ios_base::in);
		}
		else
		{
			file.open(filepath, ios_base::out | ios_base::in);
		}
	}
}


int main()
{
	char choice;
	cout << "Choose: book, journal or newspaper (b/j/n) ";
	cin >> choice;
	switch (choice)
	{
	case 'b':
	{
		fstream file("books.txt", ios_base::out | ios_base::in);
		if (!file.is_open())
		{
			cout << "This file don't exist, create?(y/n): ";
			char choice_create;
			cin >> choice_create;
			if (choice_create == 'y')
			{
				fstream create_file("books.txt", ios_base::app); // створюю файл
				create_file.close();
			}
			else
			{
				cout << "Exiting..." << endl;
				break;
			}
		}
		int choice_b = 0;
		while (choice_b != -1)
		{
			cout << "1. Fill db by books" << endl;
			cout << "2. Print books" << endl;
			cout << "3. Add book" << endl;
			cout << "4. Delete book" << endl;
			cout << "5. Sort books" << endl;
			cout << "6. Search book" << endl;
			cout << "7. Search all books by author" << endl;
			cout << "8. Count books" << endl;
			cout << "-1. Exit program" << endl;
			cout << "Enter a number: "; cin >> choice_b;
			switch (choice_b)
			{
			case 1:
			{
				checkFileIsOpen(file, "books.txt");
				fillDBBook(file);
				file.close();
				break;
			}
			case 2:
			{
				
				checkFileIsOpen(file, "books.txt", true, false);
				printDBBook(file);
				file.close();
				break;
			}
			case 3:
			{
				checkFileIsOpen(file, "books.txt", true, true, true);
				addnewBook(file);
				file.close();
				break;
			}
			case 4:
			{
				checkFileIsOpen(file, "books.txt", true, true, true);
				deleteBook(file);
				file.close();
				break;
			}
			case 5:
			{
				checkFileIsOpen(file, "books.txt", true, true, true);
				sortDBBook(file);
				break;
			}
			case 6:
			{
				checkFileIsOpen(file, "books.txt", true, true, true);
				searchDBBook(file);
				break;
			}
			case 7:
			{
				checkFileIsOpen(file, "books.txt", true, true, true);
				vibyrkaDBBook(file);
				break;
			}
			case 8:
			{
				checkFileIsOpen(file, "books.txt", true, true, true);
				countBookForGenre(file);
				break;
			}
			case -1:
			{
				cout << "Exiting..." << endl;
				break;
			}
			default:
			{
				cout << "error choice, press -1 to exit program" << endl;
			}
			}
		}
		break;
	}
	case 'j':
	{
		fstream file_j("journals.txt", ios_base::out | ios_base::in);
		if (!file_j.is_open())
		{
			cout << "This file don't exist, create?(y/n): ";
			char choice_create;
			cin >> choice_create;
			if (choice_create == 'y')
			{
				fstream create_file("journals.txt", ios_base::app); // створюю файл
				create_file.close();
			}
			else
			{
				cout << "Exiting..." << endl;
				break;
			}
		}
		int choice_j = 0;
		while (choice_j != -1)
		{
			cout << "1. Fill db by journals" << endl;
			cout << "2. Print journals" << endl;
			cout << "3. Add journal" << endl;
			cout << "4. Delete journal" << endl;
			cout << "5. Sort journals" << endl;
			cout << "6. Search journal" << endl;
			cout << "7. Vibyrka jorunals" << endl;
			cout << "-1. Exit program" << endl;
			cout << "Enter a number: "; cin >> choice_j;
			switch (choice_j)
			{
			case 1:
			{
				checkFileIsOpen(file_j, "journals.txt");
				fillDBJournal(file_j);
				file_j.close();
				break;
			}
			case 2:
			{
				checkFileIsOpen(file_j, "journals.txt", true, true, true);
				printDBJournal(file_j);
				file_j.close();
				break;
			}
			case 3:
			{
				checkFileIsOpen(file_j, "journals.txt", true, true, true);
				addnewJournal(file_j);
				file_j.close();
				break;
			}
			case 4:
			{
				checkFileIsOpen(file_j, "journals.txt", true, true, true);
				deleteJournal(file_j);
				file_j.close();
				break;
			}
			case 5:
			{
				checkFileIsOpen(file_j, "journals.txt", true, true, true);
				sortDBJournal(file_j);
				break;
			}
			case 6:
			{
				checkFileIsOpen(file_j, "journals.txt", true, true, true);
				searchDBJournal(file_j);
				break;
			}
			case 7:
			{
				checkFileIsOpen(file_j, "journals.txt", true, true, true);
				vibyrkaDBJournal(file_j);
				break;
			}
			case -1:
			{
				break;
			}
			default:
				cout << "Error number, press -1 to exit program" << endl;
				break;
			}
		}
		break;
	}
	case 'n':
	{
		fstream file_n("newspapers.txt", ios_base::out | ios_base::in);
		if (!file_n.is_open())
		{
			cout << "This file don't exist, create?(y/n): ";
			char choice_create;
			cin >> choice_create;
			if (choice_create == 'y')
			{
				fstream create_file("newspapers.txt", ios_base::app); // створюю файл
				create_file.close();
			}
			else
			{
				cout << "Exiting..." << endl;
				break;
			}
		}
		int choice_n = 0;
		while (choice_n != -1)
		{
			cout << "1. Fill db by newspapers" << endl;
			cout << "2. Print newspapers" << endl;
			cout << "3. Add newspaper" << endl;
			cout << "4. Delete newspaper" << endl;
			cout << "5. Sort newspapers" << endl;
			cout << "6. Search newspaper" << endl;
			cout << "7. Delete newspapers for year" << endl;
			cout << "-1. Exit program" << endl;
			cout << "Enter a number: "; cin >> choice_n;
			switch (choice_n)
			{
			case 1:
			{
				checkFileIsOpen(file_n, "newspapers.txt", true, true, true);
				fillDBNewspaper(file_n);
				file_n.close();
				break;
			}
			case 2:
			{
				checkFileIsOpen(file_n, "newspapers.txt", true, true, true);
				printDBNewspaper(file_n);
				file_n.close();
				break;
			}
			case 3:
			{
				checkFileIsOpen(file_n, "newspapers.txt", true, true, true);
				addnewNewspaper(file_n);
				file_n.close();
				break;
			}
			case 4:
			{
				checkFileIsOpen(file_n, "newspapers.txt", true, true, true);
				deleteNewspaper(file_n);
				file_n.close();
				break;
			}
			case 5:
			{
				checkFileIsOpen(file_n, "newspapers.txt", true, true, true);
				sortDBNewspaper(file_n);
				file_n.close();
				break;
			}
			case 6:
			{
				checkFileIsOpen(file_n, "newspapers.txt", true, true, true);
				searchDBNewspaper(file_n);
				file_n.close();
				break;
			}
			case 7:
			{
				checkFileIsOpen(file_n, "newspapers.txt", true, true, true);
				deleteNewspaperForYear(file_n);
				break;
			}
			case -1:
			{
				break;
			}
			default:
				cout << "Error number, press -1 to exit program" << endl;
				break;
			}
		}
		break;
	}
	default:
		cout << "Error choice" << endl;
		break;
	}
}