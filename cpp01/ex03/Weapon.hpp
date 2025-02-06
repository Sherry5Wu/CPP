/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:23:36 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 11:23:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon{
	private:
		std::string	_type;

	public:
		Weapon(std::string type) : _type(type){};
		const std::string&	getType(void) const;
		void				setType(const std::string& newType);
};

#endif
