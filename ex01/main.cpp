/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:03:07 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/20 19:09:08 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *d = new Data;
	uintptr_t uint = 1;

	d->str = "blah";
	std::cout << "Data before: " << d << std::endl;
	std::cout << "Uint before: " << uint << std::endl;
	uint = Serializer::serialize(d);
	std::cout << "Uint after serializer: " << uint << std::endl;
	d = Serializer::deserialize(uint);
	std::cout << "Data after deserializer: " << d << std::endl;
	
	return (0);	
}