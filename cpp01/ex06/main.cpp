/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:19:35 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:19:35 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av){
	Harl	harl;

	if (ac != 2){
		std::cerr << "Error\nThe program takes and only take one parameter"
			<< std::endl;
		std::cout << "Valid inputs: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	harl.complain(av[1]);
	return (0);
}
