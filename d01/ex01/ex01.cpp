/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:39:19 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:39:22 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak(void) {
	std::string *panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete(panthere);
}

int		main(void)
{
	memoryLeak();
	system("leaks a.out");
}
