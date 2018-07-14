// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SravTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/05 23:40:07 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/05 23:40:08 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SRAVTRAP_HPP
#define SRAVTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class SravTrap: public ClapTrap
{
	public:
		SravTrap( void );
		SravTrap( std::string const & name );
		SravTrap(SravTrap const & src);
		~SravTrap( void );

		SravTrap & operator=(SravTrap const & dst);

		///////////////////////////////////////////////////////////////
		///////////////////////    MY ATTACK      /////////////////////
		///////////////////////////////////////////////////////////////

		void	funnyAttack( std::string const & target );
		void	bustyAttack( std::string const & target );
		void	fuckingAttack( std::string const & target );
		void	spekingAttack( std::string const & target );
		void	spaceAttack( std::string const & target );

		///////////////////////////////////////////////////////////////
		//////////////    Call random attack      /////////////////////
		///////////////////////////////////////////////////////////////

		void	challengeNewcomer( std::string const & target );
};

#endif
