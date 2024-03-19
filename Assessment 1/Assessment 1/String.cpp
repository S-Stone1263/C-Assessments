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

	m_appended = new char[strlen(temp) + 1];
	strcpy_s(m_appended, strlen(temp) + 1, temp);

	m_prepended = new char[strlen(temp) + 1];
	strcpy_s(m_prepended, strlen(temp) + 1, temp);
}

//constructor for defining class member when there is an existing string
String::String(const char* c)
{
	// dynamically allocating space for this object
	m_string = new char[strlen(c) + 1]; // size of string in parameter plus one for null terminator

	strcpy_s(m_string, strlen(c) + 1, c); //copy c char[] into member variable

	m_appended = new char[strlen(c) + 1];

	strcpy_s(m_appended, strlen(c) + 1, c);

	m_prepended = new char[strlen(c) + 1];

	strcpy_s(m_prepended, strlen(c) + 1, c);
}

//copy constructor to copy an item from another class entity into this entity
String::String(String& st)
{
	m_string = new char[(strlen(st.m_string) + 1)];
	strcpy_s(m_string, strlen(st.m_string) + 1, st.m_string);

	m_appended = new char[(strlen(st.m_appended) + 1)];
	strcpy_s(m_appended, strlen(st.m_appended) + 1, st.m_appended);

	m_prepended = new char[(strlen(st.m_prepended) + 1)];
	strcpy_s(m_prepended, strlen(st.m_prepended) + 1, st.m_prepended);


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

	strcpy_s(append2, strLength, append);
	strcat_s(append2, strLength, c);

	//deleting the current string array
	delete[] m_appended;

	//creating a new appended array of required size
	m_appended = new char[strLength];

	//copying appended string into member variable and deleting the temporary arrays
	strcpy_s(m_appended, strLength, append2);
	delete[] append;
	delete[] append2;
	return m_appended;
}

//same as previous append
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

	delete[] m_appended;

	m_appended = new char[strLength];

	strcpy_s(m_appended, strLength, append2);
	delete[] append;
	delete[] append2;
	return m_appended;
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

	delete[] m_prepended;

	m_prepended = new char[strLength];

	strcpy_s(m_prepended, strLength, prepend2);
	delete[] prepend;
	delete[] prepend2;
	return m_prepended;
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

	delete[] m_prepended;

	m_prepended = new char[strLength];

	strcpy_s(m_prepended, strLength, prepend2);
	delete[] prepend;
	delete[] prepend2;
	return m_prepended;
}

const char* String::ToLower(char* c)
{
	for (int i = 0; i < strlen(c); i++)
	{
		int letter = 0;
		letter = c[i];
		c[i] = tolower(letter);

	}

	delete[] m_string;
	m_string = new char[strlen(c) + 1];
	strcpy_s(m_string, strlen(c) + 1, c);
	return m_string;
}

const char* String::ToLower(String& st)
{

	int strLength = strlen(st.m_string);

	for (int i = 0; i < strlen(st.m_string); i++)
	{
		int letter = 0;
		letter = st.m_string[i];
		st.m_string[i] = tolower(letter);

	}

	delete[] m_string;
	m_string = new char[strlen(st.m_string) + 1];
	strcpy_s(m_string, strLength + 1, st.m_string);
	return m_string;
}

const char* String::ToUpper(char* c)
{
	for (int i = 0; i < strlen(c); i++)
	{
		int letter = 0;
		letter = c[i];
		c[i] = toupper(letter);

	}

	delete[] m_string;
	m_string = new char[strlen(c) + 1];
	strcpy_s(m_string, strlen(c) + 1, c);
	return m_string;
}

const char* String::ToUpper(String& st)
{
	int strLength = strlen(st.m_string);

	for (int i = 0; i < strlen(st.m_string); i++)
	{
		int letter = 0;
		letter = st.m_string[i];
		st.m_string[i] = toupper(letter);

	}

	delete[] m_string;
	m_string = new char[strlen(st.m_string) + 1];
	strcpy_s(m_string, strLength + 1, st.m_string);
	return m_string;
}