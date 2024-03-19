#include "String.h"
#include <iostream>


//constructors and Destructors


//default constructor
String::String()
{
	char temp[15] = "Default String";
	m_string = new char[strlen(temp) + 1];
	strcpy_s(m_string, strlen(temp) + 1, temp);
	m_numberOfMatches = 0;
	m_matchIndex = new int[1];
	m_matchIndex[0] = -1;
}

//constructor for defining class member when there is an existing string
String::String(const char* c)
{
	// dynamically allocating space for this object
	m_string = new char[strlen(c) + 1]; // size of string in parameter plus one for null terminator
	strcpy_s(m_string, strlen(c) + 1, c); //copy c char[] into member variable
	m_numberOfMatches = 0;
	m_matchIndex = new int[1];
	m_matchIndex[0] = -1;

}

//copy constructor to copy an item from another class entity into this entity
String::String(const String& st)
{
	m_string = new char[(strlen(st.m_string) + 1)];
	strcpy_s(m_string, strlen(st.m_string) + 1, st.m_string);
	m_numberOfMatches = 0;
	m_matchIndex = new int[1];
	m_matchIndex[0] = -1;

}
//destructor
String::~String()
{
	delete[] m_string;
	delete[] m_matchIndex;
}

//functions

// clear and ignore invalid inputs
void clearAndIgnore()
{
	std::cout << "Invalid input, try again" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

int String::GetNumMatches()
{
	return m_numberOfMatches;
}

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
String String::Append(char* c)
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
	//
	strcpy_s(append2, strLength, append);
	strcat_s(append2, strLength, c);

	delete[] append;
	String temp(append2);
	delete[] append2;
	return temp;
}

//same as previous append using a string object instead of char array
String String::Append(String& st)
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

	delete[] append;
	String temp(append2);
	delete[] append2;
	return temp;

}

//similar to append however with the one key difference that the character array argument is copied into the temp array first
String String::Prepend(char* c)
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

	delete[] prepend;
	String temp(prepend2);
	delete[] prepend2;
	return temp;
}

String String::Prepend(String& st)
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

	delete[] prepend;
	String temp(prepend2);
	delete[] prepend2;
	return temp;
}

//using c++ functionality to convert current string into lowercase
String String::ToLower()
{
	char* lower = new char[strlen(m_string) + 1];
	strcpy_s(lower, strlen(m_string) + 1, m_string);

	for (int i = 0; i < strlen(m_string); i++)
	{
		int letter = 0;
		letter = lower[i];
		lower[i] = tolower(letter);

	}

	String temp(lower);
	delete[] lower;
	return temp;
}

//using c++ functionality to convert current string into uppercase
String String::ToUpper()
{
	char* upper = new char[strlen(m_string) + 1];
	strcpy_s(upper, strlen(m_string) + 1, m_string);

	for (int i = 0; i < strlen(m_string); i++)
	{
		int letter = 0;
		letter = upper[i];
		upper[i] = toupper(letter);

	}

	String temp(upper);
	delete[] upper;
	return temp;

}

//creating a function to find if a particular string is contained within the stored member string

int* String::Find(const char* findstring)
{
	//creating a new array to store the positions of the matched string
	int* matchIndexes;
	matchIndexes = new int[1];
	matchIndexes[0] = -1;
	int numberOfMatches = 0;

	for (int i = 0; i < strlen(m_string); i++) //starting a loop to check every letter of the member string against the first letter of the input string
	{
		if (m_string[i] == findstring[0]) //if a match is found it begins to check the circumstances of the match
		{
			if (strlen(findstring) > 1) //if the inputted string is larger than one character it enters the following loop to compare the subsequent characters in each string
			{
				for (int j = 1; j < strlen(findstring); j++)
				{
					if (findstring[j] != m_string[i + j])
					{
						j = strlen(findstring); //if not matching this breaks the loop
					}
					if (j == (strlen(findstring) - 1)) //if all characters match, it will enter the following to store the position
					{
						if (numberOfMatches == 0) //for the first match it simply creates the array of appropriate size and stores the current position in it
						{
							numberOfMatches++;
							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches + 1];
							matchIndexes[numberOfMatches - 1] = i;
						}
						else //for subsequent matches, a temporary array is used to store the current values, so that the original array can be appropriately resized and then store all current values
						{
							numberOfMatches++;
							int* temp = new int[numberOfMatches + 1];
							for (int i = 0; i < numberOfMatches - 1; i++)
							{
								temp[i] = matchIndexes[i];
							}

							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches];

							for (int i = 0; i < numberOfMatches; i++)
							{
								matchIndexes[i] = temp[i];
							}
							delete[] temp;
						}
					}
				}
			}
			else //if the input is only one character it only checks the one character and then operates the same as before for storage of the index
			{
				if (numberOfMatches == 0)
				{
					delete[] matchIndexes;
					numberOfMatches++;
					matchIndexes = new int[numberOfMatches];
					matchIndexes[numberOfMatches - 1] = i;
				}
				else
				{
					numberOfMatches++;
					int* temp = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches - 1; i++)
					{
						temp[i] = matchIndexes[i];
					}

					temp[numberOfMatches - 1] = i;

					delete[] matchIndexes;
					matchIndexes = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches; i++)
					{
						matchIndexes[i] = temp[i];
					}
					delete[] temp;
				}
			}



		}
	}
	delete[] m_matchIndex;
	m_matchIndex = new int[numberOfMatches];

	m_numberOfMatches = numberOfMatches;
	for (int i = 0; i < numberOfMatches; i++)
	{
		m_matchIndex[i] = matchIndexes[i];
	}
	delete[] matchIndexes;
	return m_matchIndex;
}

//operates exactly as the function above however the loop begins from the index 
int* String::Find(const char* findstring, int index)
{
	int* matchIndexes;
	matchIndexes = new int[1];
	matchIndexes[0] = -1;
	int numberOfMatches = 0;
	for (int i = index; i < strlen(m_string); i++)
	{
		if (m_string[i] == findstring[0])
		{
			if (strlen(findstring) > 1)
			{
				for (int j = 1; j < strlen(findstring); j++)
				{
					if (findstring[j] != m_string[i + j])
					{
						j = strlen(findstring);
					}
					if (j == (strlen(findstring) - 1))
					{
						if (numberOfMatches == 0)
						{
							numberOfMatches++;
							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches + 1];
							matchIndexes[numberOfMatches - 1] = i;
						}
						else
						{
							numberOfMatches++;
							int* temp = new int[numberOfMatches + 1];
							for (int i = 0; i < numberOfMatches - 1; i++)
							{
								temp[i] = matchIndexes[i];
							}

							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches];

							for (int i = 0; i < numberOfMatches; i++)
							{
								matchIndexes[i] = temp[i];
							}
							delete[] temp;
						}
					}
				}
			}
			else
			{
				if (numberOfMatches == 0)
				{
					delete[] matchIndexes;
					numberOfMatches++;
					matchIndexes = new int[numberOfMatches];
					matchIndexes[numberOfMatches - 1] = i;
				}
				else
				{
					numberOfMatches++;
					int* temp = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches - 1; i++)
					{
						temp[i] = matchIndexes[i];
					}

					temp[numberOfMatches - 1] = i;

					delete[] matchIndexes;
					matchIndexes = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches; i++)
					{
						matchIndexes[i] = temp[i];
					}
					delete[] temp;
				}
			}



		}
	}
	delete[] m_matchIndex;
	m_matchIndex = new int[numberOfMatches];

	m_numberOfMatches = numberOfMatches;
	for (int i = 0; i < numberOfMatches; i++)
	{
		m_matchIndex[i] = matchIndexes[i];
	}
	delete[] matchIndexes;
	return m_matchIndex;
}

//exactly the same as the first original find function except after storing the variables the function continues

String String::Replace(const char* findstring, const char* replacestring) const
{
	int* matchIndexes;
	matchIndexes = new int[1];
	matchIndexes[0] = -1;
	int numberOfMatches = 0;

	for (int i = 0; i < strlen(m_string); i++)
	{
		if (m_string[i] == findstring[0])
		{
			if (strlen(findstring) > 1)
			{
				for (int j = 1; j < strlen(findstring); j++)
				{
					if (findstring[j] != m_string[i + j])
					{
						j = strlen(findstring);
					}
					if (j == (strlen(findstring) - 1))
					{
						if (numberOfMatches == 0)
						{
							numberOfMatches++;
							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches + 1];
							matchIndexes[numberOfMatches - 1] = i;
						}
						else
						{
							numberOfMatches++;
							int* temp = new int[numberOfMatches + 1];
							for (int i = 0; i < numberOfMatches - 1; i++)
							{
								temp[i] = matchIndexes[i];
							}

							delete[] matchIndexes;
							matchIndexes = new int[numberOfMatches];

							for (int i = 0; i < numberOfMatches; i++)
							{
								matchIndexes[i] = temp[i];
							}
							delete[] temp;
						}
					}
				}
			}
			else
			{
				if (numberOfMatches == 0)
				{
					numberOfMatches++;
					delete[] matchIndexes;
					matchIndexes = new int[numberOfMatches];
					matchIndexes[numberOfMatches - 1] = i;
				}
				else
				{
					numberOfMatches++;
					int* temp = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches - 1; i++)
					{
						temp[i] = matchIndexes[i];
					}

					temp[numberOfMatches - 1] = i;

					delete[] matchIndexes;
					matchIndexes = new int[numberOfMatches];

					for (int i = 0; i < numberOfMatches; i++)
					{
						matchIndexes[i] = temp[i];
					}
					delete[] temp;
				}
			}



		}
	}

	if (matchIndexes[0] != -1) //checking if there are any matches of the string to find within the member string
	{
		int difference; //creating a variable to store the difference in size between find and replace strings

		if (strcmp(findstring, m_string) == 0) //Testing to see if the string to find is the entirety of the string
		{
			char* replacedString = new char[strlen(replacestring) + 1]; //initialise new array of appropriate size
			strcpy_s(replacedString, strlen(replacestring) + 1, replacestring); //copy the replacestring
			String temp(replacedString);
			delete[] replacedString;
			delete[] matchIndexes;
			return temp;
		}

		else if (strlen(replacestring) > strlen(findstring)) // enter this section if the replacement string is longer than the string found
		{
			difference = (strlen(replacestring) - strlen(findstring)); //setting the difference to use throughout this code
			char* replacedString = new char[strlen(m_string) + (numberOfMatches * difference) + 1];
			int currentMatch = 0; //Setting what match from the indexes was previously replaced

			for (int i = 0; i < strlen(m_string) + (numberOfMatches * difference) + 1; i++) //entering a for loop to fill the dynamically allocated array
			{
				if (i == matchIndexes[currentMatch]) //checking if the current index is where the find string was found
				{
					for (int j = 0; j < strlen(replacestring); j++) //looping through the length of the replace string to fill the array
					{
						replacedString[i + j] = replacestring[j];
					}

					i = i + difference + (strlen(findstring) - 1); //skipping through the index to avoid overwriting the previous filled data
					if (currentMatch < numberOfMatches)
					{
						currentMatch++; //setting the current match to one as one has now been replaced
					}

					for (int j = 0; j < numberOfMatches; j++)
					{
						matchIndexes[j] = matchIndexes[j] + difference; //changing the position of where the index will be found as the current array is now larger than the original
					}
				}
				else
				{
					int currentDiff;
					if (currentMatch == 0)
					{
						currentDiff = 0;
					}
					else
					{
						currentDiff = currentMatch * difference;
					}
					replacedString[i] = m_string[i - currentDiff];
				}

			}
			String temp(replacedString);
			delete[] replacedString;
			delete[] matchIndexes;
			return temp;
		}
		else if (strlen(replacestring) < strlen(findstring)) //enter this if the replacestring is shorter than the findstring
		{
			difference = (strlen(findstring) - strlen(replacestring));
			char* replacedString = new char[strlen(m_string) - (numberOfMatches * difference) + 1];
			replacedString[strlen(m_string) - (numberOfMatches * difference)] = '\0'; //setting the last character to the NULL TERMINATOR
			int currentMatch = 0;
			for (int i = 0; i < strlen(m_string) - (numberOfMatches * difference); i++) //filling the replaced string
			{
				replacedString[i] = '_';
			}

			for (int i = 0; i < strlen(m_string) - (numberOfMatches * difference) + 1; i++)
			{
				if (i == matchIndexes[currentMatch])
				{
					for (int j = 0; j < strlen(replacestring); j++)
					{
						replacedString[i + j] = replacestring[j]; //filling the dynamic array at the correct index with the entirety of the replace string
					}
					currentMatch++;
					i = i + strlen(replacestring) - 1; //stepping through the index the correct amount to ensure no overwriting
				}
				else if (currentMatch == 0)
				{
					replacedString[i] = m_string[i];
				}
				else
				{
					replacedString[i] = m_string[i + (currentMatch * difference)]; //filling the array with the original string using the correct character from the original string as the i value changes every match
				}
			}
			String temp(replacedString);
			delete[] replacedString;
			delete[] matchIndexes;
			return temp;
		}
		else //enters this if the find string and replace string and operates the same as above except it doesnt have to step through the indexes as the arrays are the same size
		{
			difference = 0;
			char* replacedString = new char[strlen(m_string) + 1];
			replacedString[strlen(m_string)] = '\0';
			int currentMatch = 0;
			for (int i = 0; i < strlen(m_string) - (numberOfMatches * difference); i++)
			{
				replacedString[i] = '_';
			}

			for (int i = 0; i < strlen(m_string) + (numberOfMatches * difference); i++)
			{
				if (i == matchIndexes[currentMatch])
				{
					for (int j = 0; j < strlen(replacestring); j++)
					{
						replacedString[i + j] = replacestring[j];
					}

					i = i + difference + (strlen(findstring) - 1);
					if (currentMatch < numberOfMatches)
					{
						currentMatch++;
					}

					for (int j = 0; j < numberOfMatches; j++)
					{
						matchIndexes[j] = matchIndexes[j] + difference;
					}
				}
				else
				{
					int currentDiff;
					if (currentMatch == 0)
					{
						currentDiff = 0;
					}
					else
					{
						currentDiff = currentMatch * difference;
					}
					replacedString[i] = m_string[i - currentDiff];
				}

			}
			String temp(replacedString);
			delete[] replacedString;
			delete[] matchIndexes;
			return temp;

		}
	}
	else
	{
		delete[] matchIndexes;
		String temp("-1");
		return temp;
	}


}

//reads an input from the console and stores it in m_string
const char* String::ReadFromConsole()
{
	//initialising variables to have a secure input
	int numberOfWords;
	int inputCheck;
	bool flag = true;


	while (flag) //using a boolean to keep looping through until the condition is satisfied
	{
		std::cout << "How many words is your string?" << std::endl; //asking the user for how many words their string is
		std::cin >> inputCheck; //input storage while the check for validity runs

		if (std::cin.fail() || inputCheck < 0) //checking if the input is an integer and is above 0
		{
			clearAndIgnore(); //clears the read buffer and then ignores the error to continue the input loop
		}
		else //if the input is valid the number of words is set to the input check and the loop is broken by changing the boolean
		{
			numberOfWords = inputCheck;
			flag = false;
		}
	}




	for (int i = 0; i < numberOfWords; i++) //starts a loop for the number of words the user wishes to input
	{
		if (i == 0)
		{
			char temp[50]; //setting a temporary array to store the input in

			//prompting the user and taking in the input
			std::cout << "Enter the first word of the string" << std::endl;
			std::cin >> temp;

			//deleting the current member string and replacing it with the first word of the new string
			delete[] m_string;
			m_string = new char[strlen(temp) + 2];
			for (int i = 0; i < strlen(temp) + 1; i++)
			{
				m_string[i] = temp[i];
			}

			strcat_s(m_string, strlen(temp) + 2, " "); //adding a space at the end of the word as inputs cannot read whitespace
		}
		else if (i == numberOfWords - 1) //Storing the last word of the string
		{
			char temp[50];
			std::cout << "Enter the last word of the string" << std::endl;
			std::cin >> temp;

			char* stringHold = new char[strlen(temp) + 1];

			for (int i = 0; i < strlen(temp) + 1; i++)
			{
				stringHold[i] = temp[i];
			}
			//does not add a space at the end as it would be wasted space

			//creating a variable to hold the member variable so that it can be resized to hold the new word to be concatenated onto it
			char* memberHold = new char[strlen(m_string) + 1];
			strcpy_s(memberHold, strlen(m_string) + 1, m_string);

			delete[] m_string;
			m_string = new char[strlen(memberHold) + strlen(stringHold) + 1];

			strcpy_s(m_string, strlen(memberHold) + strlen(stringHold) + 1, memberHold);

			strcat_s(m_string, strlen(memberHold) + strlen(stringHold) + 1, stringHold);

			delete[] memberHold;
			delete[] stringHold;
		}
		else //storing the middle words of the string
		{
			char temp[50];
			std::cout << "Enter the next word of the string" << std::endl;
			std::cin >> temp;

			char* stringHold = new char[strlen(temp) + 1];

			for (int i = 0; i < strlen(temp) + 1; i++)
			{
				stringHold[i] = temp[i];
			}

			char* memberHold = new char[strlen(m_string) + 1];
			strcpy_s(memberHold, strlen(m_string) + 1, m_string);

			delete[] m_string;
			m_string = new char[strlen(memberHold) + strlen(stringHold) + 2];

			strcpy_s(m_string, strlen(memberHold) + strlen(stringHold) + 2, memberHold);

			strcat_s(m_string, strlen(memberHold) + strlen(stringHold) + 2, stringHold);

			strcat_s(m_string, strlen(memberHold) + strlen(stringHold) + 2, " ");

			delete[] memberHold;
			delete[] stringHold;
		}
	}

	return m_string;

}

//writes the current member string to the console
void String::WriteToConsole()
{
	std::cout << m_string << std::endl;
}


bool String::operator==(String& other) //operator overloading that compares LHS to RHS using strcmp
{
	int result;
	result = strcmp(m_string, other.m_string);
	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool String::operator==(const char* other)
{
	int result;
	result = strcmp(m_string, other);
	if (result == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


const char String::operator[](int n) //returning the character at the nth index
{
	return m_string[n];
}

const char* String::operator=(const String& other) //setting LHS equal to RHS using strcpy_s
{
	delete[] m_string;
	m_string = new char[strlen(other.m_string) + 1];
	strcpy_s(m_string, strlen(other.m_string) + 1, other.m_string);

	return m_string;
}

const char* String::operator=(const char* other)
{
	delete[] m_string;
	m_string = new char[strlen(other) + 1];
	strcpy_s(m_string, strlen(other) + 1, other);

	return m_string;
}

bool String::operator<(String& other) //returning true or false whether the string comes before or after the other string alphabetically
{
	if (strcmp(m_string, other.m_string) == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}