#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
    if (grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName() + "_copy") {
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this != &src) {
        this->_grade = src.getGrade();
    }
    return *this;
}

//##################################################################
//                          GETTERS                                #
//##################################################################
std::string Bureaucrat::getName() const {
    return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
    return this->_grade;
}

//##################################################################
//                          Methodes                               #
//##################################################################
void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    this->_grade += 1;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

//##################################################################
//                          Exceptions                             #
//##################################################################
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "The grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "The grade is too low!";
}

//##################################################################
//                          Operateur <<                           #
//##################################################################
std::ostream &operator<<(std::ostream &o, const Bureaucrat &bur) {
    o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
    return o;
}