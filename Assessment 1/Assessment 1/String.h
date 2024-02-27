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

	/*int Length();
	bool EqualTo(const char* c);
	bool EqualTo(String& st);
	const char* Cstr();


	 bool EqualTo(const char* c);
	bool EqualTo(String* st);
	void Append(const char* c);
	void Append(String* st);
	void Prepend(const char* c);
	void Prepend(String* st);*/

};

