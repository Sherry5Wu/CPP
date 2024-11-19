#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook{

	private:
		Contact	_list[8];
		int		_index;
		int		_count;
	public:
		PhoneBook();
		void	add();
		void	search();
};

#endif