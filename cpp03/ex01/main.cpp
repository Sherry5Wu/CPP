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

int main( void ) {
	ClapTrap robot("CT-42");
    robot.attack("Target Dummy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(9);
    robot.attack("Enemy");
    return 0;
}
