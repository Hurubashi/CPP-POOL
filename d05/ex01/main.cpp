
#include "Bureaucrat.hpp"
#include "Form.hpp"

int			main(void)
{
	Bureaucrat	bur("Bureaucrat", 50);
	Form		form1("form1", 50, 40);
	Form		form2("form2", 60, 70);

	try {
		Form	form3("form3", 50, 151);
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}
	try {
		Form	form4("form4", 155, 15);
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}
	try {
		Form	form5("form5", 140, 0);
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}
	try {
		Form	form6("form6", 0, 15);
	}
	catch (std::exception & exp) {
		std::cout << exp.what() << std::endl;
	}
	bur.signForm(form1);
	bur.signForm(form2);
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	return (0);
}
