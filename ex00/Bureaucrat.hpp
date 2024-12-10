#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

#include <iostream>
#include <string>

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

	//getter et setter
    std::string getName() const;
    unsigned int getGrade() const;

	//methode pour incrementer et decrementer le grade
    void incrementGrade();
    void decrementGrade();

	//methode pour gerer les exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw(){
            return "\033[31mGrade is too high\033[0m";
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw(){
            return "\033[31mGrade is too low\033[0m";
        }
    };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bur);

#endif