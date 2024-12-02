#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	// Constructeurs et destructeur
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	~AForm();

	// Surcharge d'opérateur
	AForm& operator=(const AForm& rhs);

	// Getters
	std::string getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	// Méthodes
	void 		beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const;

	// Exceptions
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif