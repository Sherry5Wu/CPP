/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:19:58 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/11 08:19:58 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void){
	PhoneBook	book= PhoneBook();
	std::string	input;

	while (true){
		std::cout << GREEN << "Enter your choice (ADD/SEARCH/EXIT): " << RESET;
		std::getline(std::cin, input);
		if (input == "ADD"){
				book.add();
		}
		else if (input == "SEARCH"){
			book.search();
		}
		else if (input == "EXIT"){
				break ;
		}
		else{
			std::cout << RED << "Invalid input\n" << RESET;
		}
	}
	return 0;
}

