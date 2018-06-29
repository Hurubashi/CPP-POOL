/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:16:06 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/14 18:16:08 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
	Zombie();
	~Zombie();
	void				announce();
	void				change_type(std::string *type);
	void				change_name(std::string *name);
	void				change_roar(std::string *roar);
private:
	std::string			_name;
	std::string			_type;
	std::string			_roar;
};

#endif
