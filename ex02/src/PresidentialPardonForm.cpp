#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
PresidentialPardonForm::PresidentialPardonForm() : _name("PresidentialPardonForm"), _signed(false), _gradeToSign(25), _gradeToExecute(5) {}

PresidentialPardonForm::PresidentialPardonForm(const AForm &src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

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
