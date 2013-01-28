/*
 * Inventory.h
 *
 *  Created on: Jan 27, 2013
 *      Author: hmarasigan
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_
#define MAX_SPACE=100;

#include <iostream>
using namespace std;

class Inventory {
public:
  Inventory();
	virtual ~Inventory();

  void setfood(int);
  void setcannon(int);
  void setchain(int);
  void setscatter(int);
  void setexplosive(int);
  void setbooze(int);
  void setrepair(int);

  int getfood();
  int getcannon();
  int getchain();
  int getscatter();
  int getexplosive();
  int getbooze();
  int getrepair();
  //functions
  int sum();
  bool check();

private:
  int food;
  int cannon;
  int chain;
  int scatter;
  int explosive;
  int booze;
  int repair;

};

#endif /* INVENTORY_H_ */
