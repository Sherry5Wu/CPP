#include "PhoneBook.hpp"
#include "Contact.hpp"

#if 1
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
#endif

#if 0
int main (void){
	PhoneBook	book= PhoneBook();
	std::string	input;
	Contact		new_contact;

	// add 8 contacts here
	std::string	first_name[8][5] = {
		{"Ling", "wang", "xing", "012345678", "secret"},
		{"Bobcatdoghot", "Ericlksishshs", "happy", "01234567812345", "this is a very long secret"},
		{"Jimmy", "Wong", "Bigjoker", "012345678", "secret"},
		{"Linda", "Kerttunen", "xing", "5631489554", "secrettttttt"},
		{"Ruby", "hao", "xing", "012345678", "secret"},
		{"Tidy", "ying", "ning", "012345678", "secret"},
		{"Ericlo", "wang", "xing", "012345678", "secret"},
		{"Rebeca", "wang", "han", "012345678", "secret"}
	};
	for (int i = 0; i < 8; i++){
		for(int j = 0; j < 5; j++){
			new_contact.add_new_contact(j, first_name[i][j]);
		}
		book._list[i] = new_contact;
		book._index++;
	}

	// start the program
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
#endif
