/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:46:36 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:46:41 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	setType(type);
}

Weapon::~Weapon() {
}

void				Weapon::setType(std::string type){
	this->type = type;
}

const std::string	&Weapon::getType(){
	return this->type;
}
