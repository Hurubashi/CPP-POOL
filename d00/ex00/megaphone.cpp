/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 10:06:14 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/18 10:06:22 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {

	int i = 1;
	int j;

	if (ac == 1)
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else if (ac > 1)
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				av[i][j] = (char)std :: toupper(av[i][j]);
				j++;
			}
			std :: cout << av[i];
			i++;
		}
		std :: cout << std::endl;
	}
	return 0;
}
