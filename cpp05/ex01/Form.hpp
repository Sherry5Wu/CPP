/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:55:13 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:55:13 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form{
	public:
		Form();
		Form(const std::string& name, int gradeToS, int gradeToE);
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


	private:
		const std::string	name_;
		bool				isSigned_;
		const int			gradeToSign_;
		const int			GradeToExecute_;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);
