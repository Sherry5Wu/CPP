/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:40:20 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/17 12:47:00 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <random>
#include <iostream>
#include <ctime> // for std::time()

class Base{
	public:
		virtual	~Base();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
