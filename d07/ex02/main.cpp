
#include <iostream>
#include "Array.hpp"

int			main(void)
{
	Array<std::string> a(2);
	a._arr[0] = "Hello world0";
	a._arr[1] = "Hello world1";
	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;

	Array<std::string> b;
	b = a;
	a[0] = "San Sanych";
	a[1] = "Nataha";
	std::cout << b[0] << std::endl;
	std::cout << b[1] << std::endl;

	Array<std::string> c(b);
	b[0] = "Apple pen";
	b[1] = "Pine apple pen";
	std::cout << c[0] << std::endl;
	std::cout << c[1] << std::endl;

	try {
		std::cout << b[3] << std::endl;
	}
	catch (std::exception & exc) {
		std::cout << "Out of the limits" << std::endl;
	}
	return (0);
}