#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
    std::cout << this->_name <<", Try to create " << this->_name << std::endl;
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    this->_grade = grade;
    std::cout << this->_name <<", Created " << this->_name << std::endl;
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
        this->_grade = src._grade;
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
    std::cout << this->_name <<", Try to Increment grade" << std::endl;
    if (this->_grade - 1 < HIGHEST_GRADE)
        throw GradeTooHighException();
    std::cout << this->_name <<", Increment grade" << std::endl;
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    std::cout << "Try to Increment grade" << std::endl;
    if (this->_grade + 1 > LOWEST_GRADE)
        throw GradeTooLowException();
    std::cout << "decrement grade" << std::endl;
    this->_grade++;
}

void			signForm(const Form &form) {
    if (form)
}

//##################################################################
//                          Operateur <<                           #
//##################################################################
std::ostream &operator<<(std::ostream &o, const Bureaucrat &bur) {
    o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
    return o;
}