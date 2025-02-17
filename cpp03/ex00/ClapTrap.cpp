/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:36:14 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/17 11:30:25 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("NoName"), hitPoints_(10), energyPoints_(10),
	attackDamage_(0){
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string name) : name_(name), hitPoints_(10), energyPoints_(10),
	attackDamage_(0){
	std::cout << "Assignment constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other): name_(other.name_), hitPoints_(other.hitPoints_),
	energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_){
	std::cout << "Copy constructor called\n";
}


ClapTrap&	ClapTrap::operator=(const ClapTrap& other){
	std::cout << "Copy assignment operator called\n";
	if (this == &other){
		return *this;
	}
	name_ = other.name_;
	hitPoints_ = other.hitPoints_;
	energyPoints_ = other.energyPoints_;
	attackDamage_ = other.attackDamage_;
	return *this;
}
ClapTrap::~ClapTrap(){
	std::cout << "Deconstructor called\n";
}

void	ClapTrap::attack(const std::string& target){
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0){
		std::cout << this->name_ << "is dead. Can't attack others\n";
		return ;
	}

	ClapTrap	player(target);

	player.hitPoints_ -= player.attackDamage_;
	player.energyPoints_ -= 1;
	std::cout << "ClapTrap " << this->name_ << "attacks" << target << ", causing "
		<< player.attackDamage_ << " points of damage!"
}

void	ClapTrap::takeDamage(unsigned int	amount){
	this->attackDamage_ = amount;
	std::cout << this->name_ << " damage sets to " << amount << "\n";
}

void	ClapTrap::beRepaired(unsigned int	amount){
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0){
		std::cout << this->name_ << "is dead. Can't be repaired\n";
		return ;
	}
	this->hitPoints_ += amount;
	this->energyPoints_ -= 1;
	std::cout << this->name_ << "repairs himself/herself with " << amount << " points. "
		<< "Now his/her hit points are " << this->hitPoints_ << "\n";
}
