
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
	this->_target = "default";
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) :
		Form(obj.getName(), obj.getGradeToSign(), obj.getGradeToExecute())
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm 	& PresidentialPardonForm::operator= (const PresidentialPardonForm & form)
{
	Form::operator=(form);
	this->_target = form.getTarget();
	return (*this);
}

std::string		PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned()) {
		throw (NotSignedException());
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw (GradeTooLowException());
	}
	std::cout << this->getName() << " has been pardoned by Zafod Beebkerox." \
		  << std::endl;

}