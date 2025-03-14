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

void    testEnergyPoints(ClapTrap& name){
    std::cout << BLUE << "\nTest for energy points consumption\n" << RESET;

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

int main(){
    std::cout << "Test for ClapTrap:\n\n";
    testCasesForClapTrap();
    return 0;
}

