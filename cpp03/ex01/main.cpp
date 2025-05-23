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
    std::cout << "Testing default constructor:\n";
    ScavTrap    bee;
    bee.printValue();

    std::cout << "\nTesting parameteried constructor:\n";
    ScavTrap    beeA("Bumble-Bee");
    beeA.printValue();

    std::cout << "\nTesting attack and repair function\n";
    beeA.attack("bee");
    beeA.printValue();
    beeA.takeDamage(5);
    beeA.printValue();
    beeA.beRepaired(3);
    beeA.printValue();
    beeA.guardGate();

    std::cout << "\nTesting copy constructor:\n";
    ScavTrap    copyBeeA(beeA);
    copyBeeA.printValue();

    std::cout << "\nTesting assignment operator\n";
    bee = beeA;
    bee.printValue();
}

int main(){
    // std::cout << "Test for ClapTrap:\n\n";
    // testCasesForClapTrap();

    std::cout << "\nTest for ScavTrap:\n\n";
    testCasesForScavTrap();
    return 0;
}

