#include <iostream>;
#include <Windows.h>
#include "DungeonGen.h"
#include <process.h>
using namespace std;
class TextViewer{
public:
	TextViewer(){width = 0; height = 0; x_pos = 0; y_pos = 0; is_drawing = true;}
	void draw(DungeonGen);

private:
	int width, height;
	int x_pos, y_pos;
	bool is_drawing;
};



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

	const int WIDTH = gen.getFloor(0).getWidth();
	const int HEIGHT = gen.getFloor(0).getHeight();
	system("cls");
	gotoxy(0,0);

			for(int a = y_pos; a < y_pos+25 && a < HEIGHT; a++){
				for (int b = x_pos; b<x_pos+75 && b< WIDTH; b++){
					std::cout << gen.getFloor(0).getTile(b, a);
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
					std::cout << gen.getFloor(0).getTile(b, a);
				}
				cout << endl;
			}	
	}
}