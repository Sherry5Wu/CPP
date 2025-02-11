/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:16:53 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:16:53 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Using keyword new to allocate heap memory, it is kinda like 'malloc'
 * in C.
 */
Zombie *newZombie(std::string name){
	Zombie *new_zombie= new Zombie(name);
	return (new_zombie);
}
