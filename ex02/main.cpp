#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"

int main() {

	std::cout << "" << std::endl;

	//test du presedentialPardonForm
	std::cout << "\033[33mTest Presidential Pardon Form\033[0m" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	try {
		Bureaucrat thiery("BoZafod Beeblebrox", 2);
		std::cout << thiery << std::endl;
		std::cout << "" << std::endl;

		PresidentialPardonForm formB("julie");
		std::cout << formB << std::endl;
	
		thiery.signForm(formB);
		std::cout << formB << std::endl;
		std::cout << "" << std::endl;

		thiery.executeForm(formB);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "" << std::endl;
	std::cout << "" << std::endl;

	//test du RobotomyRequestForm
	std::cout << "\033[33mTest Robotomy Request Form\033[0m" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	try {
		Bureaucrat thiery("Isacc", 60);
		std::cout << thiery << std::endl;
		std::cout << "" << std::endl;

		RobotomyRequestForm formB("c3po");
		std::cout << formB << std::endl;

		thiery.signForm(formB);
		std::cout << formB << std::endl;
		std::cout << "" << std::endl;

		thiery.executeForm(formB);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "" << std::endl;
	std::cout << "" << std::endl;

	//test du ShrubberyCreationForm
	std::cout << "\033[33mTest Shrubbery Creation Form\033[0m" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	try {
		Bureaucrat thiery("thiery", 144);
		std::cout << thiery << std::endl;
		std::cout << "" << std::endl;

		ShrubberyCreationForm form("claude");
		std::cout << form << std::endl;
	
		thiery.signForm(form);
		std::cout << form << std::endl;
		std::cout << "" << std::endl;

		thiery.executeForm(form);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


	return 0;
}
