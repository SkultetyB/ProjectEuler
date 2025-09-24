// ProjectEuler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

const std::string baseString =	"73167176531330624919225119674426574742355349194934"
								"96983520312774506326239578318016984801869478851843"
								"85861560789112949495459501737958331952853208805511"
								"12540698747158523863050715693290963295227443043557"
								"66896648950445244523161731856403098711121722383113"
								"62229893423380308135336276614282806444486645238749"
								"30358907296290491560440772390713810515859307960866"
								"70172427121883998797908792274921901699720888093776"
								"65727333001053367881220235421809751254540594752243"
								"52584907711670556013604839586446706324415722155397"
								"53697817977846174064955149290862569321978468622482"
								"83972241375657056057490261407972968652414535100474"
								"82166370484403199890008895243450658541227588666881"
								"16427171479924442928230863465674813919123162824586"
								"17866458359124566529476545682848912883142607690042"
								"24219022671055626321111109370544217506941658960408"
								"07198403850962455444362981230987879927244284909188"
								"84580156166097919133875499200524063689912560717606"
								"05886116467109405077541002256983155200055935729725"
								"71636269561882670428252483600823257530420752963450";



std::vector<long long>& MakeListOf13DigitNumbers(const std::string& input)
{
	std::vector<long long> listof_numbers;
	std::string str = "";

	for (int i = 0; i < input.length()-14; i++)
	{
		str.push_back(input.at(i));
		for (int j = 1; j < 13; j++)
		{
			str.push_back(input.at(i+j));
		}
		listof_numbers.push_back(std::stoll(str));
		str = "";
	}
	return listof_numbers;
}

std::vector<long long>& FindNumbersWithZeroInThemFromList(std::vector<long long> numbers)
{
	std::vector<long long> numbersToDeleteFromList;
	for (long long number : numbers)
	{
		
		std::string str="";
		str = std::to_string(number);
		for (int i = 0; i < (int)str.length(); i++)
		{
			if (str[i]-'0' == 0)
			{
				numbersToDeleteFromList.push_back(number);
			}
		}
	}
	return numbersToDeleteFromList;
}

std::vector<long long> DeleteListOfNumbersFromList(std::vector<long long>& NumbersToDelete,std::vector<long long>& Numbers)
{
	std::unordered_set<long long> toDel(NumbersToDelete.begin(), NumbersToDelete.end());
	Numbers.erase(
		std::remove_if(Numbers.begin(), Numbers.end(),
					   [&](long long x){ return toDel.count(x) != 0; }),
		Numbers.end()
	);
	return Numbers;
}

long long ProductOfDigits(long long number)
{
	long long sum = 1;
	std::string stringAsNumber = std::to_string(number);
	for (int i = 0; i < stringAsNumber.length(); i++)
	{
		sum *= stringAsNumber[i]-'0';
	}
	return sum;
}

std::vector<long long > TurnListsElementsIntoTheProductOfTheirDigits(std::vector<long long> numbers)
{
	std::vector<long long> newNums;
	for (int i = 0; i < numbers.size(); i++)
	{
		newNums.push_back(ProductOfDigits(numbers[i])); 
	}
	return newNums;
}

long long FindLargestNumberInList(std::vector<long long> numbers)
{
	long long largest = numbers[0];
	for (long long number : numbers)
	{
		largest = std::max(number, largest);
	}
	return largest;
}

int main() 
{


	std::vector<long long> v = MakeListOf13DigitNumbers(baseString);
	std::vector<long long> vD = FindNumbersWithZeroInThemFromList(v);
	DeleteListOfNumbersFromList(vD, v);
	v = TurnListsElementsIntoTheProductOfTheirDigits(v);
	std::cout << FindLargestNumberInList(v)<< std::endl;
	
	//This does not work:
	// std::cout <<FindLargestNumberInList( TurnListsElementsIntoTheProductOfTheirDigits(DeleteListOfNumbersFromList(FindNumbersWithZeroInThemFromList(MakeListOf13DigitNumbers(baseString)), MakeListOf13DigitNumbers(baseString))))<< std::endl;
}