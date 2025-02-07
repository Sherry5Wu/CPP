#include <iostream>

int main(int ac, char **av){
	int	i;
	int	j;

	i = 1;
	if (ac > 1){
		while (i < ac){
			j = 0;
			while (av[i][j]){
				if (std::isalpha(av[i][j]))
					std::cout << (char)std::toupper(av[i][j]);
				else
					std::cout << av[i][j];
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	} else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}