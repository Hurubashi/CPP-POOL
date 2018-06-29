/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:50:00 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:50:05 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int		main(int ac, char **av)
{
	std::string		buff;
	std::ifstream	in;
	std::ofstream	out;
	std::string		filename;
	std::string		s1;
	std::string		s2;
	size_t		word_from_start;
	size_t		s1_len;

	if (ac == 4)
	{
		filename = av[1];
		in.open(filename, std::ios::in);
		if (in.is_open())
			out.open(filename + ".new", std::ios::out);
		if (in.is_open() && out.is_open())
		{
			s1 = av[2];
			s2 = av[3];
			s1_len = s1.size();
			while (std::getline(in, buff))
			{
				word_from_start = 0;
				while ((word_from_start = buff.find(s1, word_from_start)) != std::string::npos)
					buff.replace(word_from_start, s1_len, s2);
				out << buff << std::endl;
			}
			in.close();
			out.close();
			if_done();
			return (0);
		}
		else
			if_invalid();
	}
	usage();
}
