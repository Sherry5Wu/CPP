/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:38 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/07 10:26:10 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <sstream> // std::istringstream

class RPN{
	public:
		RPN();
		~RPN();

		void	calculateResult(const std::string& expression);

	private:
		std::stack<int> stack_;

		RPN(const RPN&);
		RPN& operator=(const RPN&);

		void	calculator(std::string& ope);

		// for bebugging
		// void	printStack();
};

int	topNumber(std::stack<int>& stack);
