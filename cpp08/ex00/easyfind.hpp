/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:44:20 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/18 14:16:16 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

/**
 * associative containers: map set
 */

 /**
  * using "typename T::iterator" instead of "T::iterator" is to tell the
  * complier "T::iterator" is a type , not a static member or variable
  */
template <typename T>
typename T::iterator	easyfind(T& container, int num){
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end()){
		throw std::runtime_error("Element " + std::to_string(num) + " is not found");
	}
	return it;
}
