#include "Form.hpp"

Form::Form() : name_("default_form"), isSigned_(false), gradeToSign_(150),
GradeToExecute_(150){}

Form(const std::string name, const int sGrade, const int eGrade);
Form(const Form& other);
~Form();

Form&				operator=(const Form& other);
const std::string&	getName() const;
bool				getIsSigned() const;
int					getGradeToSign() const;
int					geteGradeToExecute() const;
void				beSigned(const Bureaucrat& bureau);