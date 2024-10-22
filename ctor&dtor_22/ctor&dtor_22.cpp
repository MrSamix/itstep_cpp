#include <iostream>
#include <string>

using namespace std;

class Contact
{
private:
    char* surname;
    char* name;
    char* fathername;
    unsigned int* homephone;
    unsigned int* workphone;
    unsigned int* mobilephone;
    char* additionalinfo;

    void copyStr(char*& dest, const char* source)
    {
        if (dest != nullptr)
            delete[] dest;
        size_t size = strlen(source) + 1;
        dest = new char[size];
        strcpy_s(dest, size, source);
    }
    inline bool isValid(const char* source)
    {
        return name != nullptr && name[0] != '\0';
    }


public:
    Contact()
        :Contact("None")
    {
    }
    Contact(const char* surname)
        :Contact(surname, "None")
    {
    }

    Contact(const char* surname, const char* name)
		:Contact(surname, name, "None")
    {
    }

	Contact(const char* surname, const char* name, const char* fathername)
		:Contact(surname, name, fathername, 0)
	{
	}

    Contact(const char* surname, const char* name, const char* fathername, unsigned int homephone)
        :Contact(surname, name, fathername, homephone, 0)
    {
    }

	Contact(const char* surname, const char* name, const char* fathername, unsigned int homephone, unsigned int workphone)
		:Contact(surname, name, fathername, homephone, workphone, 0)
	{
	}

	Contact(const char* surname, const char* name, const char* fathername, unsigned int homephone, unsigned int workphone, unsigned int mobilephone)
		:Contact(surname, name, fathername, homephone, workphone, mobilephone, "")
	{
	}

    Contact(const char* surname, const char* name, const char* fathername, unsigned int homephone, unsigned int workphone, unsigned int mobilephone, const char* additionalinfo)
    {
        copyStr(this->surname, surname);
        copyStr(this->name, name);
        copyStr(this->fathername, surname);
		this->homephone = new unsigned int(homephone);
		this->workphone = new unsigned int(workphone);
		this->mobilephone = new unsigned int(mobilephone);
		copyStr(this->additionalinfo, additionalinfo);
    }


    ~Contact()
    {
        delete[] surname;
        delete[] name;
        delete[] fathername;
        delete homephone;
        delete workphone;
        delete mobilephone;
        delete[] additionalinfo;
    }

	void print()
	{
		cout << "Surname: " << surname << std::endl;
		cout << "Name: " << name << std::endl;
		cout << "Fathername: " << fathername << std::endl;
		cout << "Homephone: " << *homephone << std::endl;
		cout << "Workphone: " << *workphone << std::endl;
		cout << "Mobilephone: " << *mobilephone << std::endl;
		cout << "Additional info: " << additionalinfo << std::endl;
	}
};



class Contacts
{
private:
	Contact* contacts;
	size_t size;
	size_t capacity; //?

    void resize()
    {
        capacity *= 2;
        Contact* newContacts = new Contact[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newContacts[i] = contacts[i];
        }
        delete[] contacts;
        contacts = newContacts;
    }
public:
	Contacts()
	{
		size = 0;
		capacity = 8;
		contacts = new Contact[capacity];
	}

	~Contacts()
	{
		delete[] contacts;
	}

	void addContact(const Contact& contact)
	{
		if (size == capacity)
			resize();
		contacts[size++] = contact;
	}
	void removeContact(size_t index)
	{
		if (index >= size)
			return;
		for (size_t i = index; i < size - 1; i++)
		{
			contacts[i] = contacts[i + 1];
		}
		size--;
	}
	void search(const char* name)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (strcmp(contacts[i].name, name) == 0)
			{
				contacts[i].print();
			}
		}
	}

	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			contacts[i].print();
		}
	}

};


int main()
{
	Contact contact1("Ivanov", "Ivan", "Ivanovich", 123456789, 987654321, 123123123);
	contact1.print();


}