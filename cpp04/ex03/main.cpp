/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:18 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 14:03:18 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

#define GREEN "\033[1;32m"
#define RESET "\033[0;0m"
#define PURPLE "\033[0;35m"

#if 1
static void	fromSubject(){
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}
#endif

static void	fullyEquip(ICharacter* name, IMateriaSource* src){
	AMateria* tmp;
	for (int i = 0; i < AMONUT; i++){
			if (i < 2){
				tmp = src->createMateria("ice");
				name->equip(tmp);
			} else {
				tmp = src->createMateria("cure");
				name->equip(tmp);
			}
		}
}


#if 1
static void	selfTesting(){
	IMateriaSource* src = new MateriaSource();
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	std::cout << PURPLE << "\n1. testing learning Materias -- positive\n" << RESET;
	src->learnMateria(ice);
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->printInventory();

	std::cout << PURPLE << "\n2. testing learning Materias -- negative\n" << RESET;
	src->learnMateria(nullptr);// test when AMateria is nullptr case


	AMateria* tmp;

	std::cout << PURPLE << "\n3. testing creating Materias"
	<< " -- negative,unknow type and empty string\n" << RESET;
	tmp = src->createMateria("unknow_type");
	tmp = src->createMateria(""); // empty string

	std::cout << PURPLE << "\n4. testing equipment with nullptr AMateria"
	<< " -- negative\n" << RESET;
	ICharacter* jim = new Character("jim");
	jim->equip(tmp); // equip with nullptr tmp;
	jim->printInfo();

	std::cout << PURPLE << "\n5. testing creating Materias and equipment"
	<< " -- postive\n" << RESET;
	fullyEquip(jim, src);
	jim->printInfo();

	std::cout << PURPLE << "\n6. testing equipment -- inventory is full,"
	<< " then try to equip extra materia\n" << RESET;
	tmp = src->createMateria("cure");
	jim->equip(tmp);
	jim->printInfo();

	std::cout << PURPLE << "\n7. testing use function -- idx is out of the range\n"<< RESET;
	ICharacter*	eric = new Character("eric");
	jim->use(-1, *eric);
	jim->use(4, *eric);

	std::cout << PURPLE << "\n8. testing use function -- idx is IN the range\n"<< RESET;
	for (int i = 0; i < AMONUT; i++){
		jim->use(i, *eric);
	}

	std::cout << PURPLE << "\n9. testing use function -- there is no equitment\n"<< RESET;
	for (int i = 0; i < AMONUT; i++){
		eric->use(i, *jim);
	}

	std::cout << PURPLE << "\n10. testing unequip function -- postive case\n"<< RESET;
	jim->printInfo();
	std::cout << "\nUnequip inventory[1]\n";
	Character* jimCopy = dynamic_cast<Character*>(jim);
	AMateria* delete1 = jimCopy->getInventory(1);
	jim->unequip(1);
	jim->printInfo();
	delete delete1;

	std::cout << "\nUnequip inventory[3]\n";
	AMateria* delete2 = jimCopy->getInventory(3);
	jim->unequip(3);
	jim->printInfo();
	delete delete2;

	std::cout << PURPLE << "\n11. testing unequip function -- idx is out of the range\n"<< RESET;
	jim->unequip(-1);
	jim->printInfo();
	jim->unequip(4);
	jim->printInfo();

	std::cout << PURPLE << "\n12. testing unequip function -- unequip empty invetory\n"<< RESET;
	jim->unequip(1);
	jim->printInfo();

	std::cout << "\nAlways remeber to free memories";
	delete eric;
	delete jim;
	delete tmp;
	delete src;
}
#endif

int main()
{
	std::cout << GREEN << "----------------From subject-----------------\n" << RESET;
	fromSubject();

	std::cout << GREEN << "\n--------------More Testing---------------\n" << RESET;
	selfTesting();

	return 0;
}
