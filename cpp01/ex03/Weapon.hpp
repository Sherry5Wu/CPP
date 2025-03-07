/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:18:28 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:18:28 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType(void) const;
		void				setType(const std::string& newType);
};

#endif // WEAPON_HPP
