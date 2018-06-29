/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:12:34 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 16:12:36 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>
#include <string>

class Pony {

public:
	Pony		(int power, std::string color, int speed);
	~Pony		();
	void		prove_ponyness();
	void		describe_pony();

private:
	int			_pony_power;
	std::string	_pony_color;
	int			_pony_speed;
};


#endif
