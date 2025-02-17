/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:16:52 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/14 14:59:46 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(0), y_(0){}

Point::Point(const float x, const float y) : x_(x), y_(y){}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_){}

Point::~Point(){}

Point&	Point::operator=(const Point& other){
	(void)other;
	return *this;
}

Fixed	Point::getX() const{
	return (this->x_);
}

Fixed	Point::getY() const{
	return (this->y_);
}
