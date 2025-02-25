/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:59:08 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 07:59:08 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

class Cat : public Animal{
	public:
		Cat();
		Cat(const std::string type);
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);

		void	makeSound() const override;
	private:
		Brain*	brain_;
};

#endif //CAT_HPP
