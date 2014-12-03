#include "DungeonGen.h"
#include <string>
#include <fstream>
using std::string;

void DungeonGen::generateRandom(int size) {
	nFloors = size;
	floors = new Floor[size];
	for (int i = 0; i < size; i++) {
		floors[i].loadMonsters(&monsterList);
	}
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