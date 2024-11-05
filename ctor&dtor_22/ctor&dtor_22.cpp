#include <iostream>
#include <string>

using namespace std;

class Contact
{
private:
    char* surname;
    char* name;
    char* fathername;
    unsigned int homephone;
    unsigned int workphone;
    unsigned int mobilephone;
    char* additionalinfo;

    bool isValid(const char* elem)
    {
        if (elem == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    size_t Len(const char* source)
    {
        if (isValid(source))
        {
            return strlen(source) + 1;
        }
        else
        {
            return 0;
        }
    }
public:
    Contact(const char* surname = nullptr, const char* name = nullptr, const char* fathername = nullptr, const unsigned int homephone = 0, const unsigned int workphone = 0, const unsigned int mobilephone = 0, const char* additionalinfo = nullptr)
    {
        size_t surname_length = Len(surname);
        size_t name_length = Len(name);
        size_t fathername_length = Len(fathername);
        size_t additional_length = Len(additionalinfo);

        if (surname_length != 0)
        {
            this->surname = new char[surname_length];
            strcpy_s(this->surname, surname_length, surname);
        }
        else
        {
            this->surname = new char[1];
            strcpy_s(this->surname, 1, "");
        }
        if (name_length != 0)
        {
            this->name = new char[name_length];
            strcpy_s(this->name, name_length, name);
        }
        else
        {
            this->name = new char[1];
            strcpy_s(this->name, 1, "");
        }
        if (fathername_length != 0)
        {
            this->fathername = new char[fathername_length];
            strcpy_s(this->fathername, fathername_length, fathername);
        }
        else
        {
            this->fathername = new char[1];
            strcpy_s(this->fathername, 1, "");
        }
        if (additional_length != 0)
        {
            this->additionalinfo = new char[additional_length];
            strcpy_s(this->additionalinfo, additional_length, additionalinfo);
        }
        else
        {
            this->additionalinfo = new char[1];
            strcpy_s(this->additionalinfo, 1, "");
        }

        //int 
        this->homephone = homephone;
        this->workphone = workphone;
        this->mobilephone = mobilephone;
    }
    Contact(const Contact& other) // copy constructor
        : homephone(other.homephone), workphone(other.workphone), mobilephone(other.mobilephone) {
        size_t surname_length = Len(other.surname);
        size_t name_length = Len(other.name);
        size_t fathername_length = Len(other.fathername);
        size_t additional_length = Len(other.additionalinfo);

        if (surname_length != 0)
        {
            this->surname = new char[surname_length];
            strcpy_s(this->surname, surname_length, other.surname);
        }
        else
        {
            this->surname = new char[1];
            strcpy_s(this->surname, 1, "");
        }
        if (name_length != 0)
        {
            this->name = new char[name_length];
            strcpy_s(this->name, name_length, other.name);
        }
        else
        {
            this->name = new char[1];
            strcpy_s(this->name, 1, "");
        }
        if (fathername_length != 0)
        {
            this->fathername = new char[fathername_length];
            strcpy_s(this->fathername, fathername_length, other.fathername);
        }
        else
        {
            this->fathername = new char[1];
            strcpy_s(this->fathername, 1, "");
        }
        if (additional_length != 0)
        {
            this->additionalinfo = new char[additional_length];
            strcpy_s(this->additionalinfo, additional_length, other.additionalinfo);
        }
        else
        {
            this->additionalinfo = new char[1];
            strcpy_s(this->additionalinfo, 1, "");
        }
    }
    Contact& operator=(const Contact& other)
    {
        if (this != &other) {
            delete[] surname;
            delete[] name;
            delete[] fathername;
            delete[] additionalinfo;

            homephone = other.homephone;
            workphone = other.workphone;
            mobilephone = other.mobilephone;

            size_t surname_length = Len(other.surname);
            size_t name_length = Len(other.name);
            size_t fathername_length = Len(other.fathername);
            size_t additional_length = Len(other.additionalinfo);

            surname = new char[surname_length];
            strcpy_s(surname, surname_length, other.surname);

            name = new char[name_length];
            strcpy_s(name, name_length, other.name);

            fathername = new char[fathername_length];
            strcpy_s(fathername, fathername_length, other.fathername);

            additionalinfo = new char[additional_length];
            strcpy_s(additionalinfo, additional_length, other.additionalinfo);
        }
        return *this;
    }
    ~Contact()
    {
        delete[] this->surname;
        delete[] this->name;
        delete[] this->fathername;
        delete[] this->additionalinfo;
    }
    void print() const
    {
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Father name: " << fathername << endl;
        cout << "Home phone: " << homephone << endl;
        cout << "Work phone: " << workphone << endl;
        cout << "Mobile phone: " << mobilephone << endl;
        cout << "Additional info: " << additionalinfo << endl;
    }
    inline const char* getSurname() const
    {
        return this->surname;
    }
    inline const char* getName() const
    {
        return this->name;
    }
    inline const char* getFathername() const
    {
        return this->fathername;
    }
    inline void setSurname(const char* surname)
    {
        if (isValid(this->surname))
        {
            delete[] this->surname;
        }
        if (isValid(surname))
        {
            size_t length = Len(surname);
            this->surname = new char[length];
            strcpy_s(this->surname, length, surname);
        }
    }
    inline void setName(const char* name)
    {
        if (isValid(this->name))
        {
            delete[] this->name;
        }
        if (isValid(name))
        {
            size_t length = Len(name);
            this->name = new char[length];
            strcpy_s(this->name, length, name);
        }
    }
    inline void setFatherName(const char* fathername)
    {
        if (isValid(this->fathername))
        {
            delete[] this->fathername;
        }
        if (isValid(fathername))
        {
            size_t length = Len(fathername);
            this->fathername = new char[length];
            strcpy_s(this->fathername, length, fathername);
        }
    }
    inline void setHomePhone(unsigned int homephone)
    {
        this->homephone = homephone;
    }
    inline void setWorkPhone(unsigned int workphone)
    {
        this->workphone = workphone;
    }
    inline void setMobilePhone(unsigned int mobilephone)
    {
        this->mobilephone = mobilephone;
    }
};

class Contacts
{
private:
    Contact* contacts;
    size_t size = 0;
    size_t capacity = 10;
public:
    Contacts()
    {
        contacts = new Contact[capacity];
    };
    Contacts(Contact contact)
    {
        contacts = new Contact[capacity];
        contacts[size++] = contact;
    }
    ~Contacts()
    {
        if (contacts != nullptr)
        {
            delete[] contacts;
        }
    }
    void addContact(Contact other)
    {
        if (size>= capacity)
        {
            capacity++;
            Contact* tmp = new Contact[capacity];
            for (int i = 0; i < size; i++)
            {
                tmp[i] = contacts[i];
            }
            delete[] contacts;
            contacts = tmp;
        }
        contacts[size++] = other;
    }
    void deleteContact(size_t index)
    {
        index--;
        if (index >=0 && index < size)
        {
            Contact* tmp = new Contact[--size];
            for (int i = 0; i < size; i++)
            {
                if (i < index)
                {
                    tmp[i] = contacts[i];
                }
                else
                {
                    tmp[i] = contacts[i + 1];
                }
            }
            delete[] contacts;
            contacts = tmp;
        }
    }
    void searchContacts(const char* surname = "", const char* name = "", const char* fathername = "") const
    {
        for (int i = 0; i < size; i++)
        {
            if (strcmp(surname, contacts[i].getSurname()) == 0 && strcmp(name, contacts[i].getName()) == 0 && strcmp(fathername,contacts[i].getFathername()) == 0)
            {
                cout << "Found!" << endl << endl;
                cout << "Contact #" << i+1 << ":" << endl;
                contacts[i].print();
                cout << "\n\n";
            }
        }
    }
    void printContacts() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Contact #" << i+1 << ":" << endl;
            contacts[i].print();
            cout << "\n\n";
        }
    }
    
};


int main()
{
    Contact* contact1 = new Contact("Ivanov", "Ivan", "Ivanovich", 123456789, 987654321, 123123123);
    Contacts* phone = new Contacts();
    phone->printContacts();
    phone->addContact(*contact1);
    phone->addContact(Contact("Ivanov", "Ivan"));
    phone->printContacts();
    phone->deleteContact(1);
    phone->printContacts();
         
    phone->searchContacts("Ivanov", "Ivan");
    contact1->print();

    delete contact1;
    delete phone;
}