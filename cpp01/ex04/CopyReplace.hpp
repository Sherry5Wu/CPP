/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CopyReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:18:47 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:18:47 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPYREPLACE_HPP
# define COPYREPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class CopyReplace{
	public:
		CopyReplace(const std::string fileName, const std::string s1,
			const std::string s2);
		~CopyReplace();
		bool	process();

	private:
		const std::string	fileName_;
		const std::string	s1_;
		const std::string	s2_;
		std::string			content_;

		bool	readFile();
		bool	replaceAndWriteFile();
};

#endif // COPYREPLACE_HPP
