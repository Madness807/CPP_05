#include "./include/Bureaucrat.hpp"
#include "./include/AForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"

int main() {

    std::cout << "" << std::endl; 
    try {
        Bureaucrat thiery("Bob", 666);
        std::cout << thiery << std::endl;

        AForm Aform("FormA", 50, 5);
        std::cout << formA << std::endl;

        thiery.signForm(formA);
        std::cout << formA << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "" << std::endl; 
    try {
        Bureaucrat thiery("Thiery", 50);
        std::cout << thiery << std::endl;

        AForm formA("FormA", 20, 5);
        std::cout << formA << std::endl;

        thiery.signForm(formA);
        std::cout << formA << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "" << std::endl; 

        try {
        Bureaucrat thiery("Maude", 50);
        std::cout << thiery << std::endl;

        AForm formA("FormA", 60, 5);
        std::cout << formA << std::endl;

        thiery.signForm(formA);
        std::cout << formA << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "" << std::endl; 

    return 0;
}

