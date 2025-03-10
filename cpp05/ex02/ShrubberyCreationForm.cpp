#include "ShrubberyCreationForm.hpp"

#define	THE_TREE "\
		ccee88oo\n\
    C8O8O8Q8PoOb o8oo\n\
 dOB69QO8PdUOpugoO9bD\n\
CgggbU8OU qOp qOdoUOdcb\n\
    6OuU  /p u gcoUodpP\n\
      \\//  /douUP\n\
        \\////\n\
         |||||\n\
         |||||\n\
         |||||\n"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery_Creation_Form", 145, 137, "unknow"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery_Creation_Form", 145, 137, target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o) : AForm(o){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o){
	if (this != &o){
		AForm::operator=(o);
	}
	return *this;
}

void	ShrubberyCreationForm::executeForm(const Bureaucrat & executor) const{
	// if (!getIsSigned()){
	// 	throw FormNotSignedException("From isn't signed yet");
	// }
	// if (executor.getGrade() > this->geteGradeToExecute()){
	// 	throw GradeTooLowException("The executor's grade is too low, can't execute");
	// }

	// open the file for output
	std::ofstream	outfile((this->getTarget() + "_shrubbery").c_str());
	if (!outfile){
		throw std::runtime_error("Error: Couldn't open the file in Shrubbery class");
	}
	outfile << THE_TREE;
	outfile.close();
}