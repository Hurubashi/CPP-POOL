
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int			main(void)
{
	Intern	in;
	Form * f1 = in.makeForm("robotomy request" , "Home");
	std::cout << *f1 << std::endl;

	std::cout << std::endl;

	Form * f2 = in.makeForm("shrubbery request" , "Work");
	std::cout << *f2 << std::endl;

	std::cout << std::endl;

	Form * f3 = in.makeForm("presidential request" , "School");
	std::cout << *f3 << std::endl;

	std::cout << std::endl;
	in.makeForm("error request" , "error");

	return (0);
}
