#pragma once
#include <iostream>
using std::exception;

class ExistLoginException : public exception
{
public:
	const char* what() const
	{
		return "Login already exists.";
	}
};

class InvalidLoginException : public exception
{
public:
	const char* what() const
	{
		return "Invalid login.";
	}
};

class InvalidPasswordException : public exception
{
public:
	const char* what() const
	{
		return "Invalid password.";
	}
};

class FormatPasswordException : public exception
{
public:
	const char* what() const
	{
		return "Password must contain at least 7 characters, a 1 lower case, a 1 super case, a 1 number and 1 symbol.";
	}
};


class UserNotLoggedException : public exception
{
public:
	const char* what() const
	{
		return "User not logged.";
	}
};