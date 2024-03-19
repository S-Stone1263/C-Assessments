#include "String.h"
#include <iostream>

//query error thrown by prepend when taking in the member of an object
//query whether it is more appropriate to use references or pointers

//constructors and Destructors


//default constructor
String::String()
{
	char temp[15] = "Default String";
	m_string = new char[strlen(temp) + 1];
	strcpy_s(m_string, strlen(temp) + 1, temp);

}

//constructor for defining class member when there is an existing string
String::String(const char* c)
{
	// dynamically allocating space for this object
	m_string = new char[strlen(c) + 1]; // size of string in parameter plus one for null terminator
	strcpy_s(m_string, strlen(c) + 1, c); //copy c char[] into member variable

}

//copy constructor to copy an item from another class entity into this entity
String::String(String& st)
{
	m_string = new char[(strlen(st.m_string) + 1)];
	strcpy_s(m_string, strlen(st.m_string) + 1, st.m_string);

}
//destructor
String::~String()
{
	delete[] m_string;
}

//functions

// clear and ignore invalid inputs
void clearAndIgnore()
{
	std::cout << "Invalid input, try again" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}


//getting the length of the stored string
int String::Length()
{
	return strlen(m_string);
}

const char String::CharacterAt(int index)
{
	char invalidReturn = '\0';
	if (index < 0 || index > strlen(m_string) - 1)
	{
		return invalidReturn;
	}
	else
	{
		return m_string[index];
	}

}



//comparing stored string to a character array and returning true of they the same and false if not
bool String::EqualTo(const char* c)
{
	if (strcmp(m_string, c) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//comparing stored string to another object of the referenced string class and returning true of they the same and false if not
bool String::EqualTo(String& st)
{
	if (strcmp(m_string, st.m_string) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//returns the current string
const char* String::Cstr()
{
	return m_string;
}
//adds the argument to the end of the current string
const char* String::Append(char* c)
{
	char space[2] = " ";
	//Using a variable to store string length
	int strLength = strlen(space) + strlen(m_string) + 1;
	//Creating a temporary dynamic character array to store the current string with enough room to append the new string onto
	char* append;
	char* append2;
	append = new char[strLength];

	//Adding a space to the current array
	strcpy_s(append, strLength, m_string);
	strcat_s(append, strLength, space);

	//Updating string length and creating another array for storing the member variable, space and the character array
	strLength = strlen(append) + strlen(c) + 1;
	append2 = new char[strLength];
	//
	strcpy_s(append2, strLength, append);
	strcat_s(append2, strLength, c);
	return append2;
	delete[] append;
	delete[] append2;

}

//same as previous append using a string object instead of char array
const char* String::Append(String& st)
{
	char space[2] = " ";
	int strLength = strlen(space) + strlen(m_string) + 1;
	char* append;
	char* append2;
	append = new char[strLength];

	strcpy_s(append, strLength, m_string);
	strcat_s(append, strLength, space);

	strLength = strlen(append) + strlen(st.m_string) + 1;
	append2 = new char[strLength];

	strcpy_s(append2, strLength, append);
	strcat_s(append2, strLength, st.m_string);
	return append2;
	delete[] append;
	delete[] append2;

}

//similar to append however with the one key difference that the character array argument is copied into the temp array first
const char* String::Prepend(char* c)
{
	char space[2] = " ";
	int strLength = strlen(space) + strlen(c) + 1;
	char* prepend;
	char* prepend2;
	prepend = new char[strLength];

	strcpy_s(prepend, strLength, c);
	strcat_s(prepend, strLength, space);

	strLength = strlen(prepend) + strlen(m_string) + 1;
	prepend2 = new char[strLength];

	strcpy_s(prepend2, strLength, prepend);
	strcat_s(prepend2, strLength, m_string);
	return prepend2;
	delete[] prepend;
	delete[] prepend2;

}

const char* String::Prepend(String& st)
{
	char space[2] = " ";
	int strLength = strlen(space) + strlen(st.m_string) + 1;
	char* prepend;
	char* prepend2;
	prepend = new char[strLength];

	strcpy_s(prepend, strLength, st.m_string);
	strcat_s(prepend, strLength, space);

	strLength = strlen(prepend) + strlen(m_string) + 1;
	prepend2 = new char[strLength];

	strcpy_s(prepend2, strLength, prepend);
	strcat_s(prepend2, strLength, m_string);
	return prepend2;
	delete[] prepend;
	delete[] prepend2;

}

//using c++ functionality to convert current string into lowercase
const char* String::ToLower()
{
	char* lower = new char[strlen(m_string) + 1];
	strcpy_s(lower, strlen(m_string) + 1, m_string);

	for (int i = 0; i < strlen(m_string); i++)
	{
		int letter = 0;
		letter = lower[i];
		lower[i] = tolower(letter);

	}
	return lower;
	delete[] lower;
}

//using c++ functionality to convert current string into uppercase
const char* String::ToUpper()
{
	char* upper = new char[strlen(m_string) + 1];
	strcpy_s(upper, strlen(m_string) + 1, m_string);

	for (int i = 0; i < strlen(m_string); i++)
	{
		int letter = 0;
		letter = upper[i];
		upper[i] = tolower(letter);

	}
	return upper;
	delete[] upper;
}

//creating a function to find if a particular string is contained within the stored member string

void String::Find(const char* findstring)
{
	//creating a new array to store the positions of the matched string
	int* matchIndexes;
	matchIndexes = new int[1];
	int numberOfMatches = 0;

	for (int i = 0; i < strlen(m_string); i++) //starting a loop to check every letter of the member string against the first letter of the input string
	{
		if (m_string[i] == findstring[0]) //if a match is found it begins to check the circumstances of the match
		{
			if (strlen(findstring) > 1) //if the inputted string is larger than one character it enters the following loop to compare the subsequent characters in each string
			{
				for (int j = 1; j < strlen(findstring); j++)
				{
					if (findstring[j] != m_string[i + j])
					{
						j = strlen(findstring); //if not matching this breaks the loop
					}
					if (j == (strlen(findstring) - 1)) //if all characters match, it will enter the following to store the position
					{
						if (numberOfMatches == 0) //for the first match it simply creates the array of appropriate size and stores the current position in it
						{
							numberOfMatches++;
							matchIndexes = new int[numberOfMatches + 1];
							matchIndexes[numberOfMatches - 1] = i;
						}
						else //for subsequent matches, a temporary array is used to store the current values, so that the original array can be appropriately resized and then store all current values
						{
							numberOfMatches++;
							int* temp = new int[numberOfMatches + 1];
							for (int i = 0; i < numberOfMatches - 1; i++)
							{
								temp[i] = matchIndexes[i];
							}

							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches];

							for (int i = 0; i < numberOfMatches; i++)
							{
								matchIndexes[i] = temp[i];
							}
							delete[] temp;
						}
					}
				}
			}
			else //if the input is only one character it only checks the one character and then operates the same as before for storage of the index
			{
				if (numberOfMatches == 0)
				{
					numberOfMatches++;
					matchIndexes = new int[numberOfMatches];
					matchIndexes[numberOfMatches - 1] = i;
				}
				else
				{
					numberOfMatches++;
					int* temp = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches - 1; i++)
					{
						temp[i] = matchIndexes[i];
					}

					temp[numberOfMatches - 1] = i;

					delete[] matchIndexes;
					matchIndexes = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches; i++)
					{
						matchIndexes[i] = temp[i];
					}
					delete[] temp;
				}
			}



		}
	}

	//printing to the console the positions of the matches if there are any
	if (numberOfMatches > 0)
	{
		if (numberOfMatches == 1)
		{
			std::cout << "The start of the match is at index position " << matchIndexes[0] << std::endl;
		}
		else
		{
			std::cout << "The start of the matches are at ";
			for (int i = 0; i < numberOfMatches; i++)
			{
				std::cout << matchIndexes[i] << " | ";
			}
		}
	}
	else
	{
		std::cout << "There are no matches";
	}

	delete[] matchIndexes;
}

//operates exactly as the function above however the loop begins from the index 
void String::Find(const char* findstring, int index)
{
	int* matchIndexes;
	matchIndexes = new int[1];
	int numberOfMatches = 0;
	for (int i = index; i < strlen(m_string); i++)
	{
		if (m_string[i] == findstring[0])
		{
			if (strlen(findstring) > 1)
			{
				for (int j = 1; j < strlen(findstring); j++)
				{
					if (findstring[j] != m_string[i + j])
					{
						j = strlen(findstring);
					}
					if (j == (strlen(findstring) - 1))
					{
						if (numberOfMatches == 0)
						{
							numberOfMatches++;
							matchIndexes = new int[numberOfMatches + 1];
							matchIndexes[numberOfMatches - 1] = i;
						}
						else
						{
							numberOfMatches++;
							int* temp = new int[numberOfMatches + 1];
							for (int i = 0; i < numberOfMatches - 1; i++)
							{
								temp[i] = matchIndexes[i];
							}

							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches];

							for (int i = 0; i < numberOfMatches; i++)
							{
								matchIndexes[i] = temp[i];
							}
							delete[] temp;
						}
					}
				}
			}
			else
			{
				if (numberOfMatches == 0)
				{
					numberOfMatches++;
					matchIndexes = new int[numberOfMatches];
					matchIndexes[numberOfMatches - 1] = i;
				}
				else
				{
					numberOfMatches++;
					int* temp = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches - 1; i++)
					{
						temp[i] = matchIndexes[i];
					}

					temp[numberOfMatches - 1] = i;

					delete[] matchIndexes;
					matchIndexes = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches; i++)
					{
						matchIndexes[i] = temp[i];
					}
					delete[] temp;
				}
			}



		}
	}

	if (numberOfMatches > 0)
	{
		if (numberOfMatches == 1)
		{
			std::cout << "The start of the match is at index position " << matchIndexes[0] << std::endl;
		}
		else
		{
			std::cout << "The start of the matches are at ";
			for (int i = 0; i < numberOfMatches; i++)
			{
				std::cout << matchIndexes[i] << " | ";
			}
		}
	}
	else
	{
		std::cout << "There are no matches";
	}

	delete[] matchIndexes;
}

//exactly the same as the first original find function except after storing the variables the function continues

void String::Find(const char* findstring, const char* replacestring)
{
	//creating a new array to store the positions of the matched string
	int* matchIndexes;
	matchIndexes = new int[1];
	int numberOfMatches = 0;

	for (int i = 0; i < strlen(m_string); i++) //starting a loop to check every letter of the member string against the first letter of the input string
	{
		if (m_string[i] == findstring[0]) //if a match is found it begins to check the circumstances of the match
		{
			if (strlen(findstring) > 1) //if the inputted string is larger than one character it enters the following loop to compare the subsequent characters in each string
			{
				for (int j = 1; j < strlen(findstring); j++)
				{
					if (findstring[j] != m_string[i + j])
					{
						j = strlen(findstring); //if not matching this breaks the loop
					}
					if (j == (strlen(findstring) - 1)) //if all characters match, it will enter the following to store the position
					{
						if (numberOfMatches == 0) //for the first match it simply creates the array of appropriate size and stores the current position in it
						{
							numberOfMatches++;
							matchIndexes = new int[numberOfMatches + 1];
							matchIndexes[numberOfMatches - 1] = i;
						}
						else //for subsequent matches, a temporary array is used to store the current values, so that the original array can be appropriately resized and then store all current values
						{
							numberOfMatches++;
							int* temp = new int[numberOfMatches + 1];
							for (int i = 0; i < numberOfMatches - 1; i++)
							{
								temp[i] = matchIndexes[i];
							}

							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches];

							for (int i = 0; i < numberOfMatches; i++)
							{
								matchIndexes[i] = temp[i];
							}
							delete[] temp;
						}
					}
				}
			}
			else //if the input is only one character it only checks the one character and then operates the same as before for storage of the index
			{
				if (numberOfMatches == 0)
				{
					numberOfMatches++;
					matchIndexes = new int[numberOfMatches];
					matchIndexes[numberOfMatches - 1] = i;
				}
				else
				{
					numberOfMatches++;
					int* temp = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches - 1; i++)
					{
						temp[i] = matchIndexes[i];
					}

					temp[numberOfMatches - 1] = i;

					delete[] matchIndexes;
					matchIndexes = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches; i++)
					{
						matchIndexes[i] = temp[i];
					}
					delete[] temp;
				}
			}



		}
	}


	//loops throgh the matches index to find the position at which a character needs replacing
	int difference;
	if (strlen(replacestring) > strlen(findstring))
	{
		difference = (strlen(replacestring) - strlen(findstring));
		char* replacedString = new char[strlen(m_string) + (numberOfMatches * difference) + 1];
		int currentMatch = 0;

		for (int i = 0; i < strlen(m_string) + (numberOfMatches * difference) + 1; i++)
		{
			if (i == matchIndexes[currentMatch])
			{
				for (int j = 0; j < strlen(replacestring); j++)
				{
					replacedString[i + j] = replacestring[j];
				}

				i = i + difference;
				if (currentMatch < numberOfMatches)
				{
					currentMatch++;
				}

				for (int j = 0; j < numberOfMatches; j++)
				{
					matchIndexes[j] = matchIndexes[j] + difference;
				}
			}
			else
			{
				int currentDiff;
				if (currentMatch == 0)
				{
					currentDiff = 0;
				}
				else
				{
					currentDiff = currentMatch * difference;
				}
				replacedString[i] = m_string[i - currentDiff];
			}

		}

		std::cout << replacedString << std::endl;
		delete[] replacedString;
		delete[] matchIndexes;
	}
	else if (strlen(replacestring) < strlen(findstring))
	{
		difference = (strlen(replacestring) - strlen(findstring));
		char* replacedString = new char[strlen(m_string) - (numberOfMatches * difference) + 1];
		int currentMatch = 0;

		for (int i = 0; i < strlen(m_string) - (numberOfMatches * difference) + 1; i++)
		{
			if (i == matchIndexes[currentMatch])
			{
				for (int j = 0; j < strlen(replacestring); j++)
				{
					replacedString[i + j] = replacestring[j];
				}

				i = i + difference;
				if (currentMatch < numberOfMatches)
				{
					currentMatch++;
				}

				for (int j = 0; j < numberOfMatches; j++)
				{
					matchIndexes[j] = matchIndexes[j] - difference;
				}
			}
			else
			{
				int currentDiff;
				if (currentMatch == 0)
				{
					currentDiff = 0;
				}
				else
				{
					currentDiff = currentMatch * difference;
				}
				replacedString[i] = m_string[i + currentDiff];
			}

		}

		std::cout << replacedString << std::endl;
		delete[] replacedString;
		delete[] matchIndexes;
	}
	else
	{
		difference = 0;
		char* replacedString = new char[strlen(m_string) + (numberOfMatches * difference) + 1];
		int currentMatch = 0;

		for (int i = 0; i < strlen(m_string) + (numberOfMatches * difference) + 1; i++)
		{
			if (i == matchIndexes[currentMatch])
			{
				for (int j = 0; j < strlen(replacestring); j++)
				{
					replacedString[i + j] = replacestring[j];
				}

				i = i + difference;
				if (currentMatch < numberOfMatches)
				{
					currentMatch++;
				}

				for (int j = 0; j < numberOfMatches; j++)
				{
					matchIndexes[j] = matchIndexes[j] + difference;
				}
			}
			else
			{
				int currentDiff;
				if (currentMatch == 0)
				{
					currentDiff = 0;
				}
				else
				{
					currentDiff = currentMatch * difference;
				}
				replacedString[i] = m_string[i - currentDiff];
			}

		}

		std::cout << replacedString << std::endl;
		delete[] replacedString;
		delete[] matchIndexes;
	}


}

//reads an input from the console and stores it in an appropriately sized array
const char* String::ReadFromConsole()
{

	int numberOfWords;
	int inputCheck;
	bool flag = true;


	while (flag)
	{
		std::cout << "How many words is your string?" << std::endl;
		std::cin >> inputCheck;

		if (std::cin.fail() || inputCheck < 0)
		{
			clearAndIgnore();
		}
		else
		{
			numberOfWords = inputCheck;
			flag = false;
		}
	}




	for (int i = 0; i < numberOfWords; i++)
	{
		if (i == 0)
		{
			char temp[50];
			std::cout << "Enter the first word of the string" << std::endl;
			std::cin >> temp;
			delete[] m_string;
			m_string = new char[strlen(temp) + 2];
			for (int i = 0; i < strlen(temp) + 1; i++)
			{
				m_string[i] = temp[i];
			}

			strcat_s(m_string, strlen(temp) + 2, " ");
		}
		else if (i == numberOfWords - 1)
		{
			char temp[50];
			std::cout << "Enter the last word of the string" << std::endl;
			std::cin >> temp;

			char* stringHold = new char[strlen(temp) + 1];

			for (int i = 0; i < strlen(temp) + 1; i++)
			{
				stringHold[i] = temp[i];
			}

			char* memberHold = new char[strlen(m_string) + 1];
			strcpy_s(memberHold, strlen(m_string) + 1, m_string);

			delete[] m_string;
			m_string = new char[strlen(memberHold) + strlen(stringHold) + 1];

			strcpy_s(m_string, strlen(memberHold) + strlen(stringHold) + 1, memberHold);

			strcat_s(m_string, strlen(memberHold) + strlen(stringHold) + 1, stringHold);

			delete[] memberHold;
			delete[] stringHold;
		}
		else
		{
			char temp[50];
			std::cout << "Enter the next word of the string" << std::endl;
			std::cin >> temp;

			char* stringHold = new char[strlen(temp) + 1];

			for (int i = 0; i < strlen(temp) + 1; i++)
			{
				stringHold[i] = temp[i];
			}

			char* memberHold = new char[strlen(m_string) + 1];
			strcpy_s(memberHold, strlen(m_string) + 1, m_string);

			delete[] m_string;
			m_string = new char[strlen(memberHold) + strlen(stringHold) + 2];

			strcpy_s(m_string, strlen(memberHold) + strlen(stringHold) + 2, memberHold);

			strcat_s(m_string, strlen(memberHold) + strlen(stringHold) + 2, stringHold);

			strcat_s(m_string, strlen(memberHold) + strlen(stringHold) + 2, " ");

			delete[] memberHold;
			delete[] stringHold;
		}
	}

	return m_string;

}

//writes the current member string to the console
void String::WriteToConsole()
{
	std::cout << m_string << std::endl;
}


bool String::operator==(String& other)
{
	int result;
	result = strcmp(m_string, other.m_string);
	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator==(const char* other)
{
	int result;
	result = strcmp(m_string, other);
	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


const char String::operator[](int n)
{
	return m_string[n];
}

const char* String::operator=(String& other)
{
	delete[] m_string;
	m_string = new char[strlen(other.m_string) + 1];
	strcpy_s(m_string, strlen(other.m_string) + 1, other.m_string);

	return m_string;
}

const char* String::operator=(const char* other)
{
	delete[] m_string;
	m_string = new char[strlen(other) + 1];
	strcpy_s(m_string, strlen(other) + 1, other);

	return m_string;
}

bool String::operator<(String& other)
{
	if (strcmp(m_string, other.m_string) == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}