#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat {
	private:
		const std::string _name;
		const int _grade;

	public:
		// Constructeur par default
		Bureaucrat();

		// Constructeur prenant une string
		Bureaucrat(std::string name,const int grade);

		// Constructeur par copie
		Bureaucrat(Bureaucrat const & instance);

		// Destructeur
		~Bureaucrat();

		// Surcharge d operateur
		Bureaucrat& operator=(const Bureaucrat &rhs);

		// Getter
		std::string getName() const;
		int getGrade() const;

		//Methode
		void up_grade();
		void down_grade();

		// class functions
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream & operator<<(std::ostream & o, Bureaucrat &rhs);



#endif