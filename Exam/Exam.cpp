#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person(const char* name)
        :name(nullptr)
    {
        if (name != nullptr) {
            size_t length = strlen(name) + 1;
            this->name = new char[length];
            strcpy_s(this->name, length, name);
        }
    }

    Person(const Person& other)
        :name(nullptr)
    {
        if (other.name != nullptr) {
            size_t length = strlen(other.name) + 1;
            this->name = new char[length];
            strcpy_s(this->name, length, other.name);
        }
    }

    void print() const
    {
        cout << "Name: " << name << endl;
    }

    ~Person()
    {
        delete[] name;
    }

private:
    char* name = nullptr;
};


int main()
{
    Person user("Oleksandr");
    user.print();
    Person user2(user);
    user2.print();
}