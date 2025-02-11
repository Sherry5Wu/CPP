/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:17:55 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:17:55 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

/**
 * @brief here the _weapon is a reference, it means it can
 * Not be null.
 */
class HumanA{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack(void) const;
};

#endif // HUMANA_HPP
