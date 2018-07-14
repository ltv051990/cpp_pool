// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/02 10:19:16 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/02 10:32:56 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include <iostream>

class Contact {

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string login;
		std::string postal_address;
		std::string email_address;
		std::string phone_number;
		std::string birthday_date;
		std::string favorite_meal;
		std::string underwear_color;
		std::string darkest_secret;

	public:
		int index;

		Contact(void);
		~Contact(void);

		void print_part(std::string s);
		void print_cont_info(void);
		void print_contact(void);

		void setFirstName(std::string a);
		void setLastName(std::string a);
		void setNickname(std::string a);
		void setLogin(std::string a);
		void setPostalAddress(std::string a);
		void setEmailAddress(std::string a);
		void setPhoneNumber(std::string a);
		void setBirthdayDate(std::string a);
		void setFavoriteMeal(std::string a);
		void setUnderwearColor(std::string a);
		void setDarkestSecret(std::string a);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getLogin(void);
};

#endif
