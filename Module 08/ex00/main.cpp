#include "easyfind.hpp"
#include <vector>
#include <deque>

int	main(void)
{
	int					arr[] = {1, 123, 125, 23, 5, 4, 234, 5};
	std::vector<int>	vector(arr, arr + sizeof(arr) / sizeof(arr[0]));

	print_container(vector) << std::endl;
	try
	{
		easyfind(vector, 5) = 10;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_container(vector) << std::endl;

	std::deque<int>	deque(vector.begin(), vector.end());
	print_container(deque) << std::endl;
	try
	{
		easyfind(deque, 5) = 10;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	print_container(deque) << std::endl;
}
