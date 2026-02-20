#include <cctype>
#include <cstring>
#include <iostream>
#include "iter.hpp"

static void	rot13(char &c)
{
	unsigned char	out;

	out = c;
	if (!std::isalpha(out))
		return ;
	if (std::isupper(out))
	{
		out += 13;
		if (out > 'Z')
			out -= 26;
	}
	else
	{
		out += 13;
		if (out > 'z')
			out -= 26;
	}
	c = out;
}

int	main(void)
{
	char	arr1[] = "Vitamin C";
	int		arr2[] = {10, 12, 5, 47};
	long	arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	print_array(&arr1) << std::endl;
	print_array(&arr2) << std::endl;
	print_array(&arr3) << std::endl;
	iter(&arr1, rot13);
	iter(&arr2, cube);
	iter(&arr3, cube);
	print_array(&arr1) << std::endl;
	print_array(&arr2) << std::endl;
	print_array(&arr3) << std::endl;
}
