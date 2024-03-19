#pragma once
#include <iostream>
class String
{
private:

	//declaring a character pointer
	char* m_string;
	char* m_appended;
	char* m_prepended;

public:
	String();
	String(const char* c);
	String(String& st);
	~String();

	int Length();

	const char CharacterAt(int index);

	bool EqualTo(const char* c);
	bool EqualTo(String& st);

	const char* Cstr();

	const char* Append(char* c);
	const char* Append(String& st);

	const char* Prepend(char* c);
	const char* Prepend(String& st);

	const char* ToLower(char* c);
	const char* ToLower(String& st);

	const char* ToUpper(char* c);
	const char* ToUpper(String& st);





};

