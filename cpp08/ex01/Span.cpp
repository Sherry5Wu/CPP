/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:17:10 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/18 14:52:15 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): n_(0){}

Span::Span(unsigned int n) : n_(n){}

Span::Span(const Span& other) : n_(other.n_), numbers_(other.numbers_){}

Span&	Span::operator=(const Span& other){
	if (this != &other){
		n_ = other.n_;
		numbers_ = other.numbers_;
	}
	return *this;
}

Span::~Span(){}

void	Span::addNumber(int num){
	if (numbers_.size() >= n_){
		throw std::overflow_error("Error: Span is full");
	}
	numbers_.push_back(num);
}

/**
 * This function is for fast insert numbers into Span
 */
void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end){
	if (std::distance(begin, end) > static_cast<int>(n_ - numbers_.size())){
		throw std::overflow_error("Can't add range, Span will exceed its limit");
	}
	numbers_.insert(numbers_.end(), begin, end);
}

int		Span::shortestSpan() const{
	
}

int		Span::longestSpan() const{
	
}
