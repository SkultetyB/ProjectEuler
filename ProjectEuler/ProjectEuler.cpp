// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::vector<int> list{ 1,2,3,2,5,7,2,3,11,13,2,17,19};
	long long num{1};
	for (int i = 0; i < list.size(); i++)
	{
		num *= list[i];	
	}
	if (num % 20 == 0)
	{
		std::cout << "good" << "\n";
	}
	else
	{
		std::cout << "bad" << "\n";
	}

	std::cout << num;
}
 