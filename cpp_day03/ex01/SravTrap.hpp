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
#include <iostream>

class SravTrap
{
	private:
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
		static std::string const type;
		static int random;
	public:
		SravTrap( void );
		SravTrap( std::string const & name );
		SravTrap(SravTrap const & src);
		~SravTrap( void );

		SravTrap & operator=(SravTrap const & dst);

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

		// void SravTrap::setHitPoints( unsigned int name );
		// void SravTrap::setMaxHitPoints( unsigned int maxHitPoints );
		// void SravTrap::setEnergyPoints( unsigned int energyPoints );
		// void SravTrap::setMaxEnergyPoints( unsigned int maxEnergyPoints );
		// void SravTrap::setLevel( unsigned int level );
		// void SravTrap::setmeleeAttackDamage( unsigned int meleeAttackDamage );
		// void SravTrap::setRangedAttackDamage( unsigned int rangedAttackDamage );
		// void SravTrap::setEnergyAttackDamage( unsigned int energyAttackDamage );
		// void SravTrap::setArmorDamageReduction( unsigned int armorDamageReduction );
		void setName( std::string name);

		void	rangedAttack( std::string const & target ) const;
		void	meleeAttack( std::string const & target ) const;
		void	takeDamage( unsigned int amount );
		void	beRepaird( unsigned int amount );
		void	energyRepaird( unsigned int amount );
		void	takeEnergyDamage( unsigned int amount );

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
