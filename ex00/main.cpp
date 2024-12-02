#include "Bureaucrat.hpp"

int main()
{
    std::cout << "TEST 1 : no exception (42, James)" << std::endl;
    try
    {
        Bureaucrat  James("James", 42);
        std::cout << James << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "default" << std::endl;
    }

    std::cout << "TEST 2 : too high (0, joe)" << std::endl;
    try
    {
        Bureaucrat  joe("joe", 0);
        std::cout << joe << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "default" << std::endl;
    }

    std::cout << "TEST 3 : too low (Patrice 151)" << std::endl;
    try
    {
        Bureaucrat  patrice("Patrice", 150);
        std::cout << patrice << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "default" << std::endl;
    }

	std::cout << "TEST 4 : Incrementation (zoe, 2)" << std::endl;
    try
    {
        Bureaucrat  zoe("zoe", 2);

        std::cout << zoe << std::endl;

        zoe.up_grade();
        std::cout << zoe << std::endl;

        zoe.up_grade();
        std::cout << zoe << std::endl;

        zoe.up_grade();
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "default" << std::endl;
    }

    std::cout << "TEST 5 : decrementation (jasmin ,149)" << std::endl;
    try
    {
        Bureaucrat  jasmin("jasmin", 149);

        std::cout << jasmin << std::endl;

        jasmin.down_grade();
        std::cout << jasmin << std::endl;

        jasmin.down_grade();
        std::cout << jasmin << std::endl;
        
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
       std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "default" << std::endl;
    }

    return(0);
}