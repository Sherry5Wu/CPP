/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:17:19 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/21 10:02:14 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <stdexcept>

class Span{
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int num);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan() const;
		int		longestSpan() const;
		
		// for debugging
		void	printNumbers() const;
		void	printShortestSpanNumbers() const;
		void	printLongestSpanNumbers() const;

	private:
		unsigned int		n_;
		std::vector<int>	numbers_;
};
