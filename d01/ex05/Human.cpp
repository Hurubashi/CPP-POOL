/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:43:47 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:43:57 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Human.hpp"

Human::Human() {
	std::cout << "New human was born."
			  << std::endl;
}

Human::~Human() {
	std::cout << "Your human are dead."
			  << std::endl;
}

std::string		Human::identify(){
	return this->brain.identify();
}

Brain			&Human::getBrain() {
	return (Brain &)(this->brain);
}
