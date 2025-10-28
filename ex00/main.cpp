/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:18:06 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/28 17:03:24 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	std::string input;

	if (ac == 2)
	{
		input = av[1];
		ScalarConverter::convert(input);
	}
	return (0);
}