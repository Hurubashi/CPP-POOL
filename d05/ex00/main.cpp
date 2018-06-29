
#include "Bureaucrat.hpp"

int			main(void)
{
	Bureaucrat	obj1("Бюрократ Вася № 1", 150);
	Bureaucrat	obj2("Бюрократ Вася № 2", 1);

	try {
		Bureaucrat	obj3("Бюрократ Вася № 3", 151);
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}
	try {
		Bureaucrat	obj4("Бюрократ Вася № 4", 0);
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}
	try {
		obj1.decrementGrade();
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}
	try {
		obj2.incrementGrade();
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}

	std::cout << obj1 << std::endl;
	std::cout << obj2 << std::endl;

	return (0);
}
