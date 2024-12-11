#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		void	execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif