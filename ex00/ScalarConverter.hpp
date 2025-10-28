/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:18:28 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/28 16:36:45 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	
public:
	ScalarConverter& operator=(const ScalarConverter& copy);
	virtual ~ScalarConverter();
	static void	convert(const std::string& literal);
};

#endif