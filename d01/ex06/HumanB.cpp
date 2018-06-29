/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:46:04 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:46:10 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB(){
	return;
}

void		HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void		HumanB::attack() {
	std::cout << this->name
			  << " attacks with his "
			  << this->weapon->getType()
			  << std::endl;
}
