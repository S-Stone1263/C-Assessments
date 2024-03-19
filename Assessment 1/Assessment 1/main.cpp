#include "String.h"
#include <iostream>

int main()
{
	String string1("Hello World");
	char test[16] = "HeLlO UnIVeRse";
	String string2("HElLo GalAxY");
	String string3(string1);
	char randomString[3] = "ll";

	std::cout << string1.Find(randomString) << std::endl;
	return 0;

}