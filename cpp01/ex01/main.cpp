/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:17:23 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:17:23 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	int	amount = 3;
	Zombie	*array = zombieHorde(amount, "jiang_shi");
	while (--amount >= 0){
		array[amount].announce();
	}
	delete [] array;
	return (0);
}
