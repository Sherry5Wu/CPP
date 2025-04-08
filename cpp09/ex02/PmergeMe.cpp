/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:32:20 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/08 15:51:10 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>


PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}


/**
 * @brief Loop the passed arguments, if found the invalid charactor or number,
 * throw an error; otherwise, push the number into the vector.
 */
void    PmergeMe::importDataToVector(char** av){
    int num;
    char rest;

    while (*av){
        // Wraps the current string (*av) in an std::istringstream,
        // which allows you to extract formatted data (like an int) from a string.
        std::istringstream token(*av);

        // If the first part can't be parsed into an int, or If anything else
        // remains in the string after extracting the integer, then it is invalid
        // throw an error. like "42ab"
        // (token >> num): parsing token into an int
        if (!(token >> num) || token >> rest){
            throw (std::runtime_error("Error"));
        }
        if (num < 0){
            throw (std::runtime_error("Error"));
        }
        vecArray_.push_back(num);
        av++;
    }
}

/**
 * @brief Loop the passed arguments, if found the invalid charactor or number,
 * throw an error; otherwise, push the number into the deque.
 */
void    PmergeMe::importDataToDeque(char ** av){
    int num;
    char rest;

    while (*av){
        // Wraps the current string (*av) in an std::istringstream,
        // which allows you to extract formatted data (like an int) from a string.
        std::istringstream token(*av);

        // If the first part can't be parsed into an int, or If anything else
        // remains in the string after extracting the integer, then it is invalid
        // throw an error. like "42ab"
        // (token >> num): parsing token into an int
        if (!(token >> num) || token >> rest){
            throw (std::runtime_error("Error"));
        }
        if (num < 0){
            throw (std::runtime_error("Error"));
        }
        deqArray_.push_back(num);
        av++;
    }
}

template<typename T>
typename std::enable_if<
    std::is_same<T, std::vector<typename T::value_type>>::value ||
    std::is_same<T, std::deque<typename T::value_type>>::value,
    void
    >::type
PmergeMe::printContainer(T& con){
    for (int i : con){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template<typename T>
typename std::enable_if<
    std::is_same<T, std::vector<typename T::value_type>>::value ||
    std::is_same<T, std::deque<typename T::value_type>>::value,
    void
    >::type
PmergeMe::mergeSort(T& con){
    int size = con.size();

    if (size <= 1){
        return;
    }

    // Step 1: paring
    T   A; // saving bigger values
    T   B; // saving smaller values;
    for (int i = 0; i < size - 1; i += 2){
        // push the bigger one into A, the smaller one into B
        if (con[i] < con[i + 1]){
            A.push_back(con[i + 1]);
            B.push_back(con[i]);
        } else {
            A.push_back(con[i]);
            B.push_back(con[i + 1]);
        }
    }
    // if there are odd amount numbers, push the last number into A directly
    if (size % 2 == 1){
        A.push_back(con[size - 1]);
    }

    // Step 2: recursivly sort A
    PmergeMe::mergeSort(A);

    // Step3: get the insert order array
    std::vector<size_t> insertionOrder = generateJacobsthalOrder(B.size());


    // Step 4: Insert the elements in group B into the sorted A.
    for (size_t idx : insertionOrder){
        if (idx < B.size()){
            binaryInsert(A, B[idx]);
        }
    }

    // Assign the sorted A back to the original array
    con = A;
}

/**
 * @brief Generates an insertion order based on the size of group B using the
 * properties of the Jacobsthal sequence.
 * 
 * Algorithm idea:
 * 1. Generate Jacobsthal numbers using the closed-form expression J(n) = (2^n - (-1)^n) / 3,
 *    until J(n) >= the size of group B.
 * 2. Use these values to create an index sequence (note: indexing starts from 0).
 * 3. To simplify the explanation, we first use the Jacobsthal numbers as candidate indices,
 *    then fill in any remaining unselected indices in sequential order.
 *
 * @param bSize The number of elements in group B.
 * @return std::vector<size_t> The insertion order as an index sequence.
 */
std::vector<size_t> PmergeMe::generateJacobsthalOrder(size_t bSize){
    std::vector<size_t> order;
    std::vector<bool> used(bSize, false);
    // generate Jacobsthal numbers as more as possbile(but the index
    // can't greater than bsize)
    size_t n = 1;
    while (true) {
        // calculate J(n) = (2^n - (-1)^n) / 3
        size_t j = (static_cast<size_t>(std::pow(2.0, n)) - (n % 2 == 0 ? 1 : -1) ) / 3;
        if (j >= bSize) break;
        if (!used[j]) {
            order.push_back(j);
            used[j] = true;
        }
        n++;
    }
    // Complete the remaining unselected subscripts in sequence to ensure that
    // all elements can be inserted
    for (size_t i = 0; i < bSize; ++i) {
        if (!used[i]) {
            order.push_back(i);
        }
    }
    return order;
}

/**
 * @brief based on the binary search
 */
// define like this is for limited the container just can be vector and deque
template<typename T>
typename std::enable_if<
    std::is_same<T, std::vector<typename T::value_type>>::value ||
    std::is_same<T, std::deque<typename T::value_type>>::value,
    void
    >::type
PmergeMe::binaryInsert(T& con, int num){
    // start from the beging of the container
    int left = 0;
    // end at the end of the contatiner
    int right = con.size();

    // if (left < right) means there are still elements we can search
    while (left < right){
        // find the middle position
        int mid = left + (right - left) / 2;
        if (num < con[mid]){
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    // the left location is the location we should insert num.
    con.insert(con.begin() + left, num);
}

void    PmergeMe::vectorSort(){
    PmergeMe::mergeSort(vecArray_);
}

void    PmergeMe::dequeSort(){
    PmergeMe::mergeSort(deqArray_);
}

void    PmergeMe::vectorPrint_(){
    PmergeMe::printContainer(vecArray_);
}

void    PmergeMe::dequePrint_(){
    PmergeMe::printContainer(deqArray_);
}
