/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:10:24 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/18 10:14:35 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : data_(nullptr), size_(0){}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n){
	data_ = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other) : size_(other.size_){
	data_ = new T[size_];
	for (unsigned int i = 0; i < size_; i++){
		data_[i] = other.data_[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other){
	if (this != &other){
		delete[] data_;
		size_ = other.size_;
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++){
			data_[i] = other.data_[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array(){
	delete[] data_;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index){
	if (index >= size_){
		throw std::out_of_range("Index is out of bounds");
	}
	return data_[index];
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const{
	if (index >= size_){
		throw std::out_of_range("Index is out of bounds");
	}
	return data_[index];
}

template <typename T>
unsigned int	Array<T>::size() const{
	return size_;
}
