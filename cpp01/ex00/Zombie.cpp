/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:20:54 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 11:20:54 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){}

Zombie::~Zombie(){
	std::cout << "Zombie " << this->_name << "is destroyed!" << std::endl;
}

void	Zombie::announce(){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
