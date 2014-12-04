#include "DungeonGen.h"
#include <iostream>
#include "Windows.h"
#include "Text Viewer.h"
using std::cout;
using std::endl;

int main() {
	system("cls");
	DungeonGen gen;
	cout << "Loading Monsters" << endl;
	gen.loadMonsters();
	cout << "Loading Items" << endl;
	gen.loadItems();
	std::cin.get();
	system("cls");

	cout << "What type of map do you wish to view?" << endl;
	cout << "1: Random" << endl;
	cout << "2: Load from file" << endl;
	int in;
	std::cin >> in;
	if (in == 1) {
		cout << "Generating map" << endl;
		gen.generateRandom(2);
	}
	if (in == 2) {
		cout << "Loading map" << endl;
		gen.loadFromFile("test.txt");
	}
	cout << "Rendering map" << endl;
	for (int i = 0; i < gen.getAmountFloors(); i++) gen.getFloor(i).genFloorLayout();
	std::cin.get();

	TextViewer my_viewer;
	my_viewer.draw(gen);
	std::cin.get();
	return 0;
}