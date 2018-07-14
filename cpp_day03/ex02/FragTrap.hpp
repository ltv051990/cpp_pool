// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/05 11:23:23 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/05 11:23:24 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class FragTrap: public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap ( std::string const & name );
		FragTrap (FragTrap const & src);
		~FragTrap( void );

		FragTrap & operator=(FragTrap const & dst);

		// void	rangedAttack( std::string const & target ) const;
		// void	meleeAttack( std::string const & target ) const;
		// void	takeDamage( unsigned int amount );
		// void	beRepaird( unsigned int amount );
		// void	energyRepaird( unsigned int amount );
		// void	takeEnergyDamage( unsigned int amount );

		///////////////////////////////////////////////////////////////
		///////////////////////    MY ATTACK      /////////////////////
		///////////////////////////////////////////////////////////////

		void	intimAttack( std::string const & target );
		void	fustAttack( std::string const & target );
		void	stupedAttack( std::string const & target );
		void	smartAttack( std::string const & target );
		void	hopStopAttack( std::string const & target );

		///////////////////////////////////////////////////////////////
		//////////////    Call random attack      /////////////////////
		///////////////////////////////////////////////////////////////

		void	vaulthunter_dot_exe( std::string const & target );
};

#endif
