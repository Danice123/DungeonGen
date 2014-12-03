#ifndef __DUNGEONGEN_
#define __DUNGEONGEN_
#include "Floor.h"
#include "Monster.h"
#include <vector>

class DungeonGen {
public:
	DungeonGen() {}

	void generateRandom(int floors);
	void loadMonsters();

	std::vector<Floor> getFloors() { return floors; }
private:
	std::vector<Floor> floors;
	std::vector<Monster> monsterList;
};
#endif