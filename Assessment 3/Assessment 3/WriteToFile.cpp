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
	String string1("Hello World");
	String string2(string1);
	char string3[6] = "Howdy";
	String string4 = "Hello Galaxy";
	String string5 = "a";
	String string6 = "b";

	int expectedLength = 11;
	char expectedChar = 'H';
	bool expectedEqual = true;
	char expectedAppend[8] = "Hello a";
	char expectedPrepend[8] = "a Hello";
	char expectedCStr[6] = "Hello";
	char expectedToLower[6] = "hello";
	char expectedToUpper[6] = "HELLO";
	int expectedFind = 0;
	int expectedFind2 = 3;
	char expectedFind3[8] = "Herrrro";
	char expectedRead[] = "sean";
	char expectedWrite[] = "yes";
	bool expectedEqualituy = true;
	char expectedSubscript = 'H';
	char expectedAssign[13] = "Hello Galaxy";
	bool expectedLessThan = true;








		return 0;



}