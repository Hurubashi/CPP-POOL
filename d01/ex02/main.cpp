/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:15:43 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/14 18:15:44 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main()
{
	ZombieEvent		*zm_Event = new ZombieEvent;
	int				i 		= 0;
	int				sq_size = 5;
	std::string zm_type 	= "Walker";

	zm_Event->setZombieType(&zm_type);
	while (i < sq_size)
	{
		zm_Event->randomChump(zm_Event, i);
		i++;
	}
	delete(zm_Event);
}