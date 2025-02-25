/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:34:39 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 14:37:09 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name_("default_name"){
	for (int i = 0; i < AMONUT; i++){
		inventory_[i] = nullptr;
	}
}

Character::Character(const std::string name):name_(name){
	for (int i = 0; i < AMONUT; i++){
		inventory_[i] = nullptr;
	}
}

Character::Character(const Character& other):name_(other.name_){
	for (int i = 0; i < AMONUT; i++){
		if (other.inventory_[i] == nullptr)
				inventory_[i] = nullptr;
			else
				inventory_[i] = other.inventory_[i]->clone();
	}
}

Character::~Character(){
	for (int i = 0; i < AMONUT; i++){
		if (inventory_[i] != nullptr){
			delete inventory_[i];
			inventory_[i] = nullptr;
		}
	}
}

Character&	Character::operator=(const Character& other){
	if (this != &other){
		name_ = other.name_;
		for (int i = 0; i < AMONUT; i++){
			if (inventory_[i] != nullptr){
				delete inventory_[i];
				inventory_[i] = nullptr;
			}
			if (other.inventory_[i] == nullptr)
				inventory_[i] = nullptr;
			else
				inventory_[i] = other.inventory_[i]->clone();
		}
	}
	return *this;
}

std::string const &	Character::getName() const{
	return	name_;
}

void	Character::equip(AMateria* m){
	if (m == nullptr)
		return ;
	for (int i = 0; i < AMONUT; i++){
		if (inventory_[i] == nullptr){
			inventory_[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx){
	if (idx < AMONUT && idx >= 0 && inventory_[idx]){
		inventory_[idx] = nullptr;
	}
}

void	Character::use(int idx, ICharacter& target){
	if (idx < AMONUT && idx >= 0 && inventory_[idx]){
		inventory_[idx]->use(target);
	}

}

/***************************For testing*****************************/
#define DARK_YELLOW "\033[1;33m"
#define RESET "\033[0;0m"

void	Character::printInfo(){
	std::cout << "\nname is " << DARK_YELLOW << name_ << RESET <<"\n";
	std::cout << "Inventory are:\n";
	for (int i = 0; i < AMONUT; i++){
		if (inventory_[i] == nullptr){
			std::cout << " * Inventory " << i << " is empty\n";
		}else{
			std::cout << " * Inventory " << i << " is "<< inventory_[i]->getType()
			<< "\n";
		}
	}
}
