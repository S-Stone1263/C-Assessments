
#include "String.h"
#include <iostream>

int main()
{
	String string1("Hello World");
	char test[16] = "Hello Universe";
	String string2("Hello Galaxy");
	String string3(string1);

	std::cout << string1.Cstr() << std::endl;
	std::cout << string1.Prepend(string2) << std::endl;

	bool result = string1.EqualTo(string3);

	if (result == true)
	{
		std::cout << "They are the same" << std::endl;
	}
	else
	{
		std::cout << "They are different" << std::endl;
	}


	return 0;

}