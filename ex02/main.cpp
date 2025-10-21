/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penpalac <penpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:19:46 by penpalac          #+#    #+#             */
/*   Updated: 2025/10/21 14:44:37 by penpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <fstream>
#include <exception>


Base *generate(void)
{
	int result = std::rand() % 3;
	if (result == 0)
		return (new A());
	else if (result == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Not a type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			return;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				return;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int main(void)
{
	std::srand(std::time(0));

	Base *b = generate();
	identify(b); 
	identify(*b);
	return(0);
}