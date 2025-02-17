/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:16:46 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/17 10:10:49 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/**
 * @brief We use a helper function sign to calculate a “signed area” that helps
 * determine on which side of a line a point lies.
 * If any of these areas is zero, the point is on an edge or vertex, so we
 * return false. Otherwise, we check if all three values are either positive or
 * negative. If they are, the point is strictly inside the triangle.
 *
 */
static Fixed	sign(Point const point, Point const p1, Point const p2){
	return ((point.getX() - p2.getX()) * (p1.getY() - p2.getY()))
			- ((p1.getX() - p2.getX()) * (point.getY() - p2.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);

	// Checking for collinearity: if any of the signs is zero, the point lies
	// on one of the triangle's edges or coincides with a vertex.
	bool onEdge = (d1 == 0 || d2 == 0 || d3 == 0);

	// the point is inside if all three have the same sign
	bool inside = ((d1 > 0 && d2 > 0 && d3 > 0)
				|| (d1 < 0 && d2 < 0 && d3 < 0));

	//True if the point is inside the triangle. False otherwise.
	return inside && !onEdge;
}
