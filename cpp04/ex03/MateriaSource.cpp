/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:02:11 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/03 14:08:39 by jingwu           ###   ########.fr       */
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

/**
 * @brief why write the decontructor as this?
 * Because it allows multiple inventories pointing to one object, so if you use
 * nomal delete : 
 *    for (int i = 0; i < AMONUT; i++){
        if (inventory_[i] != nullptr){
            delete inventory_[i];
            inventory_[i] = nullptr;
        }
    }
	Then it might will cause double deletion error, cause segmentation fault.
 */
MateriaSource::~MateriaSource(){
	void*	freeObjects[4] = {nullptr}; // to record the deleted pointers;
	int		freeCount = 0;

	for (int i = 0; i < 4; i++)
	{
		bool	beFreed = false;
		// any inventory_[i] existed in freeObjects[] it means it has been freed,
		// don't need to be freed any more, so need to set checkFree = true.
		for (int j = 0; j < freeCount; j++)
		{
			if (inventory_[i] == freeObjects[j])
			{
				beFreed = true;
				break;
			}
		}
		if (!beFreed)
		{
			freeObjects[freeCount] = inventory_[i];
			delete inventory_[i];
			inventory_[i] = nullptr;
			freeCount++;
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
