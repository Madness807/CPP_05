#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm *form;
	
	std::cout << "\n=== Test avec un Bureaucrate de haut niveau (grade 1) ===\n";
	try {
		Bureaucrat boss("Boss", 1);
		
		// Test Presidential Pardon
		std::cout << "\n\033[33mTest Presidential Pardon Form\033[0m\n";
		std::cout << "-----------------------------------------------\n";
		form = someRandomIntern.makeForm("presidential pardon", "Alice");
		if (form) {
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}

		// Test Robotomy
		std::cout << "\n\033[33mTest Robotomy Request Form\033[0m\n";
		std::cout << "-----------------------------------------------\n";
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form) {
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		std::cout << "\n\033[33mTest Shrubbery Creation Form\033[0m\n";
		std::cout << "-----------------------------------------------\n";
		form = someRandomIntern.makeForm("shrubbery creation", "Garden");
		if (form) {
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}

		std::cout << "\n=== Test formulaire inconnu ===\n";
		form = someRandomIntern.makeForm("unknown form", "Bob");
		if (form) {
		delete form;
	}
	}
	catch (std::exception& e) {
		std::cout << "\033[31mError: " << e.what() << "\033[0m\n";
	}

	return 0;
}
