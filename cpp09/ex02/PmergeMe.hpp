/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:32:16 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/08 10:15:51 by jingwu           ###   ########.fr       */
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
};
