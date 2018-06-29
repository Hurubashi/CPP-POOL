/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 12:56:40 by mrybak            #+#    #+#             */
/*   Updated: 2018/06/18 12:56:44 by mrybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassContact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void		Contact::init_cont() {
	std :: cout << "Your first name? : " << std :: endl;
	std::getline(std::cin, this->first_name);
	std :: cout << "Your last name? : " << std :: endl;
	std::getline(std::cin, this->last_name);
	std :: cout << "Your nickname? : " << std :: endl;
	std::getline(std::cin, this->nickname);
	std :: cout << "Your login? : " << std :: endl;
	std::getline(std::cin, this->login);
	std :: cout << "Your postal address? : " << std :: endl;
	std::getline(std::cin, this->postal_address);
	std :: cout << "Your email address? : " << std :: endl;
	std::getline(std::cin, this->email_address);
	std :: cout << "Your phone number? : " << std :: endl;
	std::getline(std::cin, this->phone_number);
	std :: cout << "Your birthday? : " << std :: endl;
	std::getline(std::cin, this->birthday_date);
	std :: cout << "Your favorite meal? : " << std :: endl;
	std::getline(std::cin, this->favorite_meal);
	std :: cout << "Your underwear color? : " << std :: endl;
	std::getline(std::cin, this->underwear_color);
	std :: cout << "Your darkest secret? : " << std :: endl;
	std::getline(std::cin, this->darkest_secret);
}

void		Contact::search_header(){
	std::cout << std::setw (5) << "index" << " | ";
	std::cout << std::setw (10) << "first name" << " | ";
	std::cout << std::setw (10) << "last name" << " | ";
	std::cout << std::setw (10) << "nickname" << " | ";
	std :: cout << std :: endl;
}

void		Contact::short_info()
{
	if (this->first_name.length() > 10)
		std::cout << std::setw (10) << this->first_name.substr(0,9) << ".| ";
	else
		std::cout << std::setw (10) << this->first_name.substr(0,10) << " | ";
	if (this->last_name.length() > 10)
		std::cout << std::setw (10) << this->last_name.substr(0,9) << ".| ";
	else
		std::cout << std::setw (10) << this->last_name.substr(0,10) << " | ";
	if (this->nickname.length() > 10)
		std::cout << std::setw (10) << this->nickname.substr(0,9) << ".| ";
	else
		std::cout << std::setw (10) << this->nickname.substr(0,10) << " | ";
	std :: cout << std :: endl;
}

void		Contact::full_info(){
	std::cout << std::setw (17) << "first_name: ";
	std::cout << this->first_name << std :: endl;
	std::cout << std::setw (17) << "last_name: ";
	std::cout << this->last_name << std :: endl;
	std::cout << std::setw (17) << "nickname: ";
	std::cout << this->nickname << std :: endl;
	std::cout << std::setw (17) << "login: ";
	std::cout << this->login << std :: endl;
	std::cout << std::setw (17) << "postal_address: ";
	std::cout << this->postal_address << std :: endl;
	std::cout << std::setw (17) << "email_address: ";
	std::cout << this->email_address << std :: endl;
	std::cout << std::setw (17) << "phone_number: ";
	std::cout << this->phone_number << std :: endl;
	std::cout << std::setw (17) << "birthday_date: ";
	std::cout << this->birthday_date << std :: endl;
	std::cout << std::setw (17) << "favorite_meal: ";
	std::cout << this->favorite_meal << std :: endl;
	std::cout << std::setw (17) << "underwear_color: ";
	std::cout << this->underwear_color << std :: endl;
	std::cout << std::setw (17) << "darkest_secret: ";
	std::cout << this->darkest_secret << std :: endl;
	std :: cout << std :: endl;
}
