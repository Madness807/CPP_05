#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	
		// Grades requis fixés
		static const int SIGN_GRADE = 25;
		static const int EXEC_GRADE = 5;

	public:
		// Constructeurs et destructeur
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		
		// Constructeur par copie
		PresidentialPardonForm(const PresidentialPardonForm& other);

	// Surcharge d'opérateur
	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

	// Getter
	std::string getTarget() const;

	// Méthode d'exécution spécifique
	virtual void execute(const Bureaucrat& executor) const;
};

#endif