/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:18:53 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:18:53 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "CopyReplace.hpp"

int	main(int ac, char **av){
	if (ac != 4)
	{
		std::cerr << "Error\nThe program takes and only takes 3 parameters\n";
		return (1);
	}
	std::string	fileName = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	//create an instance of CopyReplay and process the file
	CopyReplace copier(fileName, s1, s2);
	if(!copier.process()){
		return (1);
	}
	return (0);
}
