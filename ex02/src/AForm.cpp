#include "../include/AForm.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
AForm::AForm() : _name("Unnamed"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm::~AForm() {}

//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################
AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        this->_signed = src._signed;
    }
    return *this;
}

void AForm::setSigned(bool signature){
    this->_signed = signature;
}

//##################################################################
//                          GETTERS                                #
//##################################################################
std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_signed;
}

unsigned int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

unsigned int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

//##################################################################
//                          Methodes                               #
//##################################################################
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

//##################################################################
//                          Operateur <<                           #
//##################################################################
std::ostream &operator<<(std::ostream &o, const AForm &form) {
    o << "Form " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
      << ", grade to sign: " << form.getGradeToSign()
      << ", grade to execute: " << form.getGradeToExecute() << ".";
    return o;
}