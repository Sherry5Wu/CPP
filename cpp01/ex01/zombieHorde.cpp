/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:23:11 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 11:23:11 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name){
	Zombie	*zombie_array = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombie_array->setName(name);
	return (zombie_array);
}
