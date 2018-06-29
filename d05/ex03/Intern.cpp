
#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern & intern)
{
	*this = intern;
	return ;
}

Intern::~Intern(void)
{
	return ;
}

Intern		& Intern::operator=(const Intern &)
{
	return (*this);
}

Form	* Intern::robotomy(const std::string & formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

Form	* Intern::shrubbery(const std::string & formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

Form	* Intern::presidential(const std::string & formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

Form 	* Intern::makeForm(const std::string & formName, const std::string & formTarget)
{
	const std::string	arr[] = {"robotomy request", "shrubbery request", "presidential request"};
	Form* (Intern::*f[])(const std::string & formTarget) =
			{ &Intern::robotomy, &Intern::shrubbery, &Intern::presidential};
	for (int i = 0; i < 3; i++) {
		if (arr[i].compare(formName) == 0) {
			std::cout << "Intern creates " << formName << std::endl;
			return ((Form*)(this->*f[i])(formTarget));
		}
	}
	std::cout << "I don't know this " << formName << std::endl;
	return (nullptr);
}
