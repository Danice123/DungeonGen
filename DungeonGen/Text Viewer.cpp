#include "Text Viewer.h"

void gotoxy(int x, int y) 
{ 
  HANDLE hConsoleOutput; 
  COORD dwCursorPosition;

  cout.flush(); 
  dwCursorPosition.X = x; 
  dwCursorPosition.Y = y; 
  hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition); 
}

void TextViewer::draw(DungeonGen gen){

	int WIDTH = gen.getFloor(floor).getWidth();
	int HEIGHT = gen.getFloor(floor).getHeight();
	system("cls");
	gotoxy(0,0);

			for(int a = y_pos; a < y_pos+25 && a < HEIGHT; a++){
				for (int b = x_pos; b<x_pos+75 && b< WIDTH; b++){
					std::cout << gen.getFloor(floor).getTile(b, a);
				}
				cout << endl;
			}	
	while(true){
		gotoxy(0,0);
		while(true){
			if(GetAsyncKeyState(VK_RIGHT)){
				x_pos++;
				//Sleep(10);
				break;
			}
			else if(GetAsyncKeyState(VK_LEFT)){
				x_pos--;
				//Sleep(10);
				break;
			}
			else if(GetAsyncKeyState(VK_UP)){
				y_pos--;
				//Sleep(10);
				break;
			}
			else if(GetAsyncKeyState(VK_DOWN)){
				y_pos++;
				//Sleep(10);
				break;
			}
			else if (GetAsyncKeyState(0x44)) {
				if (floor < gen.getAmountFloors() - 1) {
					floor++;

					WIDTH = gen.getFloor(floor).getWidth();
					HEIGHT = gen.getFloor(floor).getHeight();
					system("cls");
					gotoxy(0,0);

					for(int a = y_pos; a < y_pos+25 && a < HEIGHT; a++){
						for (int b = x_pos; b<x_pos+75 && b< WIDTH; b++){
							std::cout << gen.getFloor(floor).getTile(b, a);
						}
						cout << endl;
					}		
				}
			}
			else if (GetAsyncKeyState(0x55)) {
				if (floor > 0) {
					floor--;

					WIDTH = gen.getFloor(floor).getWidth();
					HEIGHT = gen.getFloor(floor).getHeight();
					system("cls");
					gotoxy(0,0);

					for(int a = y_pos; a < y_pos+25 && a < HEIGHT; a++){
						for (int b = x_pos; b<x_pos+75 && b< WIDTH; b++){
							std::cout << gen.getFloor(floor).getTile(b, a);
						}
						cout << endl;
					}		
				}
			}
		}
		gotoxy(0,0);
		if(x_pos < 0){
			x_pos = 0;
		}
		if(y_pos < 0){
			y_pos = 0;
		}
			for(int a = y_pos; a < y_pos+25 && a < HEIGHT; a++){
				for (int b = x_pos; b<x_pos+75 && b< WIDTH; b++){
					std::cout << gen.getFloor(floor).getTile(b, a);
				}
				cout << endl;
			}	
	}
}