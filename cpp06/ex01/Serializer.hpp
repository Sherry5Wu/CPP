/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:47:31 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/17 10:18:08 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint> // uintptr_t
#include "Data.hpp"

/**
 * For modern C++ (C++11 and later) → Use "= delete" to prevent some functions
 */
class Serializer{
	public:
		Serializer() = delete; // can't initialized by user
		Serializer(const Serializer&) = delete; // can't copied by user
		~Serializer() = delete;
		Serializer&	operator=(const Serializer&)= delete;
		
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
