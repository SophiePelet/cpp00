/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:51:47 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/08 12:30:33 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void	Contact::setFields(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string	Contact::getFirstname() const {
	return (first_name);
}

std::string	Contact::getLastname() const {
	return (last_name);
}

std::string	Contact::getNickname() const {
	return (nickname);
}