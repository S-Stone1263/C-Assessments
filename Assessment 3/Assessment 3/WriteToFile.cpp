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





	std::fstream testLog;
	testLog.open("TestLog.txt", std::ios::app);

	testLog << " " << std::endl;
	if (month < 10)
	{
		testLog << "Date: " << day << "/0" << month << "/" << year;
	}
	else
	{
		testLog << "Date: " << day << "/" << month << "/" << year;
	}

	if (minute < 10 && sec < 10)
	{
		testLog << " Time: " << hour << ":0" << minute << ":0" << sec << std::endl;
	}
	else if (minute < 10)
	{
		testLog << " Time: " << hour << ":0" << minute << ":" << sec << std::endl;
	}
	else if (sec < 10)
	{
		testLog << " Time: " << hour << ":" << minute << ":0" << sec << std::endl;
	}
	else
	{
		testLog << " Time: " << hour << ":" << minute << ":" << sec << std::endl;
	}


	String string1("Hello");
	String string2(string1);
	String string3("Hello Galaxy");
	String string4;
	String string5("a");
	String string6("b");
	int successes = 0;

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
	testLog << "Test 1 Length: ";
	int realLength = string1.Length();
	if (expectedLength == realLength)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//Character at
	testLog << "Test 2 Character at: ";
	char realChar = string1.CharacterAt(0);
	if (expectedChar == realChar)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//Equal to
	testLog << "Test 3 Equal to: ";
	bool realEqual = string1.EqualTo(string2);
	if (expectedEqual == realEqual)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}


	//append
	testLog << "Test 4 Append: ";
	if (strcmp(string1.Append(string5).Cstr(), expectedAppend) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//prepend
	testLog << "Test 5 Prepend: ";
	if (strcmp(string1.Prepend(string5).Cstr(), expectedPrepend) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//CStr
	testLog << "Test 6 Cstr: ";
	if (strcmp(string1.Cstr(), expectedCStr) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//to lower
	testLog << "Test 7 To Lower: ";
	if (strcmp(string1.ToLower().Cstr(), expectedToLower) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//to upper
	testLog << "Test 8 To Upper: ";
	if (strcmp(string1.ToUpper().Cstr(), expectedToUpper) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//find string
	testLog << "Test 9 Find: ";
	if (expectedFind == string1.Find("l")[0])
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}



	//find from index
	testLog << "Test 10 Find from index: ";
	if (expectedFind2 == string1.Find("l", 3)[0])
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//replace
	testLog << "Test 11 Replace: ";
	if (strcmp(string1.Replace("l", "rr").Cstr(), expectedFind3) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//read from console
	testLog << "Test 12 Read: ";
	std::cout << "Enter 1 for number of words and sean for your word" << std::endl;
	if (strcmp(string4.ReadFromConsole(), expectedRead) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//write to console
	testLog << "Test 13 Write: ";
	string4.WriteToConsole();
	char userResult[4];
	std::cout << "Does the console output above read sean? (if so input yes, if not input no)" << std::endl;
	std::cin >> userResult;

	if (strcmp(userResult, expectedWrite) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}


	//equality operator
	testLog << "Test 14 Equality: ";
	bool equalityResult = string1 == string2;
	if (equalityResult == expectedEquality)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//subscript
	testLog << "Test 15 Subscript: ";
	if (string1[0] == 'H')
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//assign
	testLog << "Test 16 Assign: ";
	string1 = string3;
	if (strcmp(string1.Cstr(), expectedAssign) == 0)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}

	//Less than
	testLog << "Test 17 Less Than: ";
	bool lessThanResult = string5 < string6;
	if (lessThanResult == expectedLessThan)
	{
		testLog << "success" << std::endl;
		successes++;
	}
	else
	{
		testLog << "fail" << std::endl;
	}
	float successRate = ((successes / 17.0f) * 100);
	testLog << "There was a " << successRate << "% success rate" << std::endl;

	testLog.close();

	return 0;



}