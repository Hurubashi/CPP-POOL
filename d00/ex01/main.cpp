/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:57:03 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/18 12:57:06 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

int main()
{
	std::string	buff;
	Contact	cont_arr[8];
	int		index = 0;
	int		i;

	while (1)
	{
		i = 0;
		std :: cout << "Enter command : " << std :: endl;
		std::getline(std::cin, buff);
		if (buff.compare("exit") == 0)
		{
			std :: cout << "Phone book self-destructed" << std :: endl;
			exit(0);
		}
		else if (buff.compare("add") == 0)
		{
			if (index == 9)
			{
				std :: cout << "Phone book is full" << std :: endl;
				continue;
			}
			cont_arr[index] = Contact();
			cont_arr[index].init_cont();
			index++;
		}
		else if (buff.compare("search") == 0)
		{
			cont_arr->search_header();
			while (i < index)
			{
				std::cout << std::setw (5) << i << " | ";
				cont_arr[i].short_info();
				i++;
			}
			std :: cout << "Select id:" << std :: endl;
			std::getline(std::cin, buff);
			i = buff[0] - '0';
			if (i >= 0 && i < index && buff.length() == 1)
				cont_arr[i].full_info();
			else
				std :: cout << "Wrong id" << std :: endl;
		}
		else
			std :: cout << "Only exit, add and search commands allowed" << std :: endl;
	}
}
