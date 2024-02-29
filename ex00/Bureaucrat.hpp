#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
    private:
    protected:

	public:

		// Constructeur par default
		Bureaucrat();
		// Constructeur prenant une string
		Bureaucrat(std::string type);
		// Constructeur par copie
		Bureaucrat(Bureaucrat const & instance);
		// Destructeur
		virtual ~Bureaucrat();

		// Surcharge d operateur
		Bureaucrat& operator=(const Bureaucrat &rhs);

		// Methodes
		virtual void makeSound() const = 0;

		virtual std::string getType() const;
};

#endif