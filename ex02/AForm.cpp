#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>


//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
AForm::AForm(): 
	_name("default"), 
	_signed(false),
	_gradeToSign(150),
	_gradeToExecute(150) {
	std::cout << "Form constructeur par defaut" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
	std::cout << "Form constructeur paramétré" << std::endl;
}

AForm::AForm(const AForm& other):
	_name(other._name),
	_signed(other._signed),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {
	std::cout << "Form constructeur par copie" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form destructeur" << std::endl;
}

//##################################################################
//                  Surcharge d operateur                         #
//##################################################################
AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

//##################################################################
//                          GETTERS                               #
//##################################################################
std::string AForm::getName() const {
	return this->_name;
}
int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}
int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}
int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

//##################################################################
//                          Methods                               #
//##################################################################
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
}
void AForm::execute(Bureaucrat const & executor) const {
	if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
}

//##################################################################
//                    Exeption                                     #
//##################################################################
const char* AForm::GradeTooHighException::what() const throw() {
	return "\033[1;31mGrade is too high for this form\033[0m";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "\033[1;31mGrade is too low for this form\033[0m";
}
const char* AForm::FormNotSignedException::what() const noexcept {
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	return os;
}



