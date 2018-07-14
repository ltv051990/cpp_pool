// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/04 13:22:00 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/04 13:22:02 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human(void) {}

Human::~Human(void) {}

void	Human::meleeAttack(std::string const & target) {
	std::cout << "REALLY??? YOU CALL meleeAttack, SO READ : " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target) {
	std::cout << "REALLY??? YOU CALL rangedAttack, SO READ : " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target) {
	std::cout << "REALLY??? YOU CALL intimidatingShout, SO READ : " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target) {
	void (Human::*sraka[3])(std::string const & t) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string names[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	for(int i = 0; i < 3; i++)
		if (names[i] == action_name)
			(this->*sraka[i])(target);
}
