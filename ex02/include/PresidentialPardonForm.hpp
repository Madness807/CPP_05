#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);
		virtual ~PresidentialPardonForm();
		
		AForm &operator=(const PresidentialPardonForm &src);

		void	execute(const Bureaucrat &Bureaucrat);

};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif