#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"


//##################################################################
//                   Constructor && Destructor                     #
//##################################################################

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src) {}//copy

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target) {}//param

ShrubberyCreationForm::~ShrubberyCreationForm(){}

//##################################################################
//	            	Operateur d'affectation		                   #
//##################################################################
    ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

//##################################################################
//                          Methodes                               #
//##################################################################

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    checkExecution(executor); // Vérifie les permissions basées sur le grade de l'executor

    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file) {
        throw std::runtime_error("Could not open file.");
    }

    file << "       _-_       \n"
         << "    /~~   ~~\\    \n"
         << " /~~         ~~\\ \n"
         << "{               }\n"
         << " \\  _-     -_  / \n"
         << "   ~  \\\\ //  ~   \n"
         << "       | |       \n"
         << "       | |       \n";
    file.close();

    std::cout << "Shrubbery created in " << filename << std::endl;
}

