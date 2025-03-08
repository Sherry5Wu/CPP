#ifndef ROBOTOMYREQUESTFORM
# define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <ctime> // for std::time
#include <cstdlib> // for std::srand

class RobotomyRequestForm : public AForm{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& o);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& o);
		// void	execute(const Bureaucrat & executor) const override;
		void	executeForm(const Bureaucrat & executor) const override;
};

#endif //ROBOTOMYREQUESTFORM