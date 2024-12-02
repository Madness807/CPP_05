#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;

public:
    // Constructeurs et destructeur
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm();
    // Constructeur par copie
    ShrubberyCreationForm(const ShrubberyCreationForm& other);

    // Surcharge d'opérateur
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

    // Methodes
    virtual void execute(Bureaucrat const & executor) const;

};

#endif