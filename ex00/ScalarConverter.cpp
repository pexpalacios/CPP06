/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:21:30 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/27 15:18:15 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

/////

bool is_psuedo_literal(const std::string &literal)
{
	return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
			literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool is_char(const std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool is_int(const std::string &literal)
{
	size_t i = 0;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

bool is_float(const std::string &literal)
{
	size_t i = 0;
	bool dot_found = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (dot_found == true)
				return (false);
			dot_found = true;
		}
		else if (literal[i] == 'f' && i == literal.length() - 1)
			return (dot_found);
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	return (false);
}

bool is_double(const std::string &literal)
{
	size_t i = 0;
	bool dot_found = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (dot_found == true)
				return (false);
			dot_found = true;
		}
		else if (!std::isdigit(literal[i]))
			return (false);
	}
	return (dot_found);
}

///

void convert_from_char(const std::string &literal)
{
	char c = literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convert_from_int(const std::string &literal)
{
	long long ll = std::stoll(literal);
	if (ll > INT_MAX || ll < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(ll) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(ll) << ".0" << std::endl;
		return;
	}

	int i = std::stoi(literal);

	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convert_from_float(const std::string &literal)
{
	try
	{
		float f = std::stof(literal);

		if (f < 0 || f > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<int>(f)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void convert_from_double(const std::string &literal)
{
	try
	{
		double d = std::stod(literal);

		if (d < 0 || d > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<int>(d)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void convert_from_psuedo_literal(const std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

///////

void ScalarConverter::convert(const std::string &literal)
{
	if (!is_psuedo_literal(literal))
	{
		if (is_char(literal))
			convert_from_char(literal);
		else if (is_int(literal))
			convert_from_int(literal);
		else if (is_float(literal))
			convert_from_float(literal);
		else if (is_double(literal))
			convert_from_double(literal);
		else
			std::cout << "Error: Invalid literal" << std::endl;
	}
	else
		convert_from_psuedo_literal(literal);
}