/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:59:17 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 07:59:17 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#define DARK_YELLOW "\033[0;33m"


class Dog : public Animal{
	public:
		Dog();
		Dog(const std::string type);
		Dog(const Dog& other);
		~Dog();

		Dog&	operator=(const Dog& other);

		void	makeSound() const override;

	private:
		Brain*	brain_;
};

#endif // DOG_HPP
