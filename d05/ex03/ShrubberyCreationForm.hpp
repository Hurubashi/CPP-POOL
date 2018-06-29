
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"
#include "fstream"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string & target);
	ShrubberyCreationForm(const ShrubberyCreationForm & obj);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm 	& operator=(const ShrubberyCreationForm  & obj);

	std::string		getTarget(void) const;

	void 		execute(Bureaucrat const & executor) const;

public:
	std::string		_target;
};


#endif
