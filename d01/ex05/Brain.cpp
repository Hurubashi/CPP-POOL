/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:42:21 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:42:24 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Congrats! You have a brain now."
			  << std::endl;
}

Brain::~Brain() {
	std::cout << "Disaster! Any brains left."
			  << std::endl;
}

std::string		Brain::identify() const {
	std::stringstream adr;
	adr << "0x" << std::hex << (unsigned long long)this;
	return (adr.str());
}
