
#pragma once
#include <iostream>
class String
{
private:

	//declaring a character pointer
	char* m_string;

	//using this to store the number of matches from the find function for use in main file
	int m_numberOfMatches;

	//to make the find function operate as written without memory leaks, this member variable is needed to store the array
	int* m_matchIndex;
public:
	String();
	String(const char* c);
	String(const String& st);
	~String();

	int GetNumMatches();

	int Length();

	const char CharacterAt(int index);

	bool EqualTo(const char* c);
	bool EqualTo(String& st);

	const char* Cstr();

	String Append(char* c);
	String Append(String& st);

	String Prepend(char* c);
	String Prepend(String& st);

	String ToLower();
	String ToUpper();

	int* Find(const char* findstring);
	int* Find(const char* findstring, int index);
	String Replace(const char* findstring, const char* replacestring) const;

	const char* ReadFromConsole();
	void WriteToConsole();

	bool operator==(String& other);
	bool operator==(const char* other);

	const char operator[](int n);

	const char* operator=(const String& other);
	const char* operator=(const char* other);

	bool operator<(String& other);
};
