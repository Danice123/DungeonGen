#include "Room.h"

Room::Room() {
	for (int i = 0; i < 4; i++) nextRooms[i] = 0;
	width = 5 + rand() % 5;
	height = 5 + rand() % 5;

	x = 0;
	y = 0;
	adjRooms = 0;
	id = rand() % 10000;
}

void Room::setRoom(dir d, Room* room) {
	nextRooms[d] = room;
	adjRooms++;

	switch (d) {
	case NORTH:
		if (nextRooms[EAST] != 0 && nextRooms[EAST]->nextRooms[NORTH] != 0) {
			room->nextRooms[EAST] = nextRooms[EAST]->nextRooms[NORTH];
			nextRooms[EAST]->nextRooms[NORTH]->nextRooms[WEST] = room;
			room->adjRooms++;
			nextRooms[EAST]->nextRooms[NORTH]->adjRooms++;
		}
		if (nextRooms[WEST] != 0 && nextRooms[WEST]->nextRooms[NORTH] != 0) {
			room->nextRooms[WEST] = nextRooms[WEST]->nextRooms[NORTH];
			nextRooms[WEST]->nextRooms[NORTH]->nextRooms[EAST] = room;
			room->adjRooms++;
			nextRooms[WEST]->nextRooms[NORTH]->adjRooms++;
		}
		break;
	case SOUTH:
		if (nextRooms[EAST] != 0 && nextRooms[EAST]->nextRooms[SOUTH] != 0) {
			room->nextRooms[EAST] = nextRooms[EAST]->nextRooms[SOUTH];
			nextRooms[EAST]->nextRooms[SOUTH]->nextRooms[WEST] = room;
			room->adjRooms++;
			nextRooms[EAST]->nextRooms[SOUTH]->adjRooms++;
		}
		if (nextRooms[WEST] != 0 && nextRooms[WEST]->nextRooms[SOUTH] != 0) {
			room->nextRooms[WEST] = nextRooms[WEST]->nextRooms[SOUTH];
			nextRooms[WEST]->nextRooms[SOUTH]->nextRooms[EAST] = room;
			room->adjRooms++;
			nextRooms[WEST]->nextRooms[SOUTH]->adjRooms++;
		}
		break;
	case EAST:
		if (nextRooms[NORTH] != 0 && nextRooms[NORTH]->nextRooms[EAST] != 0) {
			room->nextRooms[NORTH] = nextRooms[NORTH]->nextRooms[EAST];
			nextRooms[NORTH]->nextRooms[EAST]->nextRooms[SOUTH] = room;
			room->adjRooms++;
			nextRooms[NORTH]->nextRooms[EAST]->adjRooms++;
		}
		if (nextRooms[SOUTH] != 0 && nextRooms[SOUTH]->nextRooms[EAST] != 0) {
			room->nextRooms[SOUTH] = nextRooms[SOUTH]->nextRooms[EAST];
			nextRooms[SOUTH]->nextRooms[EAST]->nextRooms[NORTH] = room;
			room->adjRooms++;
			nextRooms[SOUTH]->nextRooms[EAST]->adjRooms++;
		}
		break;
	case WEST:
		if (nextRooms[NORTH] != 0 && nextRooms[NORTH]->nextRooms[WEST] != 0) {
			room->nextRooms[NORTH] = nextRooms[NORTH]->nextRooms[WEST];
			nextRooms[NORTH]->nextRooms[WEST]->nextRooms[SOUTH] = room;
			room->adjRooms++;
			nextRooms[NORTH]->nextRooms[WEST]->adjRooms++;
		}
		if (nextRooms[SOUTH] != 0 && nextRooms[SOUTH]->nextRooms[WEST] != 0) {
			room->nextRooms[SOUTH] = nextRooms[SOUTH]->nextRooms[WEST];
			nextRooms[SOUTH]->nextRooms[WEST]->nextRooms[NORTH] = room;
			room->adjRooms++;
			nextRooms[SOUTH]->nextRooms[WEST]->adjRooms++;
		}
		break;
	}
}

void Room::generateMonsters(std::vector<Monster>& temp, std::vector<MonsterInstance>& list, int mx, int my) {
	MonsterInstance m(1, temp[0]);
	m.setCoords(mx + 2, my + 2);
	list.push_back(m);
}
void Room::generateItems(std::vector<Items>& temp, std::vector<ItemInstance>& list, int mx, int my) {
	ItemInstance m(1, temp[0]);
	m.setCoords(mx + 3, my + 3);
	list.push_back(m);
}


void Room::printRoom(char** map, int mx, int my) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++) map[my + i][mx + j] = '1';
}