/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:12:54 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/15 12:12:55 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) {

	std::cout << std::endl
			  << "Oh my goodness! It's Zombie Horde!"
			  << std::endl;
	int i = 0;
	this->_zmHorde = new Zombie[N];
	this->_nZobies = N;
	while (i < N)
	{
		this->_zmHorde[i].announce();
		i++;
	}
}

ZombieHorde::~ZombieHorde() {
	std::cout << std::endl
			  << "We gonna die :( "
			  << std::endl;
	delete [] (this->_zmHorde);
}