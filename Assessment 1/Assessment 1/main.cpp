
#include "String.h"
#include <iostream>

int main()
{
	String string1("Hello World");
	char test[16] = "HeLlO UnIVeRse";
	String string2("HElLo GalAxY");
	String string3(string1);

	std::cout << string1.CharacterAt(6) << std::endl;
	std::cout << string1.Append(test) << std::endl;
	std::cout << string1.ToLower(test) << std::endl;
	std::cout << string1.Cstr() << std::endl;





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