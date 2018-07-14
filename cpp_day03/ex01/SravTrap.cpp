// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SravTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/05 23:39:59 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/05 23:40:01 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SravTrap.hpp"
#include <ctime>

std::string const SravTrap::type = "CLAPTRAPS FR4G-TP";
int SravTrap::random = 0;

SravTrap::SravTrap(void) {
	std::cout << "My comrads!!! Default model of " << this->type << " was created ans ready to fight with enemy!" <<std::endl;
	this->name = "TELESYK";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	this->energyAttackDamage = 25;
}

SravTrap::~SravTrap(void) {
	std::cout << "Fuck!!! Destructor called!!! So it is pizdez to " << this->type << std::endl;
}

SravTrap::SravTrap ( std::string const & name ) {
	std::cout << "My comrads!!! " << this->type << " was created with name " << name << " and ready to fight with enemy!" <<std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAttackDamage = 20;
	this->rangedAttackDamage = 15;
	this->armorDamageReduction = 3;
	this->energyAttackDamage = 25;
}

SravTrap & SravTrap::operator=( SravTrap const &src ) {
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

SravTrap::SravTrap( SravTrap const & src ) {
	std::cout << "My comrads!!! Copy of " << this->type << " was created with name and ready to fight with enemy!" <<std::endl;
	*this = src;
}

unsigned int SravTrap::getHitPoints( void ) const {
	return this->hitPoints;
}

unsigned int SravTrap::getMaxHitPoints( void ) const {
		return this->maxHitPoints;
}

unsigned int SravTrap::getEnergyPoints( void ) const {
	return this->energyPoints;
}

unsigned int SravTrap::getMaxEnergyPoints( void ) const {
	return this->maxEnergyPoints;
}

unsigned int SravTrap::getLevel( void ) const {
	return this->level;
}

unsigned int SravTrap::getmeleeAttackDamage( void ) const {
	return this->meleeAttackDamage;
}

unsigned int SravTrap::getRangedAttackDamage( void ) const {
	return this->rangedAttackDamage;
}

unsigned int SravTrap::getEnergyAttackDamage( void ) const {
	return this->energyAttackDamage;
}

unsigned int SravTrap::getArmorDamageReduction( void ) const {
	return this->armorDamageReduction;
}

std::string SravTrap::getName( void ) const {
	return this->name;
}

// void SravTrap::setHitPoints( unsigned int name ) {
// 	this->name = name;
// }

// void SravTrap::setMaxHitPoints( unsigned int maxHitPoints ) {
// 	this->maxHitPoints;
// }

// void SravTrap::setEnergyPoints( unsigned int energyPoints ) {
// 	this->energyPoints;
// }

// void SravTrap::setMaxEnergyPoints( unsigned int maxEnergyPoints ) {
// 	this->maxEnergyPoints = maxEnergyPoints;
// }

// void SravTrap::setLevel( unsigned int level ) {
// 	this->level = level;
// }

// void SravTrap::setmeleeAttackDamage( unsigned int meleeAttackDamage ) {
// 	this->meleeAttackDamage = meleeAttackDamage;
// }

// void SravTrap::setRangedAttackDamage( unsigned int rangedAttackDamage ) {
// 	this->rangedAttackDamage = rangedAttackDamage;
// }

// void SravTrap::setEnergyAttackDamage( unsigned int energyAttackDamage ) {
// 	this->energyAttackDamage = energyAttackDamage;
// }

// void SravTrap::setArmorDamageReduction( unsigned int armorDamageReduction ) {
// 	this->armorDamageReduction = armorDamageReduction;
// }

void SravTrap::setName( std::string name) {
	this->name = name;
}

void	SravTrap::takeDamage( unsigned int amount ) {
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

void	SravTrap::takeEnergyDamage( unsigned int amount ) {
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

void SravTrap::beRepaird( unsigned int amount ) {
	if (this->hitPoints + amount > this->maxHitPoints) {
		std::cout << " THX bro!!! I feel better! My health now is 100HP" << std::endl;
		this->hitPoints = this->maxHitPoints;
	}
	else{ 
		std::cout << " THX bro!!! I feel better! My health now is ";
		this->hitPoints += amount;
		std::cout << this->hitPoints << std::endl;
	}
}

void SravTrap::energyRepaird( unsigned int amount ) {
	if (this->energyPoints + amount > this->maxEnergyPoints) {
		std::cout << " THX bro!!! I feel better! My energy now is 100EP" << std::endl;
		this->energyPoints = this->maxEnergyPoints;
	}
	else{ 
		std::cout << " THX bro!!! I feel better! My health now is ";
		this->energyPoints += amount;
		std::cout << this->energyPoints << std::endl;
	}
}

void SravTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->type << this->name << " attacks " << target << " at range, causing "
	<< this->meleeAttackDamage << " points of damage!!!" << std::endl;
}

void SravTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->type << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage << " points of damage!!!" << std::endl;
}

		///////////////////////////////////////////////////////////////
		///////////////////////    MY ATTACK      /////////////////////
		///////////////////////////////////////////////////////////////

void SravTrap::funnyAttack( std::string const & target ) {
	std::cout << "" << this->type << " use funnyAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 20 << " points of damage!!!" << std::endl;
}

void SravTrap::bustyAttack( std::string const & target ) {
	std::cout << "" << this->type << " use bustyAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage - 15 << " points of damage!!!" << std::endl;
}

void SravTrap::fuckingAttack( std::string const & target ) {
	std::cout << "" << this->type << " use fuckingAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 10 << " points of damage!!!" << std::endl;
}

void SravTrap::spekingAttack( std::string const & target ) {
	std::cout << "" << this->type << " use spekingAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage + 50 << " points of damage!!!" << std::endl;
}

void SravTrap::spaceAttack( std::string const & target ) {
	std::cout << "" << this->type << " use spaceAttack and " << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage * 3 << " points of damage!!!" << std::endl;
}

		///////////////////////////////////////////////////////////////
		//////////////    Call random attack      /////////////////////
		///////////////////////////////////////////////////////////////

void SravTrap::challengeNewcomer( std::string const & target ) {
	this->random++;
	void (SravTrap::*ukaz[5])( std::string const & target ) = { &SravTrap::funnyAttack, &SravTrap::bustyAttack,
		&SravTrap::fuckingAttack, &SravTrap::spekingAttack, &SravTrap::spaceAttack };
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
