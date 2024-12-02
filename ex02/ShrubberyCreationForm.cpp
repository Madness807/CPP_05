#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// constructor by copy
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) 
    : AForm(other), _target(other._target) {}

// ##################################################################
//		Operateur d'affectation		                                #
// ##################################################################

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    // Check executability using base class method
    //this->executeCheck(executor);

    // Create and write to file
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    // ASCII tree art
    outFile << "       _-_" << std::endl;
    outFile << "    /~~   ~~\\" << std::endl;
    outFile << " /~~         ~~\\" << std::endl;
    outFile << "{               }" << std::endl;
    outFile << " \\  _-     -_  /" << std::endl;
    outFile << "   ~  \\\\ //  ~" << std::endl;
    outFile << "_- -   | | _- _" << std::endl;
    outFile << "  _ -  | |   -_" << std::endl;
    outFile << "      // \\\\" << std::endl;

    outFile.close();
}