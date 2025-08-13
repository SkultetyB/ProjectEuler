// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Vector
{

};


int main()
{
    int sum = 0;
    int current = 8;
    int prev = 5;
    int temp;
    while (current <= 4000000)
    {
        if (current % 2 == 0)
        {
            sum += current;
        }
        temp = prev;
        prev = current;
        current += temp;
    }

    std::cout << sum + 2;
}
