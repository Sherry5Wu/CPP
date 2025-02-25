/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:58:50 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 07:58:50 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#define RESET "\033[0m"
#define PURPLE "\033[0;35m"

/**
 * 1. What is abstract class?
 *  An abstract class in C++ is a class that cannot be instantiated and is
 * meant to be used as a base class for other classes. It usually defines
 * a common interface for derived classes.
 *
 * 2. How Do You Make a Class Abstract?
 *  A class becomes abstract when it contains at least one pure virtual
 *  function. A pure virtual function is declared by using = 0 in its
 *  prototype.
 */
class Animal{
	protected:
		std::string	type_;

	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal& other);
		virtual	~Animal();

		Animal&	operator=(const Animal& other);

		virtual void	makeSound() const = 0;
		std::string		getType() const;
		void			setType(const std::string newType);
};

#endif
