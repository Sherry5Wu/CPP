/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:36:03 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/18 10:34:05 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

// define color
#define	GREEN	"\033[1;92m"
// #define	RED		"\033[1;91m"
#define PURPLE   "\033[1;35m"  // Bold purple
// #define PINK     "\033[1;38;5;213m"
#define ORANGE   "\033[1;38;5;214m"
#define BLUE   "\033[1;34m"
#define	RESET	"\033[0;0m"

class ClapTrap{
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const std::string name, unsigned int hP, unsigned int eP, unsigned int aD);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap& other);

		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int	amount);
		void	beRepaired(unsigned int	amount);

		// for testing using
		void	printValue();
		void	setName(const std::string name);

	protected:
		std::string		name_;
		unsigned int	hitPoints_;
		unsigned int	energyPoints_;
		unsigned int	attackDamage_;
};

