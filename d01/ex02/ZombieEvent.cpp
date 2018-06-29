/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:40:37 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:40:40 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void			ZombieEvent::setZombieType(std::string *type)
{
	this->_saved_type = *type;
}

Zombie			*ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(&name, &this->_saved_type);
	return (zombie);
}

std::string		choose_name(int nb)
{
	std::string names[10];

	names[0] = "Jack in black";
	names[1] = "Vladimir Lenin";
	names[2] = "John Doe";
	names[3] = "Isaac Newton";
	names[4] = "Albert Einstein";
	names[5] = "Milla Jovovich";
	names[6] = "Jesus Christ";
	names[7] = "Morrigan";
	names[8] = "Zeus";
	names[9] = "Herald of Rivia, yeah i'm zombie now too";
	return (names[nb]);
}

void			ZombieEvent::randomChump(ZombieEvent *zm_event, int i)
{
	srand(time(0));
	std::string name = choose_name((rand() + i) % 10);
	Zombie *some_zombie = zm_event->newZombie(name);
	some_zombie->announce();
	delete(some_zombie);
}
