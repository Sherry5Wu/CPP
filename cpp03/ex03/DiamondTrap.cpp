/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:46:52 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 11:01:54 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(),
FragTrap(), name_("default"){
	std::cout << CYAN << "DiamondTrap-- Default constructor called\n" << RESET;
	this->hitPoints_ = FragTrap::hitPoints_;
	this->energyPoints_ = 50;
	this->attackDamage_ = FragTrap::attackDamage_;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"),
	name_(name){
	std::cout << CYAN << "DiamondTrap-- Parameterized constructor called\n" << RESET;
	this->hitPoints_ = FragTrap::hitPoints_;
	this->energyPoints_ = 50;
	this->attackDamage_ = FragTrap::attackDamage_;
}

/**
 *  Why shoud write ClapTrap(other)?
 * 	Because both ScavTrap and FragTrap inherit from ClapTrap, and since ClapTrap
 *  is inherited virtually, it must be explicitly initialized in DiamondTrap.
 */
DiamondTrap::DiamondTrap(const DiamondTrap& other) :
ClapTrap(other.name_ + "_clap_name"), name_(other.name_){
	std::cout << CYAN << "DiamondTrap-- Copy constructor called\n" << RESET;
	this->energyPoints_ = 50;
}

DiamondTrap::~DiamondTrap(){
	std::cout << CYAN << "DiamondTrap-- Deconstructor called. " << this->name_ 
	<< " has been destoryed!\n"<< RESET;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other){
	std::cout << CYAN << "DiamondTrap-- Assignment operator called\n" << RESET;
	if (this != &other){
		this->name_ = other.name_;
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
	}
	return *this;
}

void	DiamondTrap::attack(const std::string& traget){
	std::cout << CYAN << "DiamondTrap's attack\n" << RESET;
	ScavTrap::attack(traget);
}

void	DiamondTrap::whoAmI(){
	std::cout << CYAN << "\nWho Am I:\n";
	std::cout << CYAN << " * My name is: " << this->name_ << "\n";
	std::cout << CYAN << " * My ClapTrap name is: " << ClapTrap::name_ << "\n"<< RESET;
}

void	DiamondTrap::printMyValue(){
	std::cout << CYAN << " * hitPoints: " << this->hitPoints_ << "\n";
	std::cout << CYAN << " * energyPoints: " << this->energyPoints_ << "\n";
	std::cout << CYAN << " * attackDamage: " << this->attackDamage_ << "\n\n" << RESET;
}
