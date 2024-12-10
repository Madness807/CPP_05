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


//##################################################################
//                          GETTERS                                #
//##################################################################


//##################################################################
//                          Methodes                               #
//##################################################################


//##################################################################
//                          Operateur <<                           #
//##################################################################
