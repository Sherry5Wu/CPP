/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:12 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/13 10:43:12 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void    testEnergyPoints(ClapTrap& name){
    std::cout << BLUE << "Test for energy points consumption\n" << RESET;

    for (int i = 0; i < 10 ; i++){
        name.attack("nobody");
    }
    name.printValue();
    name.beRepaired(3);
    name.attack("nodody");
    name.takeDamage(4);
}

void    testCasesForClapTrap(){
    std::cout << "Test for ClapTrap:\n";
    ClapTrap    robot;
    robot.printValue();
    std::cout << std::endl;
    ClapTrap    robotA("R-42");
    robotA.printValue();

    robotA.attack("name");
    robotA.takeDamage(5);
    robotA.beRepaired(3);
    robotA.takeDamage(9);
    robotA.beRepaired(1);

    robot.setName("Happy-Robot");
    testEnergyPoints(robot);

}

void    testCasesForScavTrap(){
    std::cout << GREEN << "\nTest for ScavTrap:\n" << RESET;
    ScavTrap    bee;
    bee.printValue();
    std::cout << std::endl;
    ScavTrap    beeA("Bumble-Bee");
    beeA.printValue();
    beeA.attack("bee");
    beeA.printValue();
    beeA.takeDamage(5);
    beeA.printValue();
    beeA.beRepaired(3);
    beeA.printValue();
    beeA.guardGate();
}

void    testCasesForFragTrap(){
    std::cout << GREEN << "\nTest for FragTrap:\n" << RESET;
    FragTrap    f;
    f.printValue();
    std::cout << std::endl;
    FragTrap    frag("Frag");
    frag.printValue();
    frag.attack("little-frag");
    frag.printValue();
    frag.takeDamage(5);
    frag.printValue();
    frag.beRepaired(3);
    frag.printValue();
    frag.highFivesGuys();

    std::cout << GREEN << "\nAssignment operator test:\n" << RESET;
    FragTrap    littleGuy;
    FragTrap    nameGuy("name");
    littleGuy.printValue();
    littleGuy = nameGuy;
    littleGuy.printValue();
}

int main(){
    // testCasesForClapTrap();
    // testCasesForScavTrap();
    testCasesForFragTrap();
    return 0;
}

