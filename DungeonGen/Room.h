#ifndef __DUNGEONROOM_
#define __DUNGEONROOM_
#include <cstdlib>

enum dir { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3 };

class Room {
public:
	Room();
	~Room() {
		for (int i = 0; i < 4; i++) {
			if (nextRooms[i] != 0) {
				Room* r = nextRooms[i];
				nextRooms[i] = 0;
				delete r;
			}
		}
	}

	//access
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getAdjRooms() { return adjRooms; }

	Room* getRoom(dir d) { return nextRooms[d]; }
	void setRoom(dir d, Room* room);

	virtual void printRoom(int** map, int mx, int my);

	int x, y;
	int id;
protected:
	int width;
	int height;
private:
	Room* nextRooms[4];
	int adjRooms;
};
#endif