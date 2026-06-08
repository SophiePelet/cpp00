/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:31:41 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/08 16:57:59 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

class Contact {
public:
	Contact(void);
	~Contact(void);
	void	setFields(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number, std::string darkest_secret);
	std::string	getFirstname() const;
	std::string	getLastname() const;
	std::string	getNickname() const;
	std::string	getSecret() const;
	std::string	getPhone() const;
	
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif