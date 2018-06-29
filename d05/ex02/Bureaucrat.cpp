
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name(name), _grade(grade) {
	if (grade <= 0) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	else
		this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
	this->_grade = copy._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

Bureaucrat		& Bureaucrat::incrementGrade(void) {
	if (this->_grade <= 1) {
		throw (GradeTooHighException());
	}
	else {
		this->_grade = this->_grade - 1;
	}
	return (*this);
}

Bureaucrat		& Bureaucrat::decrementGrade(void) {
	if (this->_grade >= 150) {
		throw (GradeTooLowException());
	}
	else {
		this->_grade = this->_grade + 1;
	}
	return (*this);
}

const char 		*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Слишком большая оценка ...");
}

const char 		*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Слишком маленькая оценка ...");
}

void			Bureaucrat::signForm(Form & obj)
{
	try {
		obj.beSigned(*this);
		std::cout << this->_name << " подписывает " << obj.getName() << std::endl;
	}
	catch (std::exception & exp) {
		std::cout << this->_name << " не может подписать. " << obj.getName();
		std::cout << " Пата мушта " << exp.what() << std::endl;
	}
}

std::ostream	& operator<< (std::ostream & out, const Bureaucrat & obj) {
	out << obj.getName() << ", получил оценку " << obj.getGrade();
	return (out);
}

void			Bureaucrat::executeForm(const Form & form)
{
	try {
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception & exc) {
		std::cout << form.getName() << " does not executes, because " << exc.what() << std::endl;
	}
}
/*
 * А тут ниже кононическая форма вложеных класов... НАХИБАЛИТИ НАДО? И надо ли?)
 */

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &other) {
	*this = other;
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &) {
	return *this;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &other) {
	*this = other;
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &) {
	return *this;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
