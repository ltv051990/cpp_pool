// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/06 10:49:06 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/06 10:49:07 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int maxHitPoints;
		unsigned int energyPoints;
		unsigned int maxEnergyPoints;
		unsigned int level;
		unsigned int meleeAttackDamage;
		unsigned int rangedAttackDamage;
		unsigned int energyAttackDamage;
		unsigned int armorDamageReduction;
		std::string type;
		int random;

	public:
		ClapTrap( void );
		ClapTrap ( std::string const & name );
		ClapTrap (ClapTrap const & src);
		~ClapTrap( void );

		ClapTrap & operator=(ClapTrap const & dst);

		unsigned int getHitPoints( void ) const;
		unsigned int getMaxHitPoints( void ) const;
		unsigned int getEnergyPoints( void ) const;
		unsigned int getMaxEnergyPoints( void ) const;
		unsigned int getLevel( void ) const;
		unsigned int getmeleeAttackDamage( void ) const;
		unsigned int getRangedAttackDamage( void ) const;
		unsigned int getEnergyAttackDamage( void ) const;
		unsigned int getArmorDamageReduction( void ) const;
		std::string getName( void ) const;

		void setHitPoints( unsigned int name );
		void setMaxHitPoints( unsigned int maxHitPoints );
		void setEnergyPoints( unsigned int energyPoints );
		void setMaxEnergyPoints( unsigned int maxEnergyPoints );
		void setLevel( unsigned int level );
		void setmeleeAttackDamage( unsigned int meleeAttackDamage );
		void setRangedAttackDamage( unsigned int rangedAttackDamage );
		void setEnergyAttackDamage( unsigned int energyAttackDamage );
		void setArmorDamageReduction( unsigned int armorDamageReduction );
		void setName( std::string name);

		void	rangedAttack( std::string const & target ) const;
		void	meleeAttack( std::string const & target ) const;
		void	takeDamage( unsigned int amount );
		void	beRepaird( unsigned int amount );
		void	energyRepaird( unsigned int amount );
		void	takeEnergyDamage( unsigned int amount );

};

#endif
