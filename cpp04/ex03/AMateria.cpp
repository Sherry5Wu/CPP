/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:31:26 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 13:29:40 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type_("default_materia"){}

AMateria::AMateria(const std::string& type) : type_(type){}

AMateria::AMateria(const AMateria& other) : type_(other.type_){}

AMateria::~AMateria(){}

AMateria&	AMateria::operator=(const AMateria& other){
	if (this != &other){
		this->type_ = other.type_;
	}
	return *this;
}

const std::string&	AMateria::getType() const{
	return (this->type_);
}

void	AMateria::use(ICharacter& target){
	(void)target;
	std::cout << "I am from the AMateria class, I must keep slience\n";
}
