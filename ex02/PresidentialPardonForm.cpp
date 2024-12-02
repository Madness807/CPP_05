#include "PresidentialPardonForm.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
// Constructor by default
PresidentialPardonForm::PresidentialPardonForm():
    AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE),
    _target("default") {
    std::cout << "PresidentialPardonForm constructeur par defaut" << std::endl;
}
// Constructor by parameter
PresidentialPardonForm::PresidentialPardonForm(std::string target):
    AForm("Presidential Pardon", SIGN_GRADE, EXEC_GRADE),
    _target(target) {
    std::cout << "PresidentialPardonForm constructeur paramétré" << std::endl;
}
// Constructor by copy
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
    AForm(other),
    _target(other._target) {
    std::cout << "PresidentialPardonForm constructeur par copie" << std::endl;
}
// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructeur" << std::endl;
}

//##################################################################
//                  Surcharge d operateur                         #
//##################################################################
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

//##################################################################
//                          GETTERS                               #
//##################################################################
std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

//##################################################################
//                          Methods                               #
//##################################################################
void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!this->getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
        
    std::cout << GREEN << this->_target << " a été pardonné par Zaphod Beeblebrox" << std::endl;
}