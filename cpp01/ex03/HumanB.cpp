#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){}

/**
 * @brief Because the weapon can be NULL, so before to read the
 * content, need check if it exists.
 */
void	HumanB::attack(void) const{
	if (this->_weapon)
	{
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
	}
	else
		std::cout << this->_name << "isn't armed" << std::endl;
}

/**
 * @brief _weapon is a pointer.
 */
void	HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}