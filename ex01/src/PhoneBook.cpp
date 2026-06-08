/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:30:53 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/08 15:07:31 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	current_nb = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
}

/*
	Adds the new contact at the correct index
	If the 8 slots are already filled, the oldest one is replaced by the new one
*/
void	PhoneBook::addContact(Contact const &newContact) {
	int	place = current_nb % 8;
	
	this->list[place] = newContact;
	this->current_nb++;
}

/* Displays all contacts in a specific format */
void	PhoneBook::displayAll() {
	for (int i = 0; i < current_nb; ++i) {
		std::string	first_name = list[i].getFirstname();
		std::string	last_name = list[i].getLastname();
		std::string	nickname = list[i].getNickname();

		std::cout << std::right << std::setw(10) << i;
		std::cout << '|';
		if (first_name.size() > 10) {
			std::string	sub_first = first_name.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << sub_first;
			std::cout << '|';
		}
		else {
			std::cout << std::right << std::setw(10) << first_name;
			std::cout << '|';
		}
		if (last_name.size() > 10) {
			std::string	sub_last = last_name.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << sub_last;
			std::cout << '|';
		}
		else {
			std::cout << std::right << std::setw(10) << last_name;
			std::cout << '|';
		}
		if (nickname.size() > 10) {
			std::string	sub_nick = nickname.substr(0, 9) + ".";
			std::cout << std::right << std::setw(10) << sub_nick << '.' << std::endl;
		}
		else
			std::cout << std::right << std::setw(10) << nickname << std::endl;
	}
	return ;
}