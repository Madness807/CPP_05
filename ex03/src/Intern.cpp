#include "../include/Intern.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Intern::Intern() {}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern::~Intern() {}

//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

//##################################################################
//                          Methodes                               #
//##################################################################
// Tableau associant les noms de formulaire aux fonctions de création

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    // Tableau associant les noms de formulaire aux types
    const std::string formTypes[3] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    // Recherche du type de formulaire
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            
            // Création du formulaire approprié
            switch (i) {
                case 0:
                    return new RobotomyRequestForm(target);
                case 1:
                    return new PresidentialPardonForm(target);
                case 2:
                    return new ShrubberyCreationForm(target);
            }
        }
    }

    // Si aucun formulaire ne correspond, affiche une erreur
    std::cerr << "Error: Form type \"" << formName << "\" does not exist." << std::endl;
    return NULL;  // NULL au lieu de nullptr en C++98
}

