
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string & name);
	RobotomyRequestForm(const RobotomyRequestForm & form);
	~RobotomyRequestForm(void);
	RobotomyRequestForm		& operator=(const RobotomyRequestForm & form);

	std::string		getTarget(void) const;

	void 		execute(Bureaucrat const & executor) const;

public:
	std::string		_target;
};


#endif
