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
	String(String& st);
	~String();

	int Length();

	bool EqualTo(const char* c);
	bool EqualTo(String& st);

	const char* Cstr();

	const char* Append(char* c);
	const char* Append(String& st);

	bool EqualTo(const char* c);
	bool EqualTo(String* st);
	const char* Prepend(char* c);
	const char* Prepend(String& st);

	void Append(const char* c);
	void Append(String* st);
	const char* ToLower(char* c);
	const char* ToLower(String& st);

	void Prepend(const char* c);
	void Prepend(String* st);


	const char* ToUpper(char* c);
	const char* ToUpper(String& st);



};

