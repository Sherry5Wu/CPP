/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:20:08 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 11:20:08 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *create_heap_zombie(void){
	std::cout << "A heap_zombie is creating on the heap.\n" << std::endl;
	return newZombie("heap_zombie");
}

void	create_stack_zombie(void){
	std::cout << "\nA stack_zombie is creating on the stack.\n" << std::endl;
	randomChump("stack_zombie");
}

int	main(void){
	Zombie *heap_zombie;

	heap_zombie = create_heap_zombie();
	std::cout << "I am using the heap_zombie outside of the function,"
		<< " I will make it annouce:\n" << std::endl;
	heap_zombie->announce();
	std::cout << "\nWe need always to remember to delete the heap memories after using\n"
		<< std::endl;
	delete(heap_zombie);
	create_stack_zombie();
	return (0);
}
