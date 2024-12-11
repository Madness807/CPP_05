#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &other);
        ~Intern();

    // Operator
    Intern &operator=(const Intern &other);

    // Method
    AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif
