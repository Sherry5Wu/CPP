/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:44:55 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:44:55 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

#define CYAN "\033[0;36m"
#ifndef RESET
# define RESET "\033[0m"
#endif // RESET

class Brain{
	private:
		std::string	ideas_[100];

	public:
		Brain();
		Brain(const Brain& other);
		virtual ~Brain();

		Brain& operator=(const Brain& other);
};

#endif // BRAIN_HPP
