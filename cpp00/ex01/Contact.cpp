/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:19:30 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/11 08:19:30 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}

void	Contact::print_prompt(int i){
	std::cout<< std::left;
	switch (i){
		case FIRSTNAME:
			std::cout << std::setw(15) << "First name: ";
			break ;
		case LASTNAME:
			std::cout << std::setw(15) << "Last name: ";
			break ;
		case NICKNAME:
			std::cout << std::setw(15) << "Nickname: ";
			break ;
		case PHONENUMBER:
			std::cout << std::setw(15) << "Phonenumber: ";
			break ;
		case SECRET:
			std::cout << std::setw(15) << "Darkest secret: ";
			break ;
		default:
			std::cout << "Invalid promt\n";
			break ;
	}
}

void	Contact::add_new_contact(int i, std::string &str){
	switch (i)
	{
	case FIRSTNAME:
		_first_name = str;
		break;
	case LASTNAME:
		_last_name = str;
		break ;
	case NICKNAME:
		_nickname = str;
		break ;
	case PHONENUMBER:
		_phone_number = str;
		break ;
	case SECRET:
		_darkest_secret = str;
		break ;
	default:
		std::cout << "Invalid index\n";
		break;
	}
}

std::string	truncated_str(std::string str){
	return (str.length() > 10 ? (str.substr(0, 9) + ".") : str);
}

void	Contact::print_short(){
	std::cout << std::setw(10) << truncated_str(_first_name) << "|";
	std::cout << std::setw(10) << truncated_str(_last_name) << "|";
	std::cout << std::setw(10) << truncated_str(_nickname) << std::endl;
}

void	Contact::print_long(){
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}
