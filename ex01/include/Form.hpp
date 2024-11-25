#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string _name;
    bool _isSigned;
    const unsigned int _gradeToSign;
    const unsigned int _gradeToExecute;

public:
    Form();
    Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExecute);
    Form(const Form &src);
    virtual ~Form();
    Form &operator=(const Form &src);

    std::string getName() const;
    bool getIsSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif