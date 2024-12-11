#include "../include/AForm.hpp"
#include "../include/RobotomyRequestForm.hpp"


//##################################################################
//                   Constructor && Destructor                     #
//##################################################################

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src) {}//copy

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::~RobotomyRequestForm(){}

// ##################################################################
//	            	Operateur d'affectation		                   #
// ##################################################################

    RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

//##################################################################
//                          Methodes                               #
//##################################################################
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    checkExecution(executor);
    std::cout << "* BRRRRR ZZZZZZ Drrrrr *" << std::endl;
    if (rand() % 2) {
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy of " << this->getTarget() << " failed." << std::endl;
    }
}

