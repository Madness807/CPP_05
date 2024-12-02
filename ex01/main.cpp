#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n=== Test des constructeurs ===\n" << std::endl;
    try {
        Bureaucrat default_bureaucrat;
        std::cout << default_bureaucrat << std::endl;
        
        Bureaucrat bob("Bob", 100);
        std::cout << bob << std::endl;
        
        // Test copie
        Bureaucrat bob_clone(bob);
        std::cout << bob_clone << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << std::endl;
    }

    std::cout << "\n=== Test des grades invalides ===\n" << std::endl;
    try {
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << std::endl;
    }

    try {
        Bureaucrat tooLow("TooLow", 151);
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << std::endl;
    }

    std::cout << "\n=== Test de up_grade/down_grade ===\n" << std::endl;
    try {
        Bureaucrat jim("Jim", 2);
        std::cout << jim << std::endl;
        jim.up_grade();
        std::cout << jim << std::endl;
        jim.up_grade(); // Devrait throw exception
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << std::endl;
    }

    std::cout << "\n=== Test des Forms ===\n" << std::endl;
    try {
        Bureaucrat chef("Chef", 1);
        Bureaucrat stagiaire("Stagiaire", 150);
        
        Form f1("Formulaire A38", 50, 30);
        Form f2("Attestation B12", 140, 140);
        
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        
        // Test signature avec grade insuffisant
        try {
            f1.beSigned(stagiaire);
        }
        catch(const std::exception& e) {
            std::cerr << RED << e.what() << std::endl;
        }
        
        // Test signature avec grade suffisant
        f2.beSigned(chef);
        std::cout << f2 << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << RED << e.what() << std::endl;
    }

    std::cout << "\n=== Fin des tests ===\n" << std::endl;
    return 0;
}