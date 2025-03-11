/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:56:03 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:56:03 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ShrubberyCreationForm::executeForm() const{
	std::ofstream	outfile((this->getTarget() + "_shrubbery").c_str());
	if (!outfile){
		throw std::runtime_error("Error: Couldn't open the file in Shrubbery class");
	}
	outfile << THE_TREE;
	outfile.close();
}
