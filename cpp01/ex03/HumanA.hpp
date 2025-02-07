#include <string>
#include "Weapon.hpp"

/**
 * @brief here the _weapon is a reference, it means it can
 * Not be null.
 */
class HumanA{
	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		void	attack(void) const;
};