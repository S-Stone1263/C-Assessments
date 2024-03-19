#include "String.h"
#include <iostream>
#include <fstream>

//function declarations
void clearAndIgnore();
void consoleSpace();
void lengthOutput(String& string);
void characterOutput(String& string);
void classEqualToOutput(String& string1, String& string2);
void characterEqualToOutput(String& string1, char* string2);
void seeString(String& string);
void classAppendOutput(String& string1, String& string2);
void charAppendOutput(String& string1, char* string2);
void classPrependOutput(String& string1, String& string2);
void charPrependOutput(String& string1, char* string2);
void toLowerOutput(String& string);
void toUpperOutput(String& string);
void findOutput(String& string, const char* find);
void findFromIndex(String& string, const char* find, int index);
void findAndReplace(String& string, const char* find, const char* replace);
void readAndWrite(String& string);
void opOverloading(String& string1, String& string2);


int main()
{
	std::fstream testLog;
	testLog.open("TestLog.txt", std::ios::app);
	String string1("Hello World");
	String string2(string1);
	char string3[6] = "Howdy";
	String string4 = "Hello Galaxy";
	String string5 = "a";
	String string6 = "b";

	//console outputs
	lengthOutput(string1);
	consoleSpace();
	characterOutput(string1);
	consoleSpace();
	classEqualToOutput(string1, string2);
	consoleSpace();
	characterEqualToOutput(string1, string3);
	consoleSpace();
	seeString(string1);
	consoleSpace();
	classAppendOutput(string1, string2);
	consoleSpace();
	charAppendOutput(string2, string3);
	consoleSpace();
	classPrependOutput(string1, string2);
	consoleSpace();
	charPrependOutput(string2, string3);
	consoleSpace();
	toLowerOutput(string1);
	consoleSpace();
	toUpperOutput(string1);
	consoleSpace();
	findOutput(string1, "l");
	consoleSpace();
	findFromIndex(string1, "l", 3);
	consoleSpace();
	findAndReplace(string1, "l", "rr");
	consoleSpace();
	readAndWrite(string1);
	consoleSpace();
	opOverloading(string5, string6);

	//results of 1 or -1 whether the above functions succeed(1) or fail(-1)


	return 0;



}

//function definitions

//adding a blank line in the console for readability
void consoleSpace()
{
	std::cout << " " << std::endl;
}

//takes the argument of a string class and prints the length of the member string to the console
void lengthOutput(String& string)
{
	std::cout << "--- LENGTH FUNCTION ---" << std::endl;
	std::cout << "The length of this string is " << string.Length() << std::endl;
}

//takes a string class as argument and prints the character at a specific index to console
void characterOutput(String& string)
{
	std::cout << "--- CHARACTER AT FUNCTION ---" << std::endl;
	std::cout << "The character at the 4th index point is " << string.CharacterAt(4) << std::endl;
}

//takes 2 string classes as arguments and prints whether they are the same
void classEqualToOutput(String& string1, String& string2)
{
	std::cout << "--- EQUAL TO FUNCTION WITH STRING CLASS---" << std::endl;

	bool flag;
	flag = string1.EqualTo(string2);

	if (flag == true)
	{
		std::cout << "The default constructor " << string1.Cstr() << " and copy constructor " << string2.Cstr() << " are the same string" << std::endl;
	}
	if (flag == false)
	{
		std::cout << "The default constructor " << string1.Cstr() << " and copy constructor " << string2.Cstr() << " are different" << std::endl;
	}

}

//takes a string class and a character array as arguments and prints whether they are the same
void characterEqualToOutput(String& string1, char* string2)
{
	std::cout << "--- EQUAL TO FUNCTION WITH CHAR ARRAY---" << std::endl;

	bool flag;
	flag = string1.EqualTo(string2);

	if (flag == true)
	{
		std::cout << "The default constructor " << string1.Cstr() << " and " << string2 << " are the same string" << std::endl;
	}
	if (flag == false)
	{
		std::cout << "The default constructor " << string1.Cstr() << " and the other string " << string2 << " are different" << std::endl;
	}
}

//takes a string class and prints the current member string to console
void seeString(String& string)
{
	std::cout << "--- SEE STRING FUNCTION ---" << std::endl;
	std::cout << "The current string stored is " << string.Cstr() << std::endl;
}

//appends the characters of one member string to another member string with a space in between
void classAppendOutput(String& string1, String& string2)
{
	std::cout << "--- APPEND FUNCTION WITH TWO CLASSES ---" << std::endl;
	std::cout << "The appended string is " << string1.Append(string2) << std::endl;

}

//appends the characters of one member string to a char array with a space in between
void charAppendOutput(String& string1, char* string2)
{
	std::cout << "--- APPEND FUNCTION WITH CLASS AND CHAR ARRAY ---" << std::endl;
	std::cout << "The appended string is " << string1.Append(string2) << std::endl;
}

//prepends the characters of one member string to another member string with a space in between
void classPrependOutput(String& string1, String& string2)
{
	std::cout << "--- PREPEND FUNCTION WITH TWO CLASSES ---" << std::endl;
	std::cout << "The prepended string is " << string1.Prepend(string2) << std::endl;
}

//prepends the characters of one member string to a char array with a space in between
void charPrependOutput(String& string1, char* string2)
{
	std::cout << "--- PREPEND FUNCTION WITH CLASS AND CHAR ARRAY ---" << std::endl;
	std::cout << "The prepended string is " << string1.Prepend(string2) << std::endl;
}
//converts the characters of the string to lowercase
void toLowerOutput(String& string)
{
	std::cout << "--- TO LOWER FUNCTION ---" << std::endl;
	std::cout << "The member string " << string.Cstr() << " is " << string.ToLower() << " in lower case" << std::endl;
}

//converts the characters of the string to uppercase
void toUpperOutput(String& string)
{
	std::cout << "--- TO UPPER FUNCTION ---" << std::endl;
	std::cout << "The member string " << string.Cstr() << " is " << string.ToUpper() << " in upper case" << std::endl;
}
//finds the location of the find string within the main string
void findOutput(String& string, const char* find)
{
	std::cout << "--- FIND FUNCTION (searching for l) ---" << std::endl;
	int* matches = string.Find(find);
	if (string.GetNumMatches() > 0)
	{
		if (string.GetNumMatches() == 1)
		{
			std::cout << "The start of the match is at index position " << matches[0] << std::endl;
		}
		else
		{
			std::cout << "The start of the matches for l in the string " << string.Cstr() << " are at index positions ";
			for (int i = 0; i < string.GetNumMatches(); i++)
			{
				if (i == string.GetNumMatches() - 1)
				{
					std::cout << matches[i] << std::endl;
				}
				else
				{
					std::cout << matches[i] << " | ";
				}
			}
		}
	}
	else
	{
		std::cout << matches[0] << std::endl;
	}
}
//finds the location of the find string starting from a specific index
void findFromIndex(String& string, const char* find, int index)
{
	std::cout << "--- FIND FROM INDEX FUNCTION (searching for l from index 3) ---" << std::endl;
	int* matches = string.Find(find, index);
	if (string.GetNumMatches() > 0)
	{
		if (string.GetNumMatches() == 1)
		{
			std::cout << "The start of the match is at index position " << matches[0] << std::endl;
		}
		else
		{
			std::cout << "The start of the matches for l in the string " << string.Cstr() << " starting from index position 3 are at index positions ";
			for (int i = 0; i < string.GetNumMatches(); i++)
			{
				if (i == string.GetNumMatches() - 1)
				{
					std::cout << matches[i] << std::endl;
				}
				else
				{
					std::cout << matches[i] << " | ";
				}
			}
		}
	}
	else
	{
		std::cout << matches[0] << std::endl;
	}
}
//finds all instances of the find string and replaces it with the replace string
void findAndReplace(String& string, const char* find, const char* replace)
{
	std::cout << "--- FIND AND REPLACE FUNCTION (searching for l to replace with rr) ---" << std::endl;
	char* result = string.Find(find, replace);

	if (result[0] != '1')
	{
		std::cout << "The replaced string is now " << result << std::endl;
	}
	else
	{
		std::cout << -1 << std::endl;
	}

}
//reads in an input from the console and stores it in the member string, then writes it to the console
void readAndWrite(String& string)
{
	std::cout << "--- READ AND WRITE TO CONSOLE FUNCTIONS ---" << std::endl;
	string.ReadFromConsole();
	consoleSpace();
	std::cout << "The stored string has now been replaced with ";
	string.WriteToConsole();
}
//tests to ensure all operator overloading works correctly
void opOverloading(String& string1, String& string2)
{
	std::cout << "--- OPERATOR OVERLOADING FUNCTION (==, [], =, <) ---" << std::endl;
	std::cout << "Testing ==" << std::endl;
	if (string1 == string2)
	{
		std::cout << "String 1 is the same as string 2" << std::endl;
	}
	else
	{
		std::cout << "String 1 is different to string 2" << std::endl;
	}
	consoleSpace();

	std::cout << "Testing <" << std::endl;
	if (string1 < string2)
	{
		std::cout << "String 1 comes before string 2 alphabetically" << std::endl;
	}
	else
	{
		std::cout << "String 2 comes before string 1 alphabetically" << std::endl;
	}
	consoleSpace();


	std::cout << "Testing []" << std::endl;
	char subscriptCheck = string1[0];
	std::cout << "The character at the 0 index is " << subscriptCheck << std::endl;
	consoleSpace();

	std::cout << "Testing =" << std::endl;
	string1 = string2;
	std::cout << "The string has been changed to " << string1.Cstr() << std::endl;

}