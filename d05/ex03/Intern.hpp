
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern & intern);
	~Intern(void);
	Intern		& operator=(const Intern & intern);

	Form 	* makeForm(const std::string & formName, const std::string & formTarget);
	Form	* robotomy(const std::string & formTarget);
	Form	* shrubbery(const std::string & formTarget);
	Form	* presidential(const std::string & formTarget);
private:


};


#endif
