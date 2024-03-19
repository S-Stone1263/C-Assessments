#include "String.h"
#include <iostream>


int main()
{
	String string1("Hello");
	String string2("Hello Galaxy");

	std::cout << string1.Find("Hell", "COD") << std::endl;

	return 0;



}