#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int	main(void)
{
	Base	*ptr;

	std::srand(std::time(0));

	for (int i = 0; i < 10; i++)
	{
		ptr = generate();

		std::cout << "identify pointer:   ";
		identify(ptr);

		std::cout << "identify reference: ";
		identify(*ptr);

		delete ptr;
		std::cout << std::endl;
	}

	return (0);
}