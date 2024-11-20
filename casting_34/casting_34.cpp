#include <iostream>
#include <vector>
#include "Grandpa.h"
#include "Daddy.h"
#include "Son.h"

using namespace std;

void print(vector<Grandpa*> family)
{
	for (auto& item : family)
	{
		// method with using typeid
		/*item->Sleep();
		if (typeid(*item) == typeid(Daddy))
		{
			Daddy* res = static_cast<Daddy*>(item);
			res->Walk();
		}
		if (typeid(*item) == typeid(Son))
		{
			Son* res = static_cast<Son*>(item);
			res->Play();
		}*/

		// DYNAMIC CAST
		item->Sleep();
		Daddy* res = dynamic_cast<Daddy*>(item);
		if (res != nullptr)
		{
			res->Walk();
		}
		Son* rs = dynamic_cast<Son*>(item);
		if (rs != nullptr)
		{
			rs->Play();
		}
	}
}


int main()
{
	vector<Grandpa*> family{new Grandpa("Ivan"), new Daddy("Matviy"), new Son("Pavlo")};
	print(family);
}