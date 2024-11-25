#include "Form.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Form::Form() : _name("Unnamed"), _isSigned(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE) {}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
        throw Form::GradeTooHighException();
    if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form::~Form() {}

//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################
Form &Form::operator=(const Form &src) {
    if (this != &src) {
        this->_isSigned = src._isSigned;
    }
    return *this;
}

//##################################################################
//                          GETTERS                                #
//##################################################################
std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
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
    this->_isSigned = true;
}

//##################################################################
//                          Exceptions                             #
//##################################################################
const char* Form::GradeTooHighException::what() const throw() {
    return "The grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "The grade is too low!";
}

//##################################################################
//                          Operateur <<                           #
//##################################################################
std::ostream &operator<<(std::ostream &o, const Form &form) {
    o << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
      << ", grade to sign: " << form.getGradeToSign()
      << ", grade to execute: " << form.getGradeToExecute() << ".";
    return o;
}