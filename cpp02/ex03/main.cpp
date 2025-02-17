/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:29 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/13 10:43:29 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static void	checkPoint(Point const a, Point const b, Point const c, Point const point){
	if (bsp(a, b, c, point) == true){
		std::cout << "Point(" << point.getX() << ", " << point.getY() << ") is inside\n";
	}else{
		std::cout << "Point(" << point.getX() << ", " << point.getY() << ") is NOT inside\n";
	}

}

int main( void ) {
	Point	a(0.0f, 0.0f);
	Point	b(4.0f, 0.0f);
	Point	c(0.0f, 4.0f);

	Point	test1(0.0f, 0.0f);
	Point	test2(4.0f, 0.0f);
	Point	test3(1.0f, 2.0f);
	Point	test4(4.0f, 2.3f);

	checkPoint(test1, a, b, c);
	checkPoint(test2, a, b, c);
	checkPoint(a, b, c, test3);
	checkPoint(test4, a, b, c);
}

