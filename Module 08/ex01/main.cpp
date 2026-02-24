#include "Span.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

# define LARGE_SPAN_SIZE	10

int	main(void)
{
	std::srand(std::time(NULL));
	{
		int					arr[] = {6, 3, 17, 9, 11};
		std::vector<int>	vect(arr, arr + sizeof(arr) / sizeof(arr[0]));
		Span 				span(vect.begin(), vect.end());

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		span = Span(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		span = Span(6);
		span.addNumber(1);
		span.addNumber(2);
		span.addNumber(3);
		span.addNumber(4);
		span.addNumber(5);
		span.addNumber(6);
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	{
		std::list<int>	list;
		int				rnum;
		int				i;
		Span			span(0);

		i = 0;
		while (1)
		{
			rnum = std::rand() % 100;
			list.push_back(rnum);
			std::cerr << rnum;
			i++;
			if (i == LARGE_SPAN_SIZE)
				break ;
			std::cerr << ", ";
		}
		std::cout << std::endl;
		span = Span(list.begin(), list.end());
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
}
