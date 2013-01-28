/*
 * Inventory.cpp
 *
 *  Created on: Jan 27, 2013
 *      Author: hmarasigan
 */

#include "Inventory.h"

Inventory::Inventory()
{
  food=0;
	cannon=0;
	chain=0;
	scatter=0;
	explosive=0;
	booze=0;
	repair=0;
	sum();
}

Inventory::~Inventory() {
	delete Inventory();
}

void Inventory::setfood(int x)
{
	food=x;
}
void Inventory::setcannon(int x)
{
	cannon=x;
}
void Inventory::setchain(int x)
{
	chain=x;
}
void Inventory::setscatter(int x)
{
	scatter=x;
}
void Inventory::setexplosive(int x)
{
	explosive=x;
}
void Inventory::setbooze(int x)
{
	booze=x;
}
void Inventory::setrepair(int x)
{
	repair=x;
}

int Inventory::getfood()
{
	return food;
}
int Inventory::getcannon()
{
	return cannon;
}
int Inventory::getchain()
{
	return chain;
}
int Inventory::getscatter()
{
	return scatter;
}
int Inventory::getexplosive()
{
	return explosive;
}
int Inventory::getbooze()
{
	return booze;
}
int Inventory::getrepair()
{
	return repair;
}

//functions
int Inventory::sum()
{
	int sum=food+cannon+chain+scatter+explosive+booze+repair;
	return sum;
}
bool Inventory::check()
{
	if (sum<100)		
		return true;
	else 
		return false;
}
