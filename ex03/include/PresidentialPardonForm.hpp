#ifndef PRESIDENTIAL_HPP
#define PRESIDENTIAL_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		
		PresidentialPardonForm();//default
		PresidentialPardonForm(const PresidentialPardonForm &src);//copy
		PresidentialPardonForm(std::string target);//param
		virtual ~PresidentialPardonForm();
		
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		void	execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif