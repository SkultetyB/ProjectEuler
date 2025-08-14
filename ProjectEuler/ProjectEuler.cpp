// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

bool isPrime(long long x) {
	if (x < 2) return false;
	if (x % 2 == 0) return x == 2;
	for (long long d = 3; d <= x / d; d += 2) {
		if (x % d == 0) return false;
	}
	return true;
}


int main() {
    const int TARGET = 10001;

    long long last = 2;     // we already count 2
    int primeCounter = 1;   // 2 is the first prime
    long long candidate = 3;

    while (primeCounter < TARGET) {
        if (isPrime(candidate)) {
            last = candidate;
            ++primeCounter;
        }
        candidate += 2; // next odd
    }

    std::cout << last << "\n"; // 104743
}