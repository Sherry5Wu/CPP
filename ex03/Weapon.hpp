#include <string>

class Weapon{
	private:
		std::string	_type;

	public:
		Weapon(std::string type) : _type(type){};
		const std::string&	getType(void) const;
		void				setType(const std::string& newType);
};