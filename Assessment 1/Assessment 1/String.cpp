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
	std::cout << "Destructor Called" << std::endl;
	delete[] m_string;
}

//functions


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


int String::Find(const char* findstring)
{
	int* matchIndexes;
	matchIndexes = new int[1];
	int numberOfMatches = 0;
	for (int i = 0; i < strlen(m_string); i++)
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

	if (numberOfMatches > 0)
	{
		return matchIndexes[0];
	}
	else
	{
		return -1;
	}
}

int String::Find(const char* findstring, int index)
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

	if (numberOfMatches > 0)
	{
		return matchIndexes[0];
	}
	else
	{
		return -1;
	}
}