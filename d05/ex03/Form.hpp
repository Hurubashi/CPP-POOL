
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:
	Form(void);
	Form(std::string name, int gradeToSing, int gradeToExecute);
	Form(const Form &other);
	Form &operator= (const Form &copy);
	~Form();

	std::string		getName(void) const;
	int				getGradeToSign(void) const;
	int				getGradeToExecute(void) const;
	bool			getSigned(void) const ;
	void			beSigned(const Bureaucrat &obj);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException	& operator= (const GradeTooHighException & obj);
		const char 		* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		GradeTooLowException	& operator= (const GradeTooLowException & obj);
		const char 		* what() const throw();
	};
	class NotSignedException : public std::exception
	{
	public:
		virtual const char    *what(void) const throw();
	};

private:
	const std::string	_name;
	const int			_gradeToSing;
	const int			_gradeToExecute;
	bool				_signed;
};

std::ostream	& operator << (std::ostream & out, const Form & obj);

#endif
