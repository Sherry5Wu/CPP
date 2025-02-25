/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:31:22 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 13:29:50 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

/**
 * The difference between "class ICharacter;" and "#include "ICharacter.hpp"?
 *  "class ICharacter;" is called forward declaration, meaning it tells the
 *  compiler that ICharacter is a class, but it doesn't include its full
 *  definition. It's usefull when you only need a pointer or reference to
 *  ICharacter.
 *
 *  "#include "ICharacter.hpp" , if your .hpp file needs to know the full
 *  defination of IChararcter, then you must include the header filer.
 *  For example:
 * 		* You use ICharacter as a member variable inside AMateria.
 *      * You call ICharacter's methods inside the header file.
 */
// class ICharacter;
#include "ICharacter.hpp"

class AMateria{
	protected:
		std::string	type_;

	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		virtual ~AMateria();

		AMateria&	operator=(const AMateria& other);
		const std::string&	getType() const;
		virtual AMateria*	clone() const = 0; // pure virtual function
		virtual void	use(ICharacter& target);
};
