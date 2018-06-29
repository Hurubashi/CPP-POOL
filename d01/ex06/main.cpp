/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:47:23 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:47:26 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

int		main()
{
	Weapon        club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

//	Weapon        club = Weapon("crude spiked club");
//	HumanB jim("Jim");
//	jim.setWeapon(club);
//	jim.attack();
//	club.setType("some other type of club");
//	jim.attack();
}

