/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:38:51 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:38:54 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(int power, std::string color, int speed) {
	this->_pony_power = power;
	this->_pony_color = color;
	this->_pony_speed = speed;
	std :: cout << "Zaz love me, cose i'm pony! ";
}

Pony::~Pony() {
	std :: cout << this->_pony_color
				<< " Pony dead" << std::endl;
}

void	Pony::prove_ponyness()
{
	std :: cout << "Ya ponya, vai syshai mamoi klyanus! A ona u menya pony!" << std :: endl;
};

void	Pony::describe_pony()
{
	std :: cout << "I'm "
				<< this->_pony_color
				<< " with a power over "
				<< this->_pony_power
				<< " and speed of "
				<< this->_pony_speed
				<< std::endl;
}
