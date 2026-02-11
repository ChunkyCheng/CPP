#include <ctime>
#include <cstdlib>
#include "Base.hpp"

int	main(void)
{
	Base	*ptr;

	std::srand(std::time(NULL));
	ptr = Base::generate();
	Base::identify(ptr);
	Base::identify(*ptr);
	delete ptr;
}
