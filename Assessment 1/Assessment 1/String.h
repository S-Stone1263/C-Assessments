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

	int Find(const char* findstring);
	int Find(const char* findstring, int index)




		void Find(const char* findstring);
	void Find(const char* findstring, int index);
	const char* Find(const char* findstring, const char* replacestring);

	const char* ReadFromConsole();
	void WriteToConsole();

};

