/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:34:35 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:21:33 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

#define AMONUT (4)

class Character : public ICharacter{
	private:
		std::string	name_;
		AMateria	*inventory_[AMONUT];

	public:
		Character();
		Character(const std::string name);
		Character(const Character& other);
		~Character();

		Character&			operator=(const Character& other);
		std::string	const	&getName() const override;
		void 				equip(AMateria* m) override;
		void 				unequip(int idx) override;
		void 				use(int idx, ICharacter& target) override;

		// for testing
		void		printInfo() override;
		AMateria*	getInventory(int idx);
};
