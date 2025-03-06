#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form{
	public:
		Form();
		Form(const std::string name, const int sGrade, const int eGrade);
		Form(const Form& other);
		~Form();

		Form&				operator=(const Form& other);
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					geteGradeToExecute() const;
		void				beSigned(const Bureaucrat& bureau);

		class GradeTooHighException : public std::exception{
			public:
			GradeTooHighException(const std::string message);
				const char* what() const noexcept override;
			private:
				const std::string	message_;
		};

		class GradeTooLowException : public std::exception{
			public:
			GradeTooLowException(const std::string message);
				const char* what() const noexcept override;
			private:
				const std::string	message_;
		};


	private:
		const std::string	name_;
		bool				isSigned_;
		const int			gradeToSign_;
		const int			GradeToExecute_;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);