#include <iostream>;
#include <Windows.h>
#include "DungeonGen.h"
#include <process.h>
using namespace std;
class TextViewer{
public:
	TextViewer(){width = 0; height = 0; x_pos = 0; y_pos = 0; is_drawing = true; floor = 0;}
	void draw(DungeonGen);

private:
	int width, height;
	int x_pos, y_pos;
	bool is_drawing;
	int floor;
};