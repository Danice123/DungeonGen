#ifndef __DUNGEONFLOOR_
#define __DUNGEONFLOOR_
#include "Room.h"
#include "OvalRoom.h"
#include <vector>

class Floor {
public:
	Floor();
	~Floor() {
		for (int i = 0; i < height; i++) delete [] map[i];
		delete [] map;
	}
	void genFloorLayout();

	int getTile(int x, int y) {
		return map[y][x];
	}
	int getWidth() { return width; }
	int getHeight() { return height; }
private:
	Room spawn;
	int** map;
	int width, height;
};
#endif