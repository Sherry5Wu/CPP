/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:02:57 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 14:02:57 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#define RESET "\033[0m"
#define PURPLE "\033[0;35m"

class Animal{
	protected:
		std::string	type_;

	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal& other);
		virtual	~Animal();

		Animal&	operator=(const Animal& other);

		virtual void	makeSound() const;
		std::string		getType() const;
		void			setType(const std::string newType);
};

#endif
