#include "String.h"
#include <iostream>




//Constructors and Destructors


// Default constructor
String::String()
{
	m_string = new char[1];
	char temp[15] = "Default String";
	m_string = new char[strlen(temp) + 1];
	strcpy_s(m_string, strlen(temp) + 1, temp);
}

// Constructor for defining class member when there is an existing string
String::String(const char* c)
{
	// dynamically allocating space for this object
	m_string = new char[strlen(c) + 1]; // size of string in parameter plus one for null terminator
	strcpy_s(m_string, strlen(c) + 1, c); //copy c char[] into member variable
}
// Copy constructor to copy an item from another class entity into this entity
String::String(String& st)
{
	m_string = new char[(strlen(st.m_string) + 1)];
	strcpy_s(m_string, strlen(st.m_string) + 1, st.m_string);


}

// Destructor
String::~String()
{
	std::cout << "Destructor Called" << std::endl;
	delete[] m_string;
}

// Functions


// Getting the length of the stored string
int String::Length()
{
	return strlen(m_string);
}

//Functions


//Comparing stored string to a character array and returning true of they the same and false if not
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

//Comparing stored string to another object of the string class and returning true of they the same and false if not
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

const char* String::Cstr()
{
	return m_string;
}