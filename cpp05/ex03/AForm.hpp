/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:56:19 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:56:19 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm{
	public:
		AForm();
		AForm(const std::string& name, int gradeToS, int gradeToE,
				const std::string& target);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm&				operator=(const AForm& other);
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					geteGradeToExecute() const;
		const std::string&	getTarget() const;
		void				beSigned(const Bureaucrat& bureau);
		void				execute(const Bureaucrat& executor) const;
		virtual void		executeForm(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception{
			public:
				GradeTooHighException(const std::string& message);
				const char* what() const noexcept override;
			private:
				const std::string	message_;
		};

		class GradeTooLowException : public std::exception{
			public:
				GradeTooLowException(const std::string& message);
				const char* what() const noexcept override;
			private:
				const std::string	message_;
		};

		class FormNotSignedException : public std::exception{
			public:
				FormNotSignedException(const std::string& message);
				const char*	what() const noexcept override;
			private:
				const std::string	message_;
		};


	private:
		const std::string	name_;
		bool				isSigned_;
		const int			gradeToSign_;
		const int			GradeToExecute_;
		const std::string	traget_;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);
