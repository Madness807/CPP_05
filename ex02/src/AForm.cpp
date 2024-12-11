#include "../include/AForm.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
AForm::AForm() : _name("Unnamed"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {}

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute, std::string target)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
        throw AForm::GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _target(src._target) {}

AForm::~AForm() {}

//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################
AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        this->_signed = src._signed;
        this->_target = src._target;
    }
    return *this;
}

void AForm::setSigned(bool signature){
    this->_signed = signature;
}

//##################################################################
//                          GETTERS                                #
//##################################################################
std::string AForm::getTarget() const {
    return this->_target;
}

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

void AForm::checkExecution(const Bureaucrat &executor)const{
    if (!_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
}

//##################################################################
//                          Operateur <<                           #
//##################################################################
std::ostream &operator<<(std::ostream &o, const AForm &form) {
    o << "Form " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
      << ", grade to sign: " << form.getGradeToSign()
      << ", grade to execute: " << form.getGradeToExecute()
      << ", target : " << form.getTarget() << ".";
    return o;
}