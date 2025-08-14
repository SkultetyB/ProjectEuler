// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>


int main()
{
	long long a = 0;
	long long b = 0;
	for (int i = 1; i < 101; i++)
	{
		a += pow(i,2);
		b += i;

	}
	b = pow(b,2);
	std::cout << a<<"\n";
	std::cout << b << "\n";

	std::cout << b - a;
}
 