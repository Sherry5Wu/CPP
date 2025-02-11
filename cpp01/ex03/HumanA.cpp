/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:17:50 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:17:50 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name),
	_weapon(weapon){}

HumanA::~HumanA(){}

void	HumanA::attack(void) const{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
