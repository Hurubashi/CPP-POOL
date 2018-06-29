
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form ("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) :
		Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & form)
{
	Form::operator=(form);
	this->_target = form.getTarget();
	return ;
}

ShrubberyCreationForm  & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &)
{
	return (*this);
}

std::string		ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned()) {
		throw (NotSignedException());
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw (GradeTooLowException());
	}
	std::ofstream fout;
	fout.open((this->getTarget() + "_shrubbery"));
	fout << "         ; ; ;" << std::endl;
	fout << "       ;        ;  ;     ;;    ;" << std::endl;
	fout << "    ;                 ;         ;  ;" << std::endl;
	fout << "                   ;                ;;" << std::endl;
	fout << "   ;          ;            ;              ;" << std::endl;
	fout << "   ;            ';,        ;               ;" << std::endl;
	fout << "    ;              '$    ;;                ;;" << std::endl;
	fout << "   ;    ;           $:   ;:               ;" << std::endl;
	fout << " ;;      ;  ;;      *;  @):        ;   ; ;" << std::endl;
	fout << "              ;     :@,@):   ,;**:'   ;" << std::endl;
	fout << "  ;      ;,         :@@*: ;;**'      ;   ;" << std::endl;
	fout << "           ';o;    ;:(@';@*\"'  ;" << std::endl;
	fout << "   ;  ;       'bq,;;:,@@*'   ,*      ;  ;" << std::endl;
	fout << "              ,p$q8,:@)'  ;p*'      ;" << std::endl;
	fout << "       ;     '  ; '@@Pp@@*'    ;  ;" << std::endl;
	fout << "        ;  ; ;;    Y7'.'     ;  ;" << std::endl;
	fout << "                  :@):." << std::endl;
	fout << "                 .:@:'." << std::endl;
	fout << "               .::(@:.  " << std::endl;
}
