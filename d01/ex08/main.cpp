/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:50:57 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:51:00 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int		main()
{
	Human *human = new Human("Jojo");
	human->action("meleeAttack", "Petrosyan");
	human->action("rangedAttack", "Petrosyan");
	human->action("intimidatingShout", "Petrosyan");
	delete(human);
}
