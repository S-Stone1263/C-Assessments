#include "String.h"
#include <iostream>
int main()
{
	String string1("Yo World");

	String string2(string1);
	int i = 1;

	std::cout << string1.Length() << " | " << string2.Length() << std::endl;

	return 0;

}