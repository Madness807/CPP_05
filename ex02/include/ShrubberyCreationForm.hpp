#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		virtual ~ShrubberyCreationForm();
		
		AForm &operator=(const ShrubberyCreationForm &src);

		void	Executed(const Bureaucrat &Bureaucrat);
		virtual void	execute(const Bureaucrat &Bureaucrat) = 0;

};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif