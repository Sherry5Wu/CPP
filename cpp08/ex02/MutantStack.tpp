/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:45:12 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/21 14:03:18 by jingwu           ###   ########.fr       */
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

// ?? why we need add "typename" before the return type??????
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
