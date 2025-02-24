/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:40:01 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 09:02:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

#define ORANGE   "\033[1;38;5;214m"

/**
 * @brief here we need to use "virtual public ClapTrap" in stead of "public
 * ClapTrap". Because class ScavTrap and FragTrap are both inherited from
 * ClapTrap, and DiamondTrap will inhert from ScavTrap and FrapTrap, so if we
 * don't use "virtual" here, it will cause the "diamond problem."
 */
class ScavTrap : virtual public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& other);

		void	attack(const std::string& target) override;
		void	guardGate();
};

#endif // SCAVTRAP_HPP
