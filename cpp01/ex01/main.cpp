/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:23:01 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 11:23:01 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	int	amount;
	Zombie	*array;

	amount = 5;
	array = zombieHorde(amount, "jiang_shi");
	while (--amount >= 0)
		array[amount].announce();
	delete [] array;
	return (0);
}
