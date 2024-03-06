#include <chrono>
#include <iostream>
#include <ctime>

int main()
{
	

	bool flag = true;
	char input = 45;
	//these lines get the number of seconds since JAN 1 1970 (will use this for an everchanging seed for rand)
	auto time = std::chrono::system_clock::now();
	int seed = std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
	srand(seed);
	char letter = rand() % 25 + 97;
	std::cout << letter << std::endl;
	
	std::cout << "QUICK YOU'RE FALLING, PRESS "<< letter <<" THEN ENTER" << std::endl;
	int attempts = 0;
	auto start_time = std::chrono::high_resolution_clock::now();
	
	while (input != letter)
	{
		if (attempts == 0)
		{
			std::cin >> input;
		}
		else
		{
			std::cout << "WRONG LETTER, ENTER " << letter << " THEN ENTER" << std::endl;
			std::cin >> input;
		}
		attempts++;
	}
	
	auto current_time = std::chrono::high_resolution_clock::now();
	auto stopTime = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
	auto fallDistance = (((9.8 * (stopTime/1000)) / 2) * (stopTime/1000)); 
	std::cout << "You fell " << fallDistance << " metres, ouch!" << std::endl;
	//std::cout << fallDistance << std::endl;

	return 0;
}