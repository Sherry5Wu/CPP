/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:46:15 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/17 14:04:49 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b){
	return (a < b)? a : b;
}

template <typename T>
const T&	max(const T& a, const T& b){
	return (a > b)? a : b;
}
