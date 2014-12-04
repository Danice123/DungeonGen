#include <iostream>;
#include <Windows.h>
#include "DungeonGen.h"
class TextViewer{
public:
	TextViewer(){width = 0; height = 0; x_pos = 0; y_pos = 0; is_drawing = true;}
	void draw(DungeonGen);

private:
	int width, height;
	int x_pos, y_pos;
	bool is_drawing;
};



void TextViewer::draw(DungeonGen gen){

	for (int i = 0; i < gen.getFloor(0).getHeight(); i++) {
		for (int j = 0; j < gen.getFloor(0).getWidth(); j++) {
			std::cout << gen.getFloor(0).getTile(j, i);
		}
		std::cout << std::endl;
	}

	while(true){
		while(true){
			if(GetAsyncKeyState(VK_RIGHT)){
				y_pos++;
				Sleep(10);
				break;
			}
			else if(GetAsyncKeyState(VK_LEFT)){
				y_pos--;
				Sleep(10);
				break;
			}
			else if(GetAsyncKeyState(VK_UP)){
				x_pos--;
				Sleep(10);
				break;
			}
			else if(GetAsyncKeyState(VK_DOWN)){
				x_pos++;
				Sleep(10);
				break;
			}
		}
		system("cls");
		if(x_pos < 0){
			x_pos = 0;
		}
		if(y_pos < 0){
			y_pos = 0;
		}
			for(int a = x_pos; a < x_pos+70 && a < gen.getFloor(0).getWidth(); a++){
				for (int b = y_pos; b<y_pos+70 && b< gen.getFloor(0).getHeight(); b++){
					std::cout << gen.getFloor(0).getTile(a, b);
				}
				std::cout << std::endl;
			}	
	}
}