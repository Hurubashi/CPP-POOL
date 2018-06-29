
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int			main(void)
{
	std::cout << "************** ShrubberyCreationForm ****************"<<std::endl<<std::endl;

	Bureaucrat bur("Бюрократ Андрей", 145);
	ShrubberyCreationForm shr	("Shrubbery_form");
	bur.signForm(shr);
	bur.executeForm(shr);

	Bureaucrat bur2("Бюрократ Андрей2", 137);
	bur2.signForm(shr);
	bur2.executeForm(shr);

	std::cout << std::endl;
	std::cout << "****************** RobotomyRequestForm ***************"<<std::endl<<std::endl;

	Bureaucrat bur3("Бюрократ Николай", 72);
	RobotomyRequestForm rob("Robot_form");
	bur3.signForm(rob);
	bur3.executeForm(rob);

	Bureaucrat bur4("Бюрократ Николай2", 45);
	bur4.signForm(rob);
	bur4.executeForm(rob);

	std::cout << std::endl;
	std::cout << "***************** PresidentialPardonForm **************"<<std::endl<<std::endl;

	Bureaucrat	bur5("Бюрократ Василий", 25);
	PresidentialPardonForm		president_form("president_form");
	bur5.signForm(president_form);
	bur5.executeForm(president_form);

	Bureaucrat	bur6("Бюрократ Василий2", 5);
	bur6.signForm(president_form);
	bur6.executeForm(president_form);
}
