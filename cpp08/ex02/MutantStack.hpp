/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:45:09 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/21 14:31:41 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		~MutantStack();

		// inherit constructors of std::stack
		using std::stack<T>::stack;
		
		// type aliases for iterator types
		// using this way , we can support vector and list as underlying contatiners
		typedef	typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// with this way, we only support deque as underlying containers
		// using iterator = typename std::deque<T>::iterator;
		// using const_iterator = typename std::deque<T>::const_iterator;
		// using reverse_iterator = typename std::deque<T>::reverse_iterator;
		// using const_reverse_iterator = typename std::deque<T>::const_reverse_iterator;

		// iterator functions
		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"
