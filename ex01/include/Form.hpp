#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string 	_name;
	bool 				_signed;
	const unsigned int 	_gradeToSign;
	const unsigned int 	_gradeToExecute;

public:
	Form();
	Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form &src);
	virtual ~Form();
	Form &operator=(const Form &src);

	void			setSigned(bool signature);

	std::string		getName() const;
	bool 			getSigned() const;
	unsigned int 	getGradeToSign() const;
	unsigned int 	getGradeToExecute() const;
	
	void 			beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif