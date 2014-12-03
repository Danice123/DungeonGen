#include "DungeonGen.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	system("cls");
	srand(1003);
	DungeonGen gen;

	cout << "Loading Monsters" << endl;
	gen.loadMonsters();
	std::cin.get();

	cout << "Generating map" << endl;
	gen.generateRandom(1);
	std::cin.get();

	cout << "Rendering map" << endl;
	gen.getFloors()[0].genFloorLayout();
	std::cin.get();


	for (int i = 0; i < gen.getFloors()[0].getHeight(); i++) {
		for (int j = 0; j < gen.getFloors()[0].getWidth(); j++) {
			cout << gen.getFloors()[0].getTile(j, i);
		}
		cout << endl;
	}
	std::cin.get();
	return 0;
}