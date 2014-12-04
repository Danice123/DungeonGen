#include "Room.h"

Room::Room() {
	initialized = false;
	for (int i = 0; i < 4; i++) nextRooms[i] = 0;
	x = 0;
	y = 0;
	adjRooms = 0;
	id = rand() % 10000;
}

void Room::initializeRandom(std::vector<Monster>& tempM, std::vector<Items>& tempI, int level) {
	initialized = true;
	width = 5 + rand() % 5;
	height = 5 + rand() % 5;

	MonsterInstance m(level, tempM[0]);
	m.setCoords(2, 2);
	monsters.push_back(m);

	ItemInstance i(level, tempI[0]);
	i.setCoords(3, 3);
	items.push_back(i);
}

void Room::initializeFromFile(std::ifstream& fin, std::vector<Monster>& temp, std::vector<Items>& temp2, int level) {
	initialized = true;
	fin >> width;
	fin >> height;

	int nMonsters;
	fin >> nMonsters;
	for (int i = 0; i < nMonsters; i++) {
		std::string name;
		fin >> name;
		MonsterInstance* m = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (!name.compare(temp[i].getName()))
				m = new MonsterInstance(level, temp[i]);
		}
		if (m == 0) throw "bad monster name";
		int x, y;
		fin >> x;
		fin >> y;
		m->setCoords(x, y);
		monsters.push_back(*m);
	}

	int nItems;
	fin >> nItems;
	for (int i = 0; i < nItems; i++) {
		std::string name;
		fin >> name;
		ItemInstance* m = 0;
		for (int i = 0; i < temp2.size(); i++) {
			if (!name.compare(temp2[i].getName()))
				m = new ItemInstance(level, temp2[i]);
		}
		if (m == 0) throw "bad item name";
		int x, y;
		fin >> x;
		fin >> y;
		m->setCoords(x, y);
		items.push_back(*m);
	}
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

void Room::printRoom(char** map, int mx, int my, std::vector<MonsterInstance>& list, std::vector<ItemInstance>& list2) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++) map[my + i][mx + j] = '1';

		for (int i = 0; i < monsters.size(); i++) {
			monsters[i].setCoords(monsters[i].getX() + mx, monsters[i].getY() + my);
			list.push_back(monsters[i]);
		}

		for (int i = 0; i < items.size(); i++) {
			items[i].setCoords(items[i].getX() + mx, items[i].getY() + my);
			list2.push_back(items[i]);
		}
}