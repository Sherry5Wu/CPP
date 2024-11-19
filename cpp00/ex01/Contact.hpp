#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int			_index;

	public:
		Contact();
		Contact(int index,
				std::string first_name,
				std::string last_name,
				std::string nick_name,
				std::string phone_number,
				std::string	darkest_secret);
		void	print_short();
		void	print_long();
};

#endif