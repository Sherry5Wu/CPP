/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:36:03 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/17 14:54:45 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap{
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const std::string name, unsigned int hP, unsigned int eP, unsigned int aD);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap& other);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	beRepaired(unsigned int	amount);

	protected:
		std::string		name_;
		unsigned int	hitPoints_;
		unsigned int	energyPoints_;
		unsigned int	attackDamage_;
};
