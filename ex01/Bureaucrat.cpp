# include "Bureaucrat.hpp"

//##################################################################
//                   Constructor && Destructor                     #
//##################################################################
Bureaucrat::Bureaucrat(): _name("default"), _grade(1){
	std::cout << "Appel constructeur par defaut" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade){
	if (grade < MAX_GRADE){
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade > MIN_GRADE){
		throw Bureaucrat::GradeTooHighException();
	}
	else
		std::cout << "Appel du surchargeur surchargé" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &instance): _name(instance.getName()){
	this->_grade = instance.getGrade();
	std::cout << "Appel du constructeur par copie" << std::endl;
}

Bureaucrat::~Bureaucrat() {
		std::cout << "Bureaucrat " << this->getName() << " destroyed.\n";
}

//##################################################################
//	            	Surcharge d operateur		                   #
//##################################################################
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs){
	this->_grade = rhs.getGrade();
	return (*this);
}

//##################################################################
//                          GETTERS                                #
//##################################################################
std::string Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

//##################################################################
//                          Class function                         #
//##################################################################

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "\033[1;31mGrade is too high\033[0m"; // Rouge
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "\033[1;31mGrade is too low\033[0m"; // Rouge
}

//##################################################################
//                          Methodes                               #
//##################################################################

void Bureaucrat::down_grade() {
	this->_grade++;
	if (_grade > MAX_GRADE){
		throw Bureaucrat::GradeTooHighException();
	}
}

void Bureaucrat::up_grade(){
	this->_grade--;
	if (_grade < MIN_GRADE){
		throw Bureaucrat::GradeTooLowException();
	}
}


std::ostream & operator<<(std::ostream & o, Bureaucrat &rhs){
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}