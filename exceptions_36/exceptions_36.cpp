#include <iostream>
#include <vector>
#include "Exceptions.h"
using namespace std;



void PasswordValidation(string& password)
{
    bool super = false, lower = false, number = false, symbol = false;
    for (auto& c : password)
    {
        if (isupper(c))
            super = true;
        if (islower(c))
            lower = true;
        if (isdigit(c))
            number = true;
        if (!isalnum(c))
            symbol = true;
    }
	if (!super || !lower || !number || !symbol)
	{
		throw FormatPasswordException();
	}
}

class User_Account {
public:
    User_Account(string& login, string& password)
        :login(login), password(password)
    {}
    string getLogin() const { return login; }
	string getPassword() const { return password; }
	void setPassword(const string& pwd)
	{
		this->password = pwd;
	}
private:
    string login;
    string password;
};

class SocialNetwork {
private:
    vector<User_Account> accounts;
public:
    SocialNetwork() = default;
    void Register(string& login, string& password)
    {
        try
        {
            User_Account user(login, password);
            for (auto& u : accounts)
            {
                if(u.getLogin() == login)
                {
                    throw ExistLoginException();
                }
            }
			if (password.size() < 7)
			{
				throw FormatPasswordException();
			}
			PasswordValidation(password);
            accounts.push_back(user);
			cout << "Account " << login << " was succesfully created." << endl;
        }
        catch (const ExistLoginException& e)
        {
            cout << "Error: " << e.what() << endl;
        }
        catch (const FormatPasswordException& e)
        {
			cout << "Error: " << e.what() << endl;
        }
    }

    void Login(string& login, string& password)
    {
        try
		{
			for (auto& u : accounts)
			{
				if (u.getLogin() == login)
				{
					if (u.getPassword() == password)
					{
                        cout << "User " << login << " was succesfully logged in." << endl;
						return;
					}
					else
					{
						throw InvalidPasswordException();
					}
				}
			}
			throw InvalidLoginException();
		}
		catch (const InvalidLoginException& e)
		{
			cout << "Error: " << e.what() << endl;
		}
		catch (const InvalidPasswordException& e)
		{
			cout << "Error: " << e.what() << endl;
		}
    }

	void ChangePassword(string& login, string& old_password, string& new_password)
	{
        try
        {
            for (auto& u : accounts)
            {
                if (u.getLogin() == login)
                {
                    if (u.getPassword() == old_password)
                    {
                        PasswordValidation(new_password);
                        u.setPassword(new_password);
						cout << "Password for user " << login << " was succesfully changed." << endl;
                        return;
                    }
                    else
                    {
                        throw InvalidPasswordException();
                    }
                }
            }
            throw InvalidLoginException();
        }
        catch (const InvalidLoginException& e)
        {
            cout << "Error: " << e.what() << endl;
        }
        catch (const InvalidPasswordException& e)
        {
            cout << "Error: " << e.what() << endl;
        }
	}

    void Menu()
    {
        int choice;
        while (true)
        {
            cout << "[1] Register" << endl;
            cout << "[2] Login" << endl;
            cout << "[3] Change password" << endl;
            cout << "[0] Exit" << endl;
            cout << "Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "Register: " << endl;
                string login, password;
                cout << "Login: "; cin >> login;
                cout << "Password: "; cin >> password;
                Register(login, password);
                break;
            }
            case 2:
            {
                cout << "Login: " << endl;
                string login, password;
                cout << "Login: "; cin >> login;
                cout << "Password: "; cin >> password;
                Login(login, password);
                break;
            }
            case 3:
            {
                cout << "Change password: " << endl;
                string login, password_old, password_new;
                cout << "Login: "; cin >> login;
                cout << "Old password: "; cin >> password_old;
				cout << "New password: "; cin >> password_new;
                ChangePassword(login, password_old, password_new);
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
};

int main()
{
    SocialNetwork sn;
    string login1 = "Admin4ik";
    string password1 = "Qwerty1%";
    sn.Register(login1, password1);
    string login2 = "Admin4ik";
    string password2 = "Qwerty3#";
    sn.Register(login2, password2);
    sn.Menu();
}