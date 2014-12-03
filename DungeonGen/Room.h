#ifndef __DUNGEONROOM_
#define __DUNGEONROOM_
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Monster.h"
#include "MonsterInstance.h"
#include "ItemInstance.h"
#include "Items.h"

enum dir { NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3 };

class Room {
public:
	Room();
	Room(std::ifstream&, std::vector<Monster>&, int);
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

<<<<<<< HEAD
	virtual void generateMonsters(std::vector<Monster>& temp);
	virtual void generateItems(std::vector<Items>& temp);
	virtual void printRoom(char** map, int mx, int my, 
		std::vector<MonsterInstance>& list, std::vector<ItemInstance>& list2);

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