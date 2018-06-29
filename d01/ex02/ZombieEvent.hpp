/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:40:55 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:40:59 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent {

public:
	void			setZombieType(std::string *type);
	Zombie			*newZombie(std::string name);
	void			randomChump(ZombieEvent *zm_event, int i);

private:
	std::string		_saved_type;
};

#endif
