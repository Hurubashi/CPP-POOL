/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:49:14 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:49:17 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void		if_done()
{
	std::cout << "\033[1;32mDone"
			  << std::endl
			  << "No need to thank me. Just gimme ur soul :)\033[0m"
			  << std::endl;
}

void		if_invalid()
{
	std::cout << "\033[1;31mGimme valid input"
			  << std::endl
			  << "Or I'll cut your hands off, brat!!!\033[0m"
			  << std::endl;
}

void		usage()
{
	std::cout << "\033[1;32mUsage : "
			  << "./replace 1.filename 2.word_to_replace 3.replacement_word\033[0m"
			  << std::endl;
}

