/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:47:49 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 09:13:44 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

#define BLUE   "\033[1;34m"

/**
 * @brief here we need to use "virtual public ClapTrap" in stead of "public
 * ClapTrap". Because class ScavTrap and FragTrap are both inherited from
 * ClapTrap, and DiamondTrap will inhert from ScavTrap and FrapTrap, so if we
 * don't use "virtual" here, it will cause the "diamond problem."
 */
class FragTrap : virtual public ClapTrap{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& other);

		void	attack(const std::string& target) override;
		void	highFivesGuys();
};

#endif // FRAGTRAP_HPP
