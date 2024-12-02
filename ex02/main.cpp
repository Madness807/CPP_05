#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubbery("home");
        PresidentialPardonForm pardon("Alice");
        RobotomyRequestForm robotomy("Charlie");

        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        bob.signForm(pardon);
        bob.executeForm(pardon);

        bob.signForm(robotomy);
        bob.executeForm(robotomy);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}