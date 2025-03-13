/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:18 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 14:03:18 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0;0m"



int main(int ac, char** av){
// test cases: 0.0ff, 234ad, 10e500,3478374834593874589478234234234.9398
	(void)ac;

	try{
		size_t	pos;
		float	num = std::stof(av[1], &pos);
		std::cout <<"num: " << num << std::endl;
		std::cout <<"pos: " << pos << std::endl;
		return 0;
	} catch (const std::out_of_range& e){
		std::cout << "out of range\n";
		return 1;
	} catch (const std::invalid_argument& e){
		std::cout << "invalid_argument\n";
		return 1;
	} catch (const std::exception& e){
		std::cout << "Error: " << e.what()<< std::endl;
	}
}

