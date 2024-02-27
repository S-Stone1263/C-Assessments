#pragma once
#include <iostream>
class String
{
private:

	//declaring a character pointer
	char* m_string;

public:
	String();
	String(const char* c);
	String(String& st);
	~String();

	int Length();

	bool EqualTo(const char* c);
	bool EqualTo(String& st);

	const char* Cstr();

	const char* Append(char* c);
	const char* Append(String& st);

	const char* Prepend(char* c);
	const char* Prepend(String& st);







};

