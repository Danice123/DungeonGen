#ifndef __DUNGEONFLOOR_
#define __DUNGEONFLOOR_
#include "Room.h"
#include "OvalRoom.h"
#include <vector>
#include <fstream>
#include "MonsterInstance.h"
#include "ItemInstance.h"

class Floor {
public:
	Floor();
	Floor(std::ifstream&, std::vector<Monster>&);
	~Floor() {
		/*for (int i = 0; i < height; i++) delete [] map[i];
		delete [] map;*/
	}

	void genFloorLayout();

	char getTile(int x, int y) {
		return map[y][x];
	}
	int getWidth() { return width; }
	int getHeight() { return height; }

	void loadMonsters(std::vector<Monster>* l) { monsterTemplates = l; }
	void loadItems(std::vector<Items>* l) { itemTemplates = l; }
private:
	Room spawn;
	char** map;
	int width, height;
	std::vector<MonsterInstance> monsters;
	std::vector<Monster>* monsterTemplates;
	std::vector<ItemInstance> items;
	std::vector<Items>* itemTemplates;
};
#endif