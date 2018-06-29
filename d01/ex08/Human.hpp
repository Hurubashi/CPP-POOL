/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:50:45 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:50:48 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>

struct t_attack;

class Human
{

public:
	Human(char const *name);
	~Human(void);
	void		action(std::string const &action_name, std::string const &target);

private:
	static t_attack		_attacks[];
	std::string			name;
	void				meleeAttack(std::string const &target);
	void				rangedAttack(std::string const &target);
	void				intimidatingShout(std::string const &target);

};

#endif
