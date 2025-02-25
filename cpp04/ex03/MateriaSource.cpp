/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:02:11 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 14:43:43 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < AMONUT; i++){
		inventory_[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other){
	for (int i = 0; i < AMONUT; i++){
		if (other.inventory_[i] == nullptr){
			inventory_[i] = nullptr;
		}else{
			inventory_[i] = other.inventory_[i]->clone();
		}
	}
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < AMONUT; i++){
		if (inventory_[i] != nullptr){
			delete inventory_[i];
			inventory_[i] = nullptr;
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other){
	if (this != &other){
		for (int i = 0; i < AMONUT; i++){
			if (other.inventory_[i] == nullptr){
				inventory_[i] = nullptr;
			}else{
				inventory_[i] = other.inventory_[i]->clone();
			}
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m){
	if (!m){
		std::cout << "LearnMateria--empty m\n"; // for testing only
		return;
	}
	for (int i = 0; i < AMONUT; i++){
		if (inventory_[i] == nullptr){
			inventory_[i] = m;
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < AMONUT; i++){
		if (inventory_[i] && inventory_[i]->getType() == type){
			return (inventory_[i]->clone());
		}
	}
	std::cout << "There is no mattched materia source\n";
	return nullptr;
}

/***************************For testing*****************************/

void	MateriaSource::printInventory(){
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
