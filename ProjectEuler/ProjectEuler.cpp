// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>


long long factorial(long long x)
{
	long long num = 1;
	for (int i = 1; i <= x; i++) num *= i;
	return num;	
}

long long sumFactorialsOfDigits(int x)
{
	std::string s = std::to_string(x);
	long long sum{0};
	for (int i = 0; i < s.size(); i++) sum += factorial(s[i]-'0');
	return sum;
}

bool isCuriousNumber(long long x)
{
	long long y = sumFactorialsOfDigits(x);
	return x == y;
}

int main() 
{
	long long largest=0;
	std::vector<long long> list;

	for (int i = 3; i < 1000000; i++)
	{
		if (isCuriousNumber(i))
		{
			std::cout << i<<"\n";
			list.push_back(i);
		}
	}
	int sum{0};
	for (int i = 0; i < list.size(); i++)
	{
		sum += list[i];
	}
	std::cout << sum;

}