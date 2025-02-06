/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:37:02 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 14:37:52 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	_index = 0;
	_count = 0;
}

std::string	get_index(const std::string title){
	std::string	str;

	std::cout << title << std::endl;
	if (!std::getline(std::cin, str)){
		return "";
	}
	return str;
}

void	PhoneBook::add(){
	std::string	input;
	Contact		new_contact;
	int			i;

	for (i = 0; i < 5; i++){
		new_contact.print_prompt(i);
		std::getline(std::cin, input);
		if (input == ""){
			std::cout << RED << "The field can't be empty. Please enter again.\n"
				<< RESET;
			i--;
			continue ;
		}
		else{
			new_contact.add_new_contact(i, input);
		}
	}
	_list[_index] = new_contact;
	_index = (_index + 1) % MAX_CONTACT;
	_count += (_count >= MAX_CONTACT ? 0 : 1);
}

void	PhoneBook::search(){
	std::string	index;
	int			i;

	if (_count == 0){
		std::cout << RED << "The phonebook is empty. Please add contacts first\n"
			<< RESET;
		return ;
	}
	for (i = 0; i < _count; i++){
		std::cout << i + 1 << '|';
		_list[i].print_short();
	}
	while (true){
		std::cout << GREEN << "Please enter the index (1~" << _count << ") to see the full information: "
			<< RESET;
		std::getline(std::cin, index);
		if (index.length() == 1 && index.at(0) >= '1' && index.at(0) < '1' + _count){
			break;
		}
		std::cout << RED << "Invalid index\n" << RESET;
		}
	_list[index.at(0) - '1'].print_long();
}
