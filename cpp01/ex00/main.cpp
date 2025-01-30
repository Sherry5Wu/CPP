#include "Zombie.hpp"

Zombie *create_heap_zombie(void){
	std::cout << "A heap_zombie is creating on the heap." << std::endl;
	return newZombie("heap_zombie");
}

void	create_stack_zombie(void){
	std::cout << "A stack_zombie is creating on the stack." << std::endl;
	randomChump("stack_zombie");
}

int	main(void){
	Zombie *heap_zombie;

	heap_zombie = create_heap_zombie();
	std::cout << "This is how the heap_zombie announce from main" << std::endl;
	heap_zombie->announce();
	std::cout << "We need always to remember to delete the heap zombie after using"
		<< std::endl;
	delete(heap_zombie);
	create_stack_zombie();

	return (0);
}