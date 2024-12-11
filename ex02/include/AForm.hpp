#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
private:
	const std::string 	_name;
	bool 				_signed;
	const unsigned int 	_gradeToSign;
	const unsigned int 	_gradeToExecute;
	std::string 		_target;

public:
	AForm();
	AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, std::string target);
	AForm(const AForm &src);
	virtual ~AForm();
	AForm &operator=(const AForm &src);

	void			setSigned(bool signature);

	std::string		getName() const;
	std::string		getTarget() const;
	bool 			getSigned() const;
	unsigned int 	getGradeToSign() const;
	unsigned int 	getGradeToExecute() const;
	
	//methode
	void 			beSigned(const Bureaucrat &bureaucrat);
	void			checkExecution(const Bureaucrat &executor) const;

	//methode virtuel pure
	virtual void	execute(const Bureaucrat &executor) const = 0;

	//methode pour gerer les exceptions
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw(){
			return "\033[31mGrade is too high (form)\033[0m";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw(){
			return "\033[31mGrade is too low (form)\033[0m";
		}
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw(){
			return "\033[31mForm is not signed\033[0m";
		}
	};
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif