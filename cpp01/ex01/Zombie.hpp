/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:17:31 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:17:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
		void	setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif // ZOMBIE_HPP
