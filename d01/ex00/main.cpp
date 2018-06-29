/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:38:19 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:38:27 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void		ponyOnTheHeap(int power, std::string color, int speed)
{
	Pony *heapPony = new Pony(power, color, speed);
	std :: cout << "I'm living on heap!" << std::endl;
	heapPony->prove_ponyness();
	heapPony->describe_pony();
	delete(heapPony);
}

void		ponyOnTheStack(int power, std::string color, int speed)
{
	Pony stackPony(power, color, speed);
	std :: cout << "I'm living on stack!" << std::endl;
	stackPony.prove_ponyness();
	stackPony.describe_pony();
}

int		main()
{
	ponyOnTheHeap(10, "Black", 155);
	ponyOnTheStack(9000, "Pink", 160);
}
