/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:46:17 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:46:24 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string name);
	~HumanB();

	void			setWeapon(Weapon &weapon);
	void			attack();

private:
	std::string		name;
	Weapon			*weapon;
};

#endif
