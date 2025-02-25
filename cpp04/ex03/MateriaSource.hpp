/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:58:40 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 14:04:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

#ifndef AMONUT
# define AMONUT (4)
#endif // AMONUT

class MateriaSource : public IMateriaSource{
	private:
		AMateria	*inventory_[AMONUT];
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource&	operator=(const MateriaSource& other);
		void			learnMateria(AMateria* m) override;
		AMateria*		createMateria(std::string const & type) override;
		
		// for testing
		void	printInventory() override;
};
