#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <string>
#include <fstream>//permet de manipuler des fichiers
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		void	execute(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif