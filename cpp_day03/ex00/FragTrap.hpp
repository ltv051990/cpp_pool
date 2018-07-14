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
#include <string>

class FragTrap
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
		FragTrap( void );
		FragTrap ( std::string const & name );
		FragTrap (FragTrap const & src);
		~FragTrap( void );

		FragTrap & operator=(FragTrap const & dst);

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

		// void FragTrap::setHitPoints( unsigned int name );
		// void FragTrap::setMaxHitPoints( unsigned int maxHitPoints );
		// void FragTrap::setEnergyPoints( unsigned int energyPoints );
		// void FragTrap::setMaxEnergyPoints( unsigned int maxEnergyPoints );
		// void FragTrap::setLevel( unsigned int level );
		// void FragTrap::setmeleeAttackDamage( unsigned int meleeAttackDamage );
		// void FragTrap::setRangedAttackDamage( unsigned int rangedAttackDamage );
		// void FragTrap::setEnergyAttackDamage( unsigned int energyAttackDamage );
		// void FragTrap::setArmorDamageReduction( unsigned int armorDamageReduction );

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
