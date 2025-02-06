/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:23:04 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 09:23:04 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		enum field{
			FIRSTNAME,
			LASTNAME,
			NICKNAME,
			PHONENUMBER,
			SECRET
		};

	public:
		Contact();

		void	print_prompt(int i);
		void	add_new_contact(int i, std::string &str);
		void	print_short();
		void	print_long();
};

#endif
