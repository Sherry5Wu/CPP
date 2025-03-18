/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 08:51:11 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/18 09:47:25 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array();
		
		// tp support non const object
		T&	operator[](unsigned int index);
		// to support const object, to make code more robust and flexible
		const T&	operator[](unsigned int index) const;
		unsigned int	size() const;
	
	private:
		T*				data_;
		unsigned int	size_;
};


// The .tpp file is included at the end of the .hpp file to ensure the
// compiler sees the implementation when needed.
#include "Array.tpp"
