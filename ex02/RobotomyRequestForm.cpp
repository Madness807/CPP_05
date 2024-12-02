#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    // Seed the random number generator
    std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    // Check executability using base class method
    checkExecutability(executor);

    // Drilling noise
    std::cout << "* DRILLING NOISES *" << std::endl;

    // 50% success rate
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
    }
}