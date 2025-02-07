#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type){
	std::cout << "This is the constructor of Weapon" << std::endl;
}

// Here this->_type equals _type
const std::string&	Weapon::getType(void) const{
	return (this->_type);
}

void	Weapon::setType(const std::string& newType){
	this->_type = newType;
}