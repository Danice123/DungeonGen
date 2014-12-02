#ifndef __DUNGEONGEN_
#define __DUNGEONGEN_
#include "Floor.h"
#include "Monster.h"
#include <vector>

class DungeonGen {
public:
	DungeonGen() {}
	~DungeonGen() {
		delete [] floors;
	}

	//generation
	void generateRandom(int floors);
	void loadMonsters();

	//access
	Floor& getFloor(int i) { return floors[i]; }
	int getAmountFloors() { return nFloors; }
private:
	Floor* floors;
	int nFloors;
	std::vector<Monster> monsterList;
};
#endif