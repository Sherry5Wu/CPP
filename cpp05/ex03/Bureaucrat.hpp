/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:56:26 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:56:26 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat&			operator=(const Bureaucrat& other);
		const std::string&	getName() const;
		int					getGrade() const;

		// increase the grade, note: 1 is the highest grade;
		void				increament();

		// decrease the grade, note: 150 is the lowest grade;
		void				decrement();
		void				signForm(AForm& form);
		void				executeForm(const AForm& from);

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception{
			public:
				const char* what() const noexcept override;
		};

		// THe functions below are for easy testing
		void	print() const;

	private:
		const std::string	name_;
		int					grade_;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);
