#include "String.h"
#include <iostream>




String::String()
{
	m_string = new char[1];
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

String::~String()
{
	std::cout << "Destructor Called" << std::endl;
	delete[] m_string;
}