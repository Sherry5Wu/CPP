/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:36:14 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/17 14:45:04 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_(""), hitPoints_(10), energyPoints_(10),
	attackDamage_(0){
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string name) : name_(name), hitPoints_(10), energyPoints_(10),
	attackDamage_(0){
	std::cout << "Assignment constructor called\n";
}

ClapTrap::ClapTrap(const std::string name, unsigned int hP, unsigned int eP, unsigned int aD) :
 name_(name), hitPoints_(hP), energyPoints_(eP), attackDamage_(aD){
	std::cout << "Parametried construstor called\n";
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
	std::cout << "Deconstructor called. " << this->name_ << " has been destoryed!\n";
}

void	ClapTrap::attack(const std::string& target){
	if (this->energyPoints_ == 0){
		std::cout << this->name_ << "doesn't have energy, can't attack others\n";
	}else if (this->hitPoints_ == 0){
		std::cout << this->name_ << " is dead, can't attack others\n";
	}else{
		this->energyPoints_--;
		std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing "
			<<this->attackDamage_ << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int	amount){
	if (this->hitPoints_ == 0){
		std::cout << "ClapTrap " << this->name_ << "is DEAD, don't attack him/her anymore\n";
		return ;
	}
	this->hitPoints_ = (hitPoints_ > amount ? (hitPoints_ - amount) : 0);
	if (this->hitPoints_ == 0){
		std::cout << "ClapTrap " << this->name_ << " took " << amount << " damages. Then he/she"
			<< " is dead\n";
	} else {
		std::cout << "ClapTrap " << this->name_ << " took " << amount << " damages. Ane He/she"
			<< " is still alive ツ\n";
	}
}

void	ClapTrap::beRepaired(unsigned int	amount){
	if (this->energyPoints_ == 0){
		std::cout << this->name_ << "doesn't have energy to be repaired, just let him/her go\n";
	}else if (this->hitPoints_ == 0){
		std::cout << "ClapTrap " << this->name_ << " is dead, can't not be repaired anymore."
			<< " Sorry for your lost.\n";
	}else{
		this->hitPoints_ += amount;
		this->energyPoints_--;
		std::cout << this->name_ << " repairs himself/herself with " << amount << " points. "
			<< "Now his/her hit points are " << this->hitPoints_ << ". GREAT\n";
	}
}
