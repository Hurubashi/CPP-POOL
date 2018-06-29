/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 08:50:31 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/20 08:50:34 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(char const *name): name(name) {
	std::cout << "Явилось на свет Божий дитя " << this->name << std::endl;
}

Human::~Human(void) {
	std::cout << this->name << " помер от курения, курить плохо."
			" Принимайте тежелые наркотики. Информация прописалась на правах рекламы." << std::endl;
}

void	Human::meleeAttack(std::string const &target) {
	std::cout << this->name
			  << " Как втащил прям в табло "
			  << target
			  << std::endl;
}

void	Human::rangedAttack(std::string const &target) {
	std::cout << this->name
			  << " Кинул какаху прям на белую рубаху "
			  << target
			  << std::endl;
}

void	Human::intimidatingShout(std::string const &target) {
	std::cout << this->name
			  << " Ушты - пуртушты "
			  << target
			  << std::endl;
}

struct t_attack
{
	std::string		name;
	void			(Human::*func)(std::string const &);
};

t_attack		Human::_attacks[] = {
		{"meleeAttack", &Human::meleeAttack},
		{"rangedAttack", &Human::rangedAttack},
		{"intimidatingShout", &Human::intimidatingShout}
};

void			Human::action(std::string const &action_name, std::string const &target)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		if (action_name == _attacks[i].name)
		{
			(this->*_attacks[i].func)(target);
			break;
		}
		i++;
	}
}


