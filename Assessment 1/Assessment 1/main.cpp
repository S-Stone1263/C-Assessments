
#include "String.h"
#include <iostream>
int main()
{
	String string1("Hello World");

	String string2;

	char test[16] = "HeLlO UnIVeRse";
	String string2("HElLo GalAxY");
	String string3(string1);

	bool result = string1.EqualTo(string2);
	std::cout << string1.Cstr() << std::endl;
	std::cout << string1.ToUpper(test) << std::endl;

	bool result = string1.EqualTo(string3);

	if (result == true)
	{
		std::cout << "The strings are the same" << std::endl;
		std::cout << "They are the same" << std::endl;
	}
	else
	{
		std::cout << "The strings are not the same" << std::endl;
		std::cout << "They are different" << std::endl;
	}

	std::cout << string1.Length() << " | " << string2.Length() << std::endl;



	std::cout << string1.Cstr() << " | " << string2.Cstr() << std::endl;

	return 0;

}