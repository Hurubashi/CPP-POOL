
#include <curses.h>
#include "Form.hpp"

Form::Form(void)
		: _name("default"), _gradeToSing(10), _gradeToExecute(10), _signed(FALSE) {

}

Form::Form(std::string name, int gradeToSing, int gradeToExecute)
		: _name(name), _gradeToSing(gradeToSing), _gradeToExecute(gradeToExecute) , _signed(FALSE){
	if (gradeToExecute < 1 || gradeToSing < 1) {
		throw (GradeTooHighException());
	}
	if (gradeToExecute > 150 || gradeToSing > 150) {
		throw (GradeTooLowException());
	}
	this->_signed = false;
	return ;
}

Form::Form(const Form &other)
		: _name(other.getName()), _gradeToSing(other.getGradeToSign()),
		  _gradeToExecute(other.getGradeToExecute()), _signed(other.getSigned()) {
	*this = other;
}

Form& Form::operator=(const Form &) {
	return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
	return this->_name;
}

int Form::getGradeToSign() const {
	return this->_gradeToSing;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

bool Form::getSigned() const {
	return this->_signed;
}

void Form::beSigned(const Bureaucrat &obj) {
	if (obj.getGrade() > this->_gradeToSing) {
		throw(GradeTooLowException());
	}
	this->_signed = true;
	return ;
}

const char 		*Form::GradeTooHighException::what() const throw()
{
	return ("Слишком большая оценка ...");
}

const char 		*Form::GradeTooLowException::what() const throw() {
	return ("Слишком маленькая оценка ...");
}

std::ostream 	& operator<< (std::ostream & out, const Form & obj)
{
		out << "Для подписания требуется " << obj.getGradeToSign();
		out << ". Для исполнения требуется " << obj.getGradeToExecute();
		out << ". Форма " << obj.getName() << " была подписана.";
		out << (obj.getSigned() ? "" : "не была подписана.");
	return (out);
}

const char* Form::NotSignedException::what(void) const throw()
{
	return ("Form not signed, yet");
}


