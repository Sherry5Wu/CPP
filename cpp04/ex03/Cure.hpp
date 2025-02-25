/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:38:27 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 13:28:31 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria{
	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		Cure&		operator=(const Cure& other);

		AMateria*	clone() const override;
		void		use(ICharacter& target) override;
};

