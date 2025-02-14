/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:10:26 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/14 14:40:06 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

class Point
{
	private:
		const Fixed	x_;
		const Fixed	y_;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		~Point();
		Point&	operator=(const Point& other);

		Fixed	getX() const;
		Fixed	getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

