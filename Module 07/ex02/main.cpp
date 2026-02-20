#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

static void separator(const std::string& title)
{
    std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}

int main(void)
{
    std::srand(time(NULL));
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	separator("Size Check");
	if (numbers.size() != MAX_VAL)
		std::cout << "Wrong size!" << std::endl;
	else
		std::cout << "Success" << std::endl;

	separator("Copy Assignment and Copy Constructor Test");
    {
        Array<int> tmp1 = numbers;
		Array<int> tmp2(tmp1);
		if (tmp1.size() != numbers.size() || tmp2.size() != numbers.size())
			std::cout << "Copied array has different size!" << std::endl;
		for (int i = 0; i < MAX_VAL; ++i)
		{
			if (tmp1[i] != numbers[i] || tmp2[i] != numbers[i])
			{
				std::cout << "Copied array has different value!" << std::endl;
				return (1);
			}
		}
		std::cout << "Success" << std::endl;
		separator("Deep copy check");
		tmp1[0] += 1;
		tmp2[MAX_VAL - 1] += 1;
		if (tmp1[0] == numbers[0] || tmp2[MAX_VAL - 1] == numbers[MAX_VAL - 1])
			std::cout << "Copied array is not a deep copy!" << std::endl;
		else
			std::cout << "Success" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
		{
            std::cout << "failed" << std::endl;
			return (1);
		}
    }

	separator("Invalid Index Test 1");
    try
    {
        numbers[-2] = 0;
		std::cout << "Failed" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		std::cout << "Exception caught, Passed" << std::endl;
    }
	
	separator("Invalid Index Test 2");
    try
    {
        numbers[MAX_VAL] = 0;
		std::cout << "Failed" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
		std::cout << "Exception caught, Passed" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    delete [] mirror;
}
