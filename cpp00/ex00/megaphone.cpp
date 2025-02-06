/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:22:52 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 09:22:52 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av){
	if (ac > 1){
		for (int i = 1; i < ac; i++){
			for (int j = 0; av[i][j]; j++){
				if (std::isalpha(av[i][j]))
					std::cout << (char)std::toupper(av[i][j]);
				else
					std::cout << av[i][j];
			}
		}
		std::cout << std::endl;
	} else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
