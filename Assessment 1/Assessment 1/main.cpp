#include "String.h"
#include <iostream>

int main()
{
	String string1("Yo World");

	String string2(string1);


	String string3(string1);

		bool result = string1.EqualTo(string2);
		if (result == true)
		{
			std::cout << "The strings are the same" << std::endl;
		}
		else
		{
			std::cout << "The strings are not the same" << std::endl;
		}

		std::cout << string1.Length() << " | " << string2.Length() << std::endl;



		std::cout << string1.Cstr() << " | " << string2.Cstr() << std::endl;

		return 0;

}