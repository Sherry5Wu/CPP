/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:23:24 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/06 09:23:24 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

#define	GREEN	"\033[1;92m"
#define	RED		"\033[1;91m"
#define	RESET	"\033[0;0m"
#define	MAX_CONTACT	2 // change to 8

std::string	get_index(const std::string title);

class PhoneBook{

	private:
		Contact	_list[MAX_CONTACT];
		int		_index;
		int		_count;

	public:
		PhoneBook(void);
		void	add(void);
		void	search(void);
};

#endif
