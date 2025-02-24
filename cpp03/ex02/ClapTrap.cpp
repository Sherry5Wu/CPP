/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:36:14 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 08:54:41 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("default"), hitPoints_(10), energyPoints_(10),
	attackDamage_(0){
	std::cout << PURPLE << "ClapTrap--Default constructor called\n" << RESET;
}

ClapTrap::ClapTrap(const std::string name) : name_(name), hitPoints_(10),
energyPoints_(10), attackDamage_(0){
	std::cout << PURPLE << "ClapTrap--Parameterized constructor called\n" << RESET;
}

ClapTrap::ClapTrap(const ClapTrap& other): name_(other.name_),
hitPoints_(other.hitPoints_), energyPoints_(other.energyPoints_),
attackDamage_(other.attackDamage_){
	std::cout << PURPLE << "ClapTrap--Copy constructor called\n" << RESET;
}

ClapTrap::~ClapTrap(){
	std::cout << PURPLE << "ClapTrap--Deconstructor called. " << this->name_ 
	<< " has been destoryed!\n" << RESET;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other){
	std::cout << PURPLE << "ClapTrap--Assignment operator called\n" << RESET;
	if (this != &other){
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target){
	if (this->energyPoints_ == 0){
		std::cout  << PURPLE << "ClapTrap "<< this->name_
		<< "doesn't have energy, can't attack others\n" << RESET;
	}else if (this->hitPoints_ == 0){
		std::cout  << PURPLE << "ClapTrap "<< this->name_
		<< " is dead, can't attack others\n" << RESET;
	}else{
		this->energyPoints_--;
		std::cout  << PURPLE << "ClapTrap " << this->name_ << " attacks "
		<< target << ", causing " <<this->attackDamage_ << " points of damage!\n"
		<< RESET;
	}
}

void	ClapTrap::takeDamage(unsigned int	amount){
	if (this->hitPoints_ == 0){
		std::cout  << PURPLE << "ClapTrap " << this->name_
		<< "is DEAD, don't attack it anymore\n" << RESET;
		return ;
	}else if(this->energyPoints_ == 0){
		std::cout  << PURPLE << "ClapTrap " << this->name_
		<< "doesn't have any enery left, too tired to take damage\n" << RESET;
		return ;
	}
	this->hitPoints_ = (hitPoints_ > amount ? (hitPoints_ - amount) : 0);
	if (this->hitPoints_ == 0){
		std::cout  << PURPLE << "ClapTrap " << this->name_ << " took " << amount
		<< " damages. It is DEAD\n" << RESET;
	} else {
		std::cout  << PURPLE << "ClapTrap " << this->name_ << " took " << amount
		<< " damages. It is still ALIVE ツ\n" << RESET;
	}
}

void	ClapTrap::beRepaired(unsigned int	amount){
	if (this->energyPoints_ == 0){
		std::cout  << PURPLE << "ClapTrap "<< this->name_
		<< "doesn't have energy to be repaired, just let it go\n" << RESET;
		return ;
	}else if (this->hitPoints_ == 0){
		std::cout  << PURPLE << "ClapTrap " << this->name_
		<< " is dead, can't be repaired anymore. Sorry for your lost.\n" << RESET;
		return ;
	}
	this->hitPoints_ += amount;
	this->energyPoints_--;
	std::cout  << PURPLE << "ClapTrap "<< this->name_
	<< " repairs itself with " << amount << " points. Now its hit-points are "
	<< this->hitPoints_ << ". GREAT\n" << RESET;
}

void	ClapTrap::printValue(){
	std::cout << this->name_ << " current points info:\n";
	std::cout << "hitPoints   : " << hitPoints_ << "\n";
	std::cout << "engeryPoints: " << energyPoints_ << "\n";
	std::cout << "attackDamage: " << attackDamage_ << "\n";
}

void	ClapTrap::setName(const std::string name){
	this->name_ = name;
}
