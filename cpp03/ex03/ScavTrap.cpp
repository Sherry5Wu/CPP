/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:40:14 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 12:59:38 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << ORANGE << "ScavTrap -- Default constructor called\n" << RESET;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
	std::cout << ORANGE << "ScavTrap -- Consturctor called.\n"<< RESET;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	std::cout << ORANGE << "ScavTrap -- Copy constrtuctor called\n "<< RESET;
}
ScavTrap::~ScavTrap(){
	std::cout << ORANGE << "ScavTrap -- Deconstructor called. " << this->name_ 
	<< " has been destoryed!\n"<< RESET;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other){
	std::cout << ORANGE << "ScavTrap -- Assignment operator called\n" << RESET;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target){
	if (this->energyPoints_ == 0){
		std::cout << ORANGE << "ScavTrap -- "<< this->name_
		<< "doesn't have energy, can't attack others\n" << RESET;
	}else if (this->hitPoints_ == 0){
		std::cout << ORANGE << "ScavTrap -- " << this->name_
		<< " is dead, can't attack others\n" << RESET;
	}else{
		this->energyPoints_--;
		std::cout << ORANGE << "ScavTrap " << this->name_ << " attacks "
		<< target << "\n" << RESET;
	}
}

void	ScavTrap::guardGate(){
	std::cout << ORANGE << "ScavTrap " << this->name_
	<< " is now in Gate keeper mode\n" << RESET;
}
