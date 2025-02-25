/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:38:27 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 09:43:05 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria{
	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice&		operator=(const Ice& other);

		AMateria*	clone() const override;
		void		use(ICharacter& target) override;
};

