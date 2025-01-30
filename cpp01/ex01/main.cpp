#include "Zombie.hpp"

int	main(void){
	int	amount;
	Zombie	*array;

	amount = 5;
	array = zombieHorde(amount, "jiang_shi");
	while (--amount >= 0)
		array[amount].announce();
	delete [] array;
	return (0);
}