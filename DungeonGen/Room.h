#ifndef __DUNGEONROOM_
#define __DUNGEONROOM_
#include <cstdlib>
#include <vector>
#include "Monster.h"
#include "MonsterInstance.h"

enum dir { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3 };

class Room {
public:
	Room();
	~Room() {
		/*for (int i = 0; i < 4; i++) {
			if (nextRooms[i] != 0) {
				delete nextRooms[i];
				nextRooms[i] = 0;
			}
		}*/
	}

	//access
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getAdjRooms() { return adjRooms; }

	Room* getRoom(dir d) { return nextRooms[d]; }
	void setRoom(dir d, Room* room);

	virtual void generateMonsters(std::vector<Monster>& temp, std::vector<MonsterInstance>&, int mx, int my);
	virtual void printRoom(char** map, int mx, int my);

	int x, y;
	int id;
protected:
	int width;
	int height;
	std::vector<MonsterInstance> monsters;
private:
	Room* nextRooms[4];
	int adjRooms;
};
#endif