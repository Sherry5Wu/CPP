/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:39:53 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 14:44:26 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure"){}

Cure::Cure(const Cure& other): AMateria(other.type_){}

Cure::~Cure(){}

Cure&	Cure::operator=(const Cure& other){
	if (this != &other){
		this->type_ = other.type_;
	}
	return *this;
}

AMateria*	Cure::clone() const{
	return (new Cure());
}

void	Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
