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

/**
 * A reference (&) in C++ is an alias for an existing variable. It must have the same
 * type as the variable it refers to.
 *
 * The differences bewteen reference and pointer:
 *	- References (&) = safer, easier to use, but cannot be null or reassigned.
	- Pointers (*) = more flexible (can be null, can be reassigned), but require more care.
	If an object must always exist, use a reference.
	If it can be null or change targets, use a pointer.

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

/*
	How to Decide Whether to Use References for Return Values and Arguments in a Member Function
	When designing a class member function, choosing whether to use references (&), pointers (*),
	or values depends on efficiency, mutability, and ownership. Here’s how you can decide:
	1. Should Function Arguments Use References?
	Use references to avoid unnecessary copies and improve efficiency.

					Case	                                   Use Pass by Reference (&)     	            Use Pass by Value
		Large objects (e.g., class instances, structs)	    ✅ Avoids copying large data.	          ❌ Copying is expensive.
		Objects that should not be modified	                ✅ Use const T& to prevent changes.	      ❌ Copies are modifiable.
		Small built-in types (int, char, float)	            ❌ Passing by reference is not needed.	  ✅ Faster for simple types.
		Function modifies the argument	                    ✅ Use T& to allow modification.	          ❌ Copies won't reflect changes.

	2. Should the Return Type Use a Reference?
	Use references when you want to return an existing object without copying it.

		         Case	                                       Use Return by Reference (&)	                 Use Return by Value
		Returning an object owned by the class	            ✅ Prevents copying.	                       ❌ Copying is expensive.
		Returning a local variable	                        ❌ Local variables cannot be returned       ✅ Safe, avoids dangling references.
		                                                        by reference.
		Returning a constant object that                    ✅ Use const T& to prevent modification.	   ❌ Copying might be unnecessary.
		should not be modified
		Returning a calculated temporary value	            ❌ Temporary values must be returned        ✅ Prevents dangling references.
		                                                       by value.

*/
