#include "../include/Form.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Form::Form() : _name("Unnamed"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form::~Form() {}

//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################
Form &Form::operator=(const Form &src) {
    if (this != &src) {
        this->_signed = src._signed;
    }
    return *this;
}

void Form::setSigned(bool signature){
    this->_signed = signature;
}

//##################################################################
//                          GETTERS                                #
//##################################################################
std::string Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->_signed;
}

unsigned int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

unsigned int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

//##################################################################
//                          Methodes                               #
//##################################################################
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

//##################################################################
//                          Operateur <<                           #
//##################################################################
std::ostream &operator<<(std::ostream &o, const Form &form) {
    o << "Form " << form.getName() << ", signed: " << (form.getSigned() ? "yes" : "no")
      << ", grade to sign: " << form.getGradeToSign()
      << ", grade to execute: " << form.getGradeToExecute() << ".";
    return o;
}