/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:39:53 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 13:39:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){}

Ice::Ice(const Ice& other): AMateria(other.type_){}

Ice::~Ice(){}

Ice&	Ice::operator=(const Ice& other){
	if (this != &other){
		this->type_ = other.type_;
	}
	return *this;
}

AMateria*	Ice::clone() const{
	return (new Ice());
}

void	Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
