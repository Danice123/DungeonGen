#ifndef __OVALROOM_
#define __OVALROOM_
#include "Room.h"

class OvalRoom : public Room {
public:
	OvalRoom() : Room() {

	}

	virtual void printRoom(int** map, int mx, int my) {
		for (int y = -1; y < height + 1; y++) {
			int x = 0;
			if (y == -1 || y == height) x = 1;
			int xbound = width;
			if (y == -1 || y == height) xbound = width - 1;

			for (;x < xbound; x++) map[my + y][mx + x] = 1;
		}
	}
};
#endif