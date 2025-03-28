/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:45:12 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/28 08:59:36 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other){}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack& other){
	if (this != &other){
		this->~MutantStack();
		new MutantStack(other);
	}
	return *this;
}

template <typename T> MutantStack<T>::~MutantStack(){}


/*----------------------------Iterator Functions-----------------------------*/

/**
 * why we need add "typename" before the return type?
 * In C++, when dealing with dependent types inside template classes or 
 * functions, we need to explicitly specify that something is a type (not a 
 * variable or member) using the typename keyword. Without this, the compiler
 * may be confused and interpret the name as something else.
 * 
 * What is c?????
 * In std::stack, c is the protected member that stores the actual data. 
 * By default, std::stack uses std::deque as its underlying container.
 * 
 */
template <typename T> 
typename MutantStack<T>::iterator	MutantStack<T>::begin(){
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(){
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator			MutantStack<T>::begin() const{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator			MutantStack<T>::end() const{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rbegin(){
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rend(){
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const{
	return this->c.rend();
}
