/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:47:53 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 13:17:42 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << BLUE << "FragTrap-- Default constructor called\n" << RESET;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name){
	std::cout << BLUE << "FragTrap-- Parameterized constructor called\n" << RESET;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
	std::cout << BLUE << "FragTrap-- Copy constructor called\n" << RESET;
}

FragTrap::~FragTrap(){
	std::cout << BLUE << "FragTrap-- Deconstructor called\n" << RESET;
}

FragTrap&	FragTrap::operator=(const FragTrap& other){
	std::cout << BLUE << "FragTrap-- Assignment operator called\n" << RESET;
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return *this;
}

void	FragTrap::attack(const std::string& target){
	if (this->energyPoints_ == 0){
		std::cout << BLUE << "FragTrap -- "<< this->name_
		<< "doesn't have energy, can't attack others\n" << RESET;
	}else if (this->hitPoints_ == 0){
		std::cout << BLUE << "FragTrap -- " << this->name_
		<< " is dead, can't attack others\n"<< RESET;
	}else{
		this->energyPoints_--;
		std::cout << BLUE << "FragTrap " << this->name_ << " attacks " << target
		<< "\n" << RESET;
	}
}

void	FragTrap::highFivesGuys(){
	std::cout << BLUE << "FragTrap " << this->name_ << " requests a joyly, happily"
	<< " lovely HIGH FIVES 🙏🏻\n" << RESET;
}
