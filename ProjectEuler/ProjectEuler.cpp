// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

 
int main()
{
    std::cout << "Give me a large number:";
    long long n; 
    std::cin >> n;

    //long long n = 600851475143;
    long long factor = 2;
    long long largest = 0;

    while (n > 1)
    {
        if (n % factor == 0)
        {
            largest = factor;
            n = n / factor;
        }
        else
        {
            if (factor % 2 == 0)
            {
                factor++;
            }
            else
            {
                factor += 2;
            }
        }
    }
    std::cout << largest;
}
 