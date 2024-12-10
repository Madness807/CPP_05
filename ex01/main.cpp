#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        Bureaucrat thiery("Thiery", 3);
        std::cout << thiery << std::endl;

        Form formA("FormA", 2, 5);
        std::cout << formA << std::endl;

        thiery.incrementGrade();
        std::cout << thiery << std::endl;

        thiery.signForm(formA);
        std::cout << formA << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}