
#include "String.h"
#include <iostream>
#include <fstream>




int main()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int sec = newtime.tm_sec;
	int minute = newtime.tm_min;
	int hour = newtime.tm_hour;
	int day = newtime.tm_mday;
	int month = 1 + newtime.tm_mon;
	int year = newtime.tm_year + 1900;

	std::cout << "Date: " << day << "/" << month << "/" << year << " Time: " << hour << ":" << minute << ":" << sec << std::endl;



	//std::fstream testLog;
	//testLog.open("TestLog.txt", std::ios::app);
	String string1("Hello");
	String string2(string1);
	String string3("Hello Galaxy");
	String string4;
	String string5("a");
	String string6("b");

	int expectedLength = 5;
	char expectedChar = 'H';
	bool expectedEqual = true;
	char expectedAppend[8] = "Hello a";
	char expectedPrepend[8] = "a Hello";
	char expectedCStr[6] = "Hello";
	char expectedToLower[6] = "hello";
	char expectedToUpper[6] = "HELLO";
	int expectedFind = 2;
	int expectedFind2 = 3;
	char expectedFind3[8] = "Herrrro";
	char expectedRead[] = "sean ";
	char expectedWrite[] = "yes";
	bool expectedEquality = true;
	char expectedSubscript = 'H';
	char expectedAssign[13] = "Hello Galaxy";
	bool expectedLessThan = true;

	//length
	int realLength = string1.Length();
	if (expectedLength == realLength)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//Character at
	char realChar = string1.CharacterAt(0);
	if (expectedChar == realChar)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//Equal to
	bool realEqual = string1.EqualTo(string2);
	if (expectedEqual == realEqual)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}


	//append
	if (strcmp(string1.Append(string5), expectedAppend) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//prepend
	if (strcmp(string1.Prepend(string5), expectedPrepend) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//CStr
	if (strcmp(string1.Cstr(), expectedCStr) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//to lower
	if (strcmp(string1.ToLower(), expectedToLower) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//to upper
	if (strcmp(string1.ToUpper(), expectedToUpper) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//find string
	if (expectedFind == string1.Find("l")[0])
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}



	//find from index
	if (expectedFind2 == string1.Find("l", 3)[0])
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//replace
	if (strcmp(string1.Find("l", "rr"), expectedFind3) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//read from console
	std::cout << "Enter 1 for number of words and sean for your word" << std::endl;
	if (strcmp(string4.ReadFromConsole(), expectedRead) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//write to console
	string4.WriteToConsole();
	char userResult[4];
	std::cout << "Does the console output above read sean? (if so input yes, if not input no)" << std::endl;
	std::cin >> userResult;

	if (strcmp(userResult, expectedWrite) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}


	//equality operator
	bool equalityResult = string1 == string2;
	if (equalityResult == expectedEquality)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//subscript
	if (string1[0] == 'H')
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//assign
	string1 = string3;
	if (strcmp(string1.Cstr(), expectedAssign) == 0)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	//Less than
	bool lessThanResult = string5 < string6;
	if (lessThanResult == expectedLessThan)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}

	return 0;



}
