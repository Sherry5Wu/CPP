#include <string>
#include "Weapon.hpp"

/**
 * @brief Becasue HumanB may not always have a Weapon,
 * so it can be null, set it to a pointer, not a reference.
 */
class HumanB{
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		HumanB(std::string name);
		void	attack(void) const;
		void	setWeapon(Weapon& weapon);
};