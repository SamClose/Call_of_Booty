#include <iostream>
#include "item.h"

using namespace std;

int Item::getItem(Item[] itemArray, Item item) {
	int i = 0, location;
	bool exit = false;
	while ( exit ) {
		if (itemArray[i]==item) {
			location = i;
			exit = true;
		}
		else if (itemArray[i] != item) {
			i++;
		}
		else if (i == itemArray.length - 1 && itemArray[itemArray.length-1] != item) {
			location = 0;
			exit = true;
		}
	}
	if( location == 0 ) {
		cout << "Item not in array." << endl;
	}
	return location;
}

string Item::getItemName() {
	return itemName;
}

void Item::setItemName(string name) {
	itemName = name;
}

string Item::getItemType() {
	return itemType;
}

void Item::setItemType(string type) {
	itemType = type;
}
/* End of item.cpp */
