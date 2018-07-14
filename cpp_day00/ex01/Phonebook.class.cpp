// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Phonebook.class.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/02 10:16:33 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/02 10:16:34 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Phonebook.class.hpp"

Phonebook::Phonebook(void) {
	nb_contact = 0;
	return ;
}

Phonebook::~Phonebook(void) {
	return ;
}

bool	Phonebook::Full(void) {
	return (nb_contact >= 8 ? true : false);
}

void	Phonebook::AddContact(Contact *new_cont) {
	contacts[nb_contact] = *new_cont;
	nb_contact++;
}

void Phonebook::PrintLinesContacts(void) {
	for(int i = 0; i < nb_contact; i++)
		contacts[i].print_cont_info();
}

void	Phonebook::PrintOneContact(int index) {
	if (index > 0 && index < 9)
	{
		for (int i = 0; i < 8; i++)
			if (index == contacts[i].index)
				contacts[i].print_contact();
	}
}
