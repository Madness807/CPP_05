#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
//PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}//default

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {}//copy


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target) {
    
}//param

PresidentialPardonForm::~PresidentialPardonForm(){}

// ##################################################################
//	            	Operateur d'affectation		                   #
// ##################################################################

    PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

//##################################################################
//                          Methodes                               #
//##################################################################

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    checkExecution(executor);
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
