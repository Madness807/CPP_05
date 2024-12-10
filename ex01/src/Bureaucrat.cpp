#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>
#include "../include/Form.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
    std::cout <<"Try to create " << this->_name << std::endl;
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    else if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    this->_grade = grade;
    std::cout <<"Created " << this->_name << std::endl;
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

void Bureaucrat::signForm(Form &form) {
    std::cout << this->_name <<", Try to Sign the form" << std::endl;

    if (this->_grade > form.getGradeToSign()){
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
        throw Form::GradeTooLowException();
    }
    form.setSigned(1);

    std::cout << this->_name <<", \033[32mForm is signed\033[0m" << std::endl;
}

//##################################################################
//                          Operateur <<                           #
//##################################################################
std::ostream &operator<<(std::ostream &o, const Bureaucrat &bur) {
    o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
    return o;
}
