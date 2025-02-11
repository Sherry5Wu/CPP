/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:18:23 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:18:23 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){
	std::cout << "This is the constructor of the Weapon Class" << std::endl;
}

Weapon::~Weapon(){};

// Here this->_type equals _type
const std::string&	Weapon::getType(void) const{
	return (this->_type);
}

void	Weapon::setType(const std::string& newType){
	this->_type = newType;
}
