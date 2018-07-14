// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/05 11:23:16 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/05 11:23:17 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include <iostream>
#include <ctime>
std::string const FragTrap::type = "FragTrap FR4G-TP";
int FragTrap::random = 0;

FragTrap::FragTrap(void) {
	std::cout << "My comrads!!! Default model of " << this->type << " was created ans ready to fight with enemy!" <<std::endl;
	this->name = "IVASYK";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->energyAttackDamage = 25;
}

FragTrap::~FragTrap(void) {
	std::cout << "Fuck!!! Destructor called!!! So it is pizdez to " << this->type << std::endl;
}

FragTrap::FragTrap ( std::string const & name ) {
	std::cout << "My comrads!!! " << this->type << " was created with name " << name << " and ready to fight with enemy!" <<std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 100;
	this->maxEnergyPoints = 100;
	this->level = 1;
	this->meleeAttackDamage = 30;
	this->rangedAttackDamage = 20;
	this->armorDamageReduction = 5;
	this->energyAttackDamage = 25;
}

FragTrap & FragTrap::operator=( FragTrap const &src ) {
	this->name = src.getName();
	this->hitPoints = src.getHitPoints();
	this->maxHitPoints = src.getMaxHitPoints();
	this->energyPoints = src.getEnergyPoints();
	this->maxEnergyPoints = src.getMaxEnergyPoints();
	this->level = src.getLevel();
	this->meleeAttackDamage = src.getmeleeAttackDamage();
	this->rangedAttackDamage = src.getRangedAttackDamage();
	this->armorDamageReduction = src.getArmorDamageReduction();
	this->energyAttackDamage = src.getEnergyAttackDamage();
//	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

FragTrap::FragTrap( FragTrap const & src ) {
	std::cout << "My comrads!!! Copy of " << this->type << " was created with name and ready to fight with enemy!" <<std::endl;
	*this = src;
}

unsigned int FragTrap::getHitPoints( void ) const {
	return this->hitPoints;
}

unsigned int FragTrap::getMaxHitPoints( void ) const {
		return this->maxHitPoints;
}

unsigned int FragTrap::getEnergyPoints( void ) const {
	return this->energyPoints;
}

unsigned int FragTrap::getMaxEnergyPoints( void ) const {
	return this->maxEnergyPoints;
}

unsigned int FragTrap::getLevel( void ) const {
	return this->level;
}

unsigned int FragTrap::getmeleeAttackDamage( void ) const {
	return this->meleeAttackDamage;
}

unsigned int FragTrap::getRangedAttackDamage( void ) const {
	return this->rangedAttackDamage;
}

unsigned int FragTrap::getEnergyAttackDamage( void ) const {
	return this->energyAttackDamage;
}

unsigned int FragTrap::getArmorDamageReduction( void ) const {
	return this->armorDamageReduction;
}

std::string FragTrap::getName( void ) const {
	return this->name;
}

// void FragTrap::setHitPoints( unsigned int name ) {
// 	this->name = name;
// }

// void FragTrap::setMaxHitPoints( unsigned int maxHitPoints ) {
// 	this->maxHitPoints;
// }

// void FragTrap::setEnergyPoints( unsigned int energyPoints ) {
// 	this->energyPoints;
// }

// void FragTrap::setMaxEnergyPoints( unsigned int maxEnergyPoints ) {
// 	this->maxEnergyPoints = maxEnergyPoints;
// }

// void FragTrap::setLevel( unsigned int level ) {
// 	this->level = level;
// }

// void FragTrap::setmeleeAttackDamage( unsigned int meleeAttackDamage ) {
// 	this->meleeAttackDamage = meleeAttackDamage;
// }

// void FragTrap::setRangedAttackDamage( unsigned int rangedAttackDamage ) {
// 	this->rangedAttackDamage = rangedAttackDamage;
// }

// void FragTrap::setEnergyAttackDamage( unsigned int energyAttackDamage ) {
// 	this->energyAttackDamage = energyAttackDamage;
// }

// void FragTrap::setArmorDamageReduction( unsigned int armorDamageReduction ) {
// 	this->armorDamageReduction = armorDamageReduction;
// }

void FragTrap::setName( std::string name) {
	this->name = name;
}

void	FragTrap::takeDamage( unsigned int amount ) {
	if (this->hitPoints < amount - this->armorDamageReduction) {
		std::cout << "HUSTON!!! HUSTON!!! " << this->type << " " << this->name << " takeDamage and my hitPoints = 0" << std::endl;
		this->hitPoints = 0;
	}
	else
	{
		this->hitPoints -= amount - this->armorDamageReduction;
		std::cout << "HUSTON!!! HUSTON!!! " << this->type << " " << name << " takeDamage and my hitPoints = " << this->hitPoints << std::endl;
	}
}

void	FragTrap::takeEnergyDamage( unsigned int amount ) {
	if (this->energyPoints < amount - this->energyAttackDamage) {
		std::cout << "HUSTON!!! HUSTON!!! " << this->type << " " << this->name << " takeDamage and my energyPoints = 0" << std::endl;
		this->energyPoints = 0;
	}
	else
	{
		this->energyPoints -= amount - this->armorDamageReduction;
		std::cout << "HUSTON!!! HUSTON!!! " << this->type << " " << name << " takeDamage and my hitPoints = " << this->energyPoints << std::endl;
	}
}


void FragTrap::beRepaird( unsigned int amount ) {
	if (this->hitPoints + amount > this->maxHitPoints) {
		std::cout << " THX bro!!! I feel better! My health now is 100HP" << std::endl;
		this->hitPoints = 100;
	}
	else{ 
		std::cout << " THX bro!!! I feel better! My health now is ";
		this->hitPoints += amount;
		std::cout << this->hitPoints << std::endl;
	}
}

void FragTrap::energyRepaird( unsigned int amount ) {
	if (this->energyPoints + amount > this->maxEnergyPoints) {
		std::cout << " THX bro!!! I feel better! My energy now is 100EP" << std::endl;
		this->energyPoints = 100;
	}
	else{ 
		std::cout << " THX bro!!! I feel better! My health now is ";
		this->energyPoints += amount;
		std::cout << this->energyPoints << std::endl;
	}
}


void FragTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->type << this->name << " attacks " << target << " at range, causing "
	<< this->meleeAttackDamage << " points of damage!!!" << std::endl;
}

void FragTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->type << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage << " points of damage!!!" << std::endl;
}

		///////////////////////////////////////////////////////////////
		///////////////////////    MY ATTACK      /////////////////////
		///////////////////////////////////////////////////////////////

void FragTrap::intimAttack( std::string const & target ) {
	std::cout << "" << this->type << " use intimAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 5<< " points of damage!!!" << std::endl;
}

void FragTrap::fustAttack( std::string const & target ) {
	std::cout << "" << this->type << " use fustAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage - 10 << " points of damage!!!" << std::endl;
}

void FragTrap::stupedAttack( std::string const & target ) {
	std::cout << "" << this->type << " use stupedAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage - 15 << " points of damage!!!" << std::endl;
}

void FragTrap::smartAttack( std::string const & target ) {
	std::cout << "" << this->type << " use smartAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 30 << " points of damage!!!" << std::endl;
}

void FragTrap::hopStopAttack( std::string const & target ) {
	std::cout << "" << this->type << " use hopStopAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage * 2 << " points of damage!!!" << std::endl;
}

		///////////////////////////////////////////////////////////////
		//////////////    Call random attack      /////////////////////
		///////////////////////////////////////////////////////////////

void FragTrap::vaulthunter_dot_exe( std::string const & target ) {
	this->random++;
	void (FragTrap::*ukaz[5])( std::string const & target ) = { &FragTrap::hopStopAttack, &FragTrap::smartAttack,
		&FragTrap::stupedAttack, &FragTrap::fustAttack, &FragTrap::intimAttack };
	int random = (std::time(nullptr) + random) % 5;
	if (this->energyPoints >= 25) {
		(this->*ukaz[random])(target);
		energyPoints -= 25;
	}
	else {
		std::cout << "YOU DON'T HAVE ENOUGTH ENERGY!!!" << std::endl;
	}
//	std::cout << "energyPoints " << energyPoints << std::endl;
}
