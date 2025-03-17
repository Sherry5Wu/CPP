/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:11:54 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/17 14:32:22 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T* array, size_t length, F function){
	if (!array){
		std::cout << "Error: passed an empty array\n";
		return ;
	}
	for (size_t i = 0; i < length; i++){
		function(array[i]);
	}
}
