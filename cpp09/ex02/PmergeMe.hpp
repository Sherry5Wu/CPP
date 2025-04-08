/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:32:16 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/08 13:48:45 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <type_traits>

class PmergeMe{
    public:
        PmergeMe();
        ~PmergeMe();

        void    importDataToVector(char** av);
        void    importDataToDeque(char ** av);
        void    vectorSort();
        void    dequeSort();
        void    vectorPrint_();
        void    dequePrint_();

    private:
        std::vector<int> vecArray_;
        std::deque<int> deqArray_;

        PmergeMe(const PmergeMe&);
        PmergeMe& operator=(const PmergeMe&);

        // define like this is for limited the container just can be vector and deque
        template<typename T>
        static typename std::enable_if<
        std::is_same<T, std::vector<typename T::value_type>>::value ||
        std::is_same<T, std::deque<typename T::value_type>>::value,
        void
        >::type
        printContainer(T& con);

        template<typename T>
        static typename std::enable_if<
        std::is_same<T, std::vector<typename T::value_type>>::value ||
        std::is_same<T, std::deque<typename T::value_type>>::value,
        void
        >::type
        mergeSort(T& con);

        template<typename T>
        static typename std::enable_if<
        std::is_same<T, std::vector<typename T::value_type>>::value ||
        std::is_same<T, std::deque<typename T::value_type>>::value,
        void
        >::type
        mergeBack(T& con, T& left, T& right);

        template<typename T>
        static typename std::enable_if<
        std::is_same<T, std::vector<typename T::value_type>>::value ||
        std::is_same<T, std::deque<typename T::value_type>>::value,
        void
        >::type
        binaryInsert(T& con, int num);

        static std::vector<size_t> generateJacobsthalOrder(size_t bSize);
};

/**
 * The difference bwtween Vector and deque:
 * vector excels at:
    Random access (i.e., arr[i])
    Push/insert at the end (amortized O(1))
    Cache locality (memory is continuous, so CPU cache works better)
 *

 🔹 deque excels at:
    Insertions at both ends (O(1))
    Less overhead when inserting at front or middle compared to vector
    Avoids full reallocations when growing (vector might need to copy all elements)
 *
 *
    ✅ vector is faster when:
        The input size is relatively small (cache locality wins)

        Insertions mostly happen at the end

        You do few insertions or insertions are in order (less shifting)

    ✅ deque is faster when:
        You insert a lot at the beginning or middle

        The array grows frequently and you want to avoid reallocation

        There’s less need for tight CPU-cache performance (e.g., large dataset
        where cache is already a bottleneck)
 */

