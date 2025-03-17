/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:40:24 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/17 13:18:38 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base*	generate(void){
	std::srand(std::time(0)); // set a seed;
	int	num = rand() % 3;

	switch(num){
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

/**
 *  Understand dynamic_cast
 *  -- Runtime checking: It performs conversions at runtime, making it safer than
 *     static_cast.
 *  -- Runtime overhead: Since it checks the type of the object during execution,
 *     it incurs some performance overhead compared to static_cast.
 *  -- Safety: It ensures that the cast is valid, and if it is not, it returns nullptr
 *     (for pointers) or throws std::bad_cast (for references) without causing undefined
 *      behavior.
 *  -- Used for polymorphism: It's commonly used when working with polymorphic types
 * 	    (i.e., when you have a class hierarchy with virtual functions).
 */
void	identify(Base* p){
	std::cout << "The actual type of the object pointed to by p is:";
	if (!p){
		std::cout << "Error: P is an nullptr\n";
	} else if (dynamic_cast<A*>(p)){
		std::cout << "A\n";
	} else if (dynamic_cast<B*>(p)){
		std::cout << "B\n";
	} else if (dynamic_cast<C*>(p)){
		std::cout << "C\n";
	} else {
		std::cout << "unknow type\n";
	}
}

void	identify(Base& p){
	std::cout << "The actual type of the object pointed to by p is:";
	
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	} catch (const std::exception& e){
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B\n";
		} catch (const std::exception& e){
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C\n";
			} catch (const std::exception& e){
				std::cout << "unknow type\n";
			}
		}
	}
}
