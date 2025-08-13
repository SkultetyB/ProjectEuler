// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool isPalindrom(int x)
{
	std::string str = std::to_string(x);
	int lengthOfNumber = str.length();
	for (int i = 0; i < lengthOfNumber-1; i++)
	{
		if (str[i] != str[lengthOfNumber - 1 - i])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	std::vector<int> list;
	for (int i = 100; i < 1000; i++)
	{

		for (int j = 100; j < 1000; j++)
		{
			
			if (isPalindrom(i*j) ==true)
			{
				std::cout << i*j << i << j << "\n";
				list.push_back(i * j);
			}
		}
	}
	int largest = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] > largest)
		{
			largest = list[i];
		}
	}
	std::cout << largest;	
}
 