#include "DungeonGen.h"
#include <string>
#include <fstream>
using std::string;

void DungeonGen::generateRandom(int size) {
	nFloors = size;
	floors = new Floor[size];
	for (int i = 0; i < size; i++) {
		floors[i].initializeRandom(monsterList, itemList);
	}
}

void DungeonGen::loadFromFile(std::string name) {
	std::ifstream fin;

	fin.open(name);
	fin >> nFloors;
	floors = new Floor[nFloors];
	for (int i = 0; i < nFloors; i++) {
		floors[i].initializeFromFile(fin, monsterList, itemList);
	}
	fin.close();
}

void DungeonGen::loadMonsters() {
	std::ifstream fin;
	fin.open("monsters/monsters.list");
	std::vector<string> names;

	for (string s;!fin.eof();s = "") {
		fin >> s;
		names.push_back(s);
	}

	for (int i = 0; i < names.size(); i++)
		monsterList.push_back(Monster(names[i]));

	fin.close();
}

void DungeonGen::loadItems() {
	std::ifstream fin;
	fin.open("items/items.list");
	std::vector<string> names;

	for (string s;!fin.eof();s = "") {
		fin >> s;
		names.push_back(s);
	}

	for (int i = 0; i < names.size(); i++)
		itemList.push_back(Items(names[i]));

	fin.close();
}