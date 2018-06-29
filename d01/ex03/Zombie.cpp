/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:15:59 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/14 18:16:01 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string		get_rand_name(int nb)
{
	std::string names[10];

	names[0] = "Alexander Pushkin";
	names[1] = "Vladimir Lenin";
	names[2] = "John Doe";
	names[3] = "Isaac Newton";
	names[4] = "Albert Einstein";
	names[5] = "Milla Jovovich";
	names[6] = "Jesus Christ";
	names[7] = "Morrigan";
	names[8] = "Zeus";
	names[9] = "Herald of Rivia";
	return (names[nb]);
}

std::string		get_rand_type(int nb)
{
	std::string type[5];

	type[0] = "Walker";
	type[1] = "Runner";
	type[2] = "Ghoul";
	type[3] = "Crawler";
	type[4] = "The Screamer";
	return (type[nb]);
}

std::string		get_rand_roar(int nb)
{
	std::string roar[5];

	roar[0] = "Braiiiiiiinnnssss...";
	roar[1] = "More Braiiiiinnss...";
	roar[2] = "I need Morrree....";
	roar[3] = "Cherry cake pls!";
	roar[4] = "Gimme your Braaiinnsss...";
	return (roar[nb]);
}

Zombie::Zombie()
{
	this->_name = get_rand_name((rand() + time(0)) % 10);
	this->_type = get_rand_type((rand() + time(0)) % 5);
	this->_roar = get_rand_roar((rand() + time(0)) % 5);
}

Zombie::~Zombie()
{
	std::cout << "Oh my god they killed "
			  << this->_name
			  << ", you bastards!"
			  << std::endl;
}

void		Zombie::change_type(std::string *type)
{
	this->_type = *type;
}

void		Zombie::change_name(std::string *name)
{
	this->_type = *name;
}

void		Zombie::change_roar(std::string *roar)
{
	this->_roar = *roar;
}

void	Zombie::announce()
{
	std::cout << "<"
			  << this->_name
			  << " ("
			  << this->_type
			  << ")"
			  << this->_roar
			  << std::endl;
}