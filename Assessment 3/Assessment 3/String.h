
#pragma once
#include <iostream>
class String
{
private:

	//declaring a character pointer
	char* m_string;

	//using this to store the number of matches from the find function for use in main file
	int m_numberOfMatches;

public:
	String();
	String(const char* c);
	String(String& st);
	~String();

	int GetNumMatches();

	int Length();

	const char CharacterAt(int index);

	bool EqualTo(const char* c);
	bool EqualTo(String& st);

	const char* Cstr();

	const char* Append(char* c);
	const char* Append(String& st);

	const char* Prepend(char* c);
	const char* Prepend(String& st);

	const char* ToLower();
	const char* ToUpper();

	int* Find(const char* findstring);
	int* Find(const char* findstring, int index);
	char* Find(const char* findstring, const char* replacestring);

	const char* ReadFromConsole();
	void WriteToConsole();

	bool operator==(String& other);
	bool operator==(const char* other);

	const char operator[](int n);

	const char* operator=(String& other);
	const char* operator=(const char* other);

	bool operator<(String& other);

};

