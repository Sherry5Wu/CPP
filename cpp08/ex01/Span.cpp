/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:17:10 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/21 12:37:17 by jingwu           ###   ########.fr       */
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
		throw std::overflow_error("Error: Can't add range, Span will exceed its limit");
	}
	numbers_.insert(numbers_.end(), begin, end);
}

int		Span::shortestSpan() const{
	if (numbers_.size() < 2){
		throw std::logic_error("Error: Not enough numbers to find a span.");
	}
	std::vector<int>	sorted(numbers_);
	std::sort(sorted.begin(), sorted.end());
	int	minSpan = sorted[1] - sorted[0];

	// The return type of function size() is size_t
	for (size_t i = 1; i < sorted.size() - 1; i++){
		minSpan = std::min(minSpan, (sorted[i + 1] - sorted[i]));
	}
	return minSpan;
}

int		Span::longestSpan() const{
	if (numbers_.size() < 2){
		throw std::logic_error("Error: Not enough numbers to find a span");
	}

	// the returns of std::max_element and std::min_element are interator.
	return (*std::max_element(numbers_.begin(), numbers_.end())
			- *std::min_element(numbers_.begin(), numbers_.end()));
}

/*--------------------------------For debugging---------------------------------------*/
void	Span::printNumbers() const{
	std::cout << "Numbers are: ";
    for (size_t i = 0; i < numbers_.size(); i++){
        std::cout << numbers_[i] << ", ";
    }
    std::cout << std::endl;
}

void	Span::printShortestSpanNumbers() const{
	int	shorestSpan = this->shortestSpan();
	std::vector<int>	sorted(numbers_);
	std::sort(sorted.begin(), sorted.end());
	for (size_t i = 0; i < sorted.size() - 1; i++){
		if ( (sorted[i + 1] - sorted[i]) == shorestSpan){
			std::cout << "Shortest Span numbers are: " << sorted[i] << " and " << sorted[i + 1] << std::endl;
			std::cout << std::endl;
		}
	}
}

void	Span::printLongestSpanNumbers() const{
	std::cout << "Longest Span numbers are: ";
	std::cout << *std::min_element(numbers_.begin(), numbers_.end());
	std::cout << " and ";
	std::cout << *std::max_element(numbers_.begin(), numbers_.end());
	std::cout << std::endl;
}
