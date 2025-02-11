/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:18:02 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:18:02 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

/**
 * @brief Becasue HumanB may not always have a Weapon,
 * so it can be null, set it to a pointer, not a reference.
 */
class HumanB{
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif // HUMANB_HPP
