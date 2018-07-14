// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Phonebook.class.hpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/02 10:16:42 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/02 10:16:44 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Phonebook.class.hpp"
#include "Contact.class.hpp"
# include <iostream>

class Phonebook {
	private:
		Contact contacts[8];
		int nb_contact;
	public:
		Phonebook(void);
		~Phonebook(void);

		void AddContact(Contact *new_cont);
		void PrintOneContact(int index);
		bool Full(void);
		void PrintLinesContacts(void);
};

#endif