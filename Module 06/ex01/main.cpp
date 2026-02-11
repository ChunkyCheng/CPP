#include "Serializer.hpp"
#include <iostream>
#include <climits>
#include <cfloat>

int	main(void)
{
	Data		data;
	Data		*data_ptr;
	uintptr_t	raw;
	Data		*deserialized;

	data_ptr = &data;
	data_ptr->c = 'A';
	data_ptr->i = INT_MAX;
	data_ptr->f = FLT_MIN;
	data_ptr->d = DBL_MAX;

	raw = Serializer::serialize(data_ptr);
	deserialized = Serializer::deserialize(raw);
	std::cout << "data_ptr: " << data_ptr << std::endl;
	std::cout << "serialized: " << raw << std::endl;
	std::cout << "deserialized: " << deserialized << std::endl;
	std::cout << "c: " << deserialized->c << std::endl;
	std::cout << "i: " << deserialized->i << std::endl;
	std::cout << "f: " << deserialized->f << std::endl;
	std::cout << "d: " << deserialized->d << std::endl;
}
