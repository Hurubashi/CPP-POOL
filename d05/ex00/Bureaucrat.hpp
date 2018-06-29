
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

public:
	Bureaucrat(void);
	Bureaucrat(const std::string & name);
	Bureaucrat(const std::string & name, int grade);
	Bureaucrat(const Bureaucrat & other);
	Bureaucrat& operator=(const Bureaucrat &copy);
	~Bureaucrat(void);

	std::string			getName(void) const;
	int					getGrade(void) const;

	Bureaucrat 		& incrementGrade(void);
	Bureaucrat		& decrementGrade(void);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(const GradeTooHighException & other);
		GradeTooHighException& operator=(const GradeTooHighException &);
		~GradeTooHighException(void) throw();
		const char 		* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(const GradeTooLowException & other);
		GradeTooLowException& operator=(const GradeTooLowException &);
		~GradeTooLowException(void) throw();
		const char 		* what() const throw();
	};

private:
	const std::string			_name;
	int					_grade;


};

std::ostream	& operator << (std::ostream & out, const Bureaucrat & obj);

#endif
