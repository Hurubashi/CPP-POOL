/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:41:55 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:41:58 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *pointer_to_brain = &brain;
	std::string &ref_to_brain = brain;
	std::cout << *pointer_to_brain
			  << std::endl
			  << ref_to_brain
			  << std::endl;
}
