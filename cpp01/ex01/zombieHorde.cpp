/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:17:36 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:17:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	Zombie	*zombie_array = new Zombie[N];

	for (int i = 0; i < N; i++){
		zombie_array[i].setName(name);
	}
	return (zombie_array);
}
