#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat {
private:
    const std::string _name;
    unsigned int _grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &src);
    virtual ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &src);

    // getter et setter
    std::string getName() const;
    unsigned int getGrade() const;

    // méthode pour incrémenter et décrémenter le grade
    void incrementGrade();
    void decrementGrade();

    // méthode pour signer un formulaire
    void signForm(Form &form);

    // méthode pour gérer les exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bur);

#endif