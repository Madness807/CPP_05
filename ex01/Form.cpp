#include "Form.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Form::Form(): 
    _name("default"), 
    _signed(false),
    _gradeToSign(150),
    _gradeToExecute(150) {
    std::cout << "Form constructeur par defaut" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute):
    _name(name),
    _signed(false),
    _gradeToSign(gradeToSign),
    _gradeToExecute(gradeToExecute) {
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw Form::GradeTooHighException();
    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw Form::GradeTooLowException();
    std::cout << "Form constructeur paramétré" << std::endl;
}

Form::Form(const Form& other):
    _name(other._name),
    _signed(other._signed),
    _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form constructeur par copie" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructeur" << std::endl;
}

//##################################################################
//                  Surcharge d operateur                         #
//##################################################################
Form& Form::operator=(const Form& rhs) {
    if (this != &rhs)
        this->_signed = rhs._signed;
    return *this;
}

//##################################################################
//                          GETTERS                               #
//##################################################################
std::string Form::getName() const {
    return this->_name;
}

bool Form::getSigned() const {
    return this->_signed;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

//##################################################################
//                          Methods                               #
//##################################################################
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

//##################################################################
//                     Exception Methods                          #
//##################################################################
const char* Form::GradeTooHighException::what() const throw() {
    return "\033[1;31mGrade is too high for this form\033[0m";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "\033[1;31mGrade is too low for this form\033[0m";
}

//##################################################################
//                    Operator Overload                           #
//##################################################################
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() 
       << ", signed: " << (form.getSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}
