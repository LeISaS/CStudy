#include "GameMap.h"
#include "util.h"
#include <Windows.h>
#include <time.h>
#include"MyCursor.h"
#include<conio.h>
#include<iostream>
#include<Windows.h>
using namespace std;
void main()
{
	srand(unsigned int(time(nullptr)));
	
	CGameMap cGameMap(10, 10, 10);
	CMyCursor cursor(0, 0, 10, 10);
	clock_t oldTime, curTime;
	oldTime = clock();
	
	bool isContinue = true;
	ScreenInit(); //화면 초기화
	while (isContinue)
	{
		//draw call
		ScreenClear(); //화면 지운다.
		cGameMap.Draw();
		cursor.Draw();
		ScreenFlipping(); //화면에 보여준다.
		
		int nkey;
		if (_kbhit())
		{
			nkey = _getch();
			switch (nkey)
			{
			case UP:
				cursor.GoUp();
				break;
			case DOWN:
				cursor.GoDown();
				break;
			case LEFT:
				cursor.GoLeft();
				break;
			case RIGHT:
				cursor.GoRight();
				break;
			case SPACE:
			{
				int x = cursor.GetX();
				int y = cursor.GetY();
				if (cGameMap.GetMap()[y][x].GetNum() == 9)
				{
					cout << "지뢰밟음";
					exit(0);
					system("pause");
				}
				cGameMap.setTile(y, x);
				ScreenClear(); //화면 지운다.
				cGameMap.Draw();
				cursor.Draw();
				ScreenFlipping();
			}
				break;
			}
		}

	}
	ScreenRelease(); //화면 해제
}