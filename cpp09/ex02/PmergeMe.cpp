/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:32:20 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/08 10:15:38 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


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

    // Step 3: Insert the elements in group B into the sorted A.
    // Here, binary search is used for insertion to simulate the effect of
    // optimized insertion
    for (int num : B){
        binaryInsert(A, num);
    }

    // Assign the sorted A back to the original array
    con = A;
}

// define like this is for limited the container just can be vector and deque
template<typename T>
typename std::enable_if<
    std::is_same<T, std::vector<typename T::value_type>>::value ||
    std::is_same<T, std::deque<typename T::value_type>>::value,
    void
    >::type
PmergeMe::binaryInsert(T& con, int num){
    int left = 0;
    int right = con.size();

    while (left < right){
        int mid = left + (right - left) / 2;
        if (num < con[mid]){
            right = mid;
        }else {
            left = mid + 1;
        }
    }
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
