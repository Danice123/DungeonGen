#include "DungeonGen.h"
#include <iostream>
#include "Windows.h"
#include "Text Viewer.h"
using std::cout;
using std::endl;

int main() {
	system("cls");
	srand(1003);
	DungeonGen gen;
	TextViewer my_viewer;
	cout << "Loading Monsters" << endl;
	gen.loadMonsters();
	std::cin.get();
	
	cout << "Loading Items" << endl;
	gen.loadItems();
	std::cin.get();

	cout << "Generating map" << endl;
	gen.generateRandom(1);
	std::cin.get();

	/*cout << "Loading map" << endl;
	gen.loadFromFile("test.txt");
	std::cin.get();*/

	cout << "Rendering map" << endl;
	gen.getFloor(0).genFloorLayout();
	std::cin.get();

	
	
	/*	*/
	std::cin.get();
	my_viewer.draw(gen);

	std::cin.get();
	return 0;
}