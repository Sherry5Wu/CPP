#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

#include "AForm.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& o);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& o);
		// void	execute(const Bureaucrat & executor) const override;
		void	executeForm(const Bureaucrat & executor) const override;
};

#endif //PRESIDENTIALPARDONFORM