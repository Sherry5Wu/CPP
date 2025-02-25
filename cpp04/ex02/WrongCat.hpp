/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:59:35 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 07:59:35 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>


class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		// WrongCat(const std::string type);
		WrongCat(const WrongCat& other);
		~WrongCat();

		WrongCat&	operator=(const WrongCat& other);

		void	makeSound() const;
};

#endif //WRONGCAT_HPP
