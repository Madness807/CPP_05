#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
    
    static const int SIGN_GRADE = 72;
    static const int EXEC_GRADE = 45;

public:
    // Constructeurs et destructeur
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    virtual ~RobotomyRequestForm();
    
    // Constructeur par copie
    RobotomyRequestForm(const RobotomyRequestForm& other);

    // Surcharge d'opérateur
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

    // Getter
    std::string getTarget() const;

    // Méthode d'exécution
    virtual void execute(const Bureaucrat& executor) const;
};

#endif