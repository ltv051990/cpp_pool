// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/06 15:19:33 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/06 15:19:35 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "SravTrap.hpp"

class NinjaTrap: public ClapTrap
{
	public:
		NinjaTrap(void);
		NinjaTrap(std::string const & name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap(void);

		NinjaTrap		& operator=(NinjaTrap const &rhs);

		void	ninjaShoebox(NinjaTrap const &target) const;
		void	ninjaShoebox(ClapTrap const &target) const;
		void	ninjaShoebox(FragTrap const &target) const;
		void	ninjaShoebox(SravTrap const &target) const;	
};

#endif
