// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/04/06 10:48:58 by tlutsyk           #+#    #+#             //
//   Updated: 2018/04/06 10:49:00 by tlutsyk          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::ClapTrap (): hitPoints(100), maxHitPoints(100), level(1), name("XZ")  {
	setEnergyPoints(0);
	setEnergyPoints(0);
	setmeleeAttackDamage(0);
	setRangedAttackDamage(0);
	setArmorDamageReduction(0);
	setEnergyAttackDamage(0);
	this->random = 0;
	this->type = "ClapTrap";
	std::cout << this->type << " Constructor called!!!" <<std::endl;
}

ClapTrap::ClapTrap( std::string const & name ) :  hitPoints(100), maxHitPoints(100), level(1), name(name) {
	this->energyPoints = 0;
	this->maxEnergyPoints = 0;
	this->meleeAttackDamage = 0;
	this->rangedAttackDamage = 0;
	this->armorDamageReduction = 0;
	this->energyAttackDamage = 0;
	this->random = 0;
	this->type = "ClapTrap";
	std::cout << this->type << " constructor called!" <<std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {
	std::cout << this->type << "Copy Constructor called!!!" <<std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Fuck!!! Destructor " << this->type << " called!!!" << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap const &src ) {
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

unsigned int ClapTrap::getHitPoints( void ) const { return this->hitPoints; }
unsigned int ClapTrap::getMaxHitPoints( void ) const { return this->maxHitPoints; }
unsigned int ClapTrap::getEnergyPoints( void ) const { return this->energyPoints; }
unsigned int ClapTrap::getMaxEnergyPoints( void ) const { return this->maxEnergyPoints; }
unsigned int ClapTrap::getLevel( void ) const {	return this->level; }
unsigned int ClapTrap::getmeleeAttackDamage( void ) const {	return this->meleeAttackDamage; }
unsigned int ClapTrap::getRangedAttackDamage( void ) const { return this->rangedAttackDamage;}
unsigned int ClapTrap::getEnergyAttackDamage( void ) const { return this->energyAttackDamage; }
unsigned int ClapTrap::getArmorDamageReduction( void ) const { return this->armorDamageReduction; }
std::string ClapTrap::getName( void ) const { return this->name; }


void ClapTrap::setHitPoints( unsigned int name ) { this->name = name; }
void ClapTrap::setMaxHitPoints( unsigned int maxHitPoints ) { this->maxHitPoints = maxHitPoints; }
void ClapTrap::setEnergyPoints( unsigned int energyPoints ) { this->energyPoints = energyPoints; }
void ClapTrap::setMaxEnergyPoints( unsigned int maxEnergyPoints ) {	this->maxEnergyPoints = maxEnergyPoints; }
void ClapTrap::setLevel( unsigned int level ) {	this->level = level; }
void ClapTrap::setmeleeAttackDamage( unsigned int meleeAttackDamage ) { this->meleeAttackDamage = meleeAttackDamage; }
void ClapTrap::setRangedAttackDamage( unsigned int rangedAttackDamage ) { this->rangedAttackDamage = rangedAttackDamage; }
void ClapTrap::setEnergyAttackDamage( unsigned int energyAttackDamage ) { this->energyAttackDamage = energyAttackDamage; }
void ClapTrap::setArmorDamageReduction( unsigned int armorDamageReduction ) { this->armorDamageReduction = armorDamageReduction; }
void ClapTrap::setName( std::string name) { this->name = name; }

void	ClapTrap::takeDamage( unsigned int amount ) {
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

void	ClapTrap::takeEnergyDamage( unsigned int amount ) {
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


void ClapTrap::beRepaird( unsigned int amount ) {
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

void ClapTrap::energyRepaird( unsigned int amount ) {
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

void ClapTrap::meleeAttack( std::string const & target ) const {
	std::cout << this->type << this->name << " attacks " << target << " at range, causing "
	<< this->meleeAttackDamage << " points of damage!!!" << std::endl;
}

void ClapTrap::rangedAttack( std::string const & target ) const {
	std::cout << this->type << this->name << " attacks " << target << " at range, causing "
	<< this->rangedAttackDamage << " points of damage!!!" << std::endl;
}
