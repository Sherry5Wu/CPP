#include "Contact.hpp"

Contact::Contact(){

}

Contact::Contact(int index, std::string first_name, std::string last_name,
			std::string nick_name, std::string phone_number, std::string darkest_secret){
	_index = index;
	_first_name = first_name;
	_last_name = last_name;
	_nick_name = nick_name;
	_phone_number = phone_number;
	_darkest_secret = darkest_secret;
}