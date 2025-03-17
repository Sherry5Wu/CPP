/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:46:32 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/17 08:46:32 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <string>
#include "D.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}

static void	pointerIdentifyTesting(){
	printInColor("\n1. pass a nullptr to indentify:", PURPLE);
	identify(nullptr);

	printInColor("\n2. pass a nll A, B, C type to indentify:", PURPLE);
	Base* unknow = new D();
	identify(unknow);

	printInColor("\n3. Random generating, the type are:", PURPLE);
	Base* random = generate();
	identify(random);

	printInColor("\n4. Pass type A", PURPLE);
	Base*	a = new A();
	identify(a);

	printInColor("\n5. Pass type B", PURPLE);
	Base*	b = new B();
	identify(b);

	printInColor("\n6. Pass type C", PURPLE);
	Base*	c = new C();
	identify(c);

	delete unknow;
	delete random;
	delete a;
	delete b;
	delete c;
}

static void	referenceIdentifyTesting(){
	printInColor("\n1. Pass type A", PURPLE);
	A	type_a;
	identify(type_a);

	printInColor("\n2. Pass type B", PURPLE);
	B	type_b;
	identify(type_b);

	printInColor("\n3. Pass type C", PURPLE);
	C	type_c;
	identify(type_c);

	printInColor("\n4. Pass type unknow", PURPLE);
	D	type_d;
	identify(type_d);
}

int main() {

	printInColor("\n<-----Indentify pointers function------>", GREEN);
	pointerIdentifyTesting();


	printInColor("\n<-----Indentify reference function------>", GREEN);
	referenceIdentifyTesting();

	return 0;
}
