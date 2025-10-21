/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:33:33 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/20 19:03:00 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){};

Serializer::Serializer(Serializer const &copy){
	*this = copy;
}

Serializer &Serializer::operator=(Serializer const &copy){
	if (this != &copy)
		*this = copy;
	return (*this);
}

Serializer::~Serializer(){}

/////

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}