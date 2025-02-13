/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:17:42 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:17:42 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/**
 * @brief The differences bewteen reference and pointer:
 * 1. Memory Address Handling
 * 	- Pointer stores the address of a variable and can be reassigned.
 *  - Reference is an alias for an existing variable and cannot be changed to
 * 	  refer to another variable.
 * 2. Nullability
 * 	- Pointer can be nullptr (not pointing to anything).
 * 	- Reference cannot be null and must be initialized when declared.
 * 3. Reassignment
 *	- Pointer can be reassigned to another variable’s address.
 *	- Reference always refers to the same variable after initialization.
 * 4. Indirection & Dereferencing
 *  - Pointer requires explicit dereferencing (*) to access the value.
 *  - Reference is accessed like a normal variable.
 * 5. Pointer Arithmetic
 *  - Pointer supports arithmetic (increment, decrement, etc.)
 *  - Reference does not support arithmetic.
 * 6. Use Cases
 *  - Pointers are better when:
 *  		- You need dynamic memory allocation (new, delete).
 *  		- You need to work with data structures like linked lists.
 *  		- You need to pass nullptr to indicate "no object."
 *  - References are better when:
 *      - You want to pass parameters efficiently (pass-by-reference).
 *      - You want to return values from functions without copying.
 */
int	main(void){
	std::string	string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string	&stringREF = string;

	// print the the memory address
	std::cout << "Below are addresses:" << std::endl;
	std::cout << "  * string:   " << &string << std::endl;
	std::cout << "  * stringPTR:" << stringPTR << std::endl;
	std::cout << "  * stringREF:" << &stringREF << std::endl;

	// print the values
	std::cout << "\nBelow are values:" << std::endl;
	std::cout << "  * string:   " << string << std::endl;
	std::cout << "  * stringPTR:" << *stringPTR << std::endl;
	std::cout << "  * stringREF:" << stringREF << std::endl;

	return (0);
}
