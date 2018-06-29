/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:39:48 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:39:54 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string *name, std::string *type)
{
	this->_name = *name;
	this->_type = *type;
}

Zombie::~Zombie() {
	std::cout << this->_name
			  << " is dead"
			  << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<"
			  << this->_name
			  << " ("
			  << this->_type
			  << ")"
			  << "> Braiiiiiiinnnssss..."
			  << std::endl;
}
