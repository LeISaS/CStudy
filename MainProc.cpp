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
	ScreenInit(); //ȭ�� �ʱ�ȭ
	while (isContinue)
	{
		//draw call
		ScreenClear(); //ȭ�� �����.
		cGameMap.Draw();
		cursor.Draw();
		ScreenFlipping(); //ȭ�鿡 �����ش�.
		
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
					cout << "���ڹ���";
					exit(0);
					system("pause");
				}
				cGameMap.setTile(y, x);
				ScreenClear(); //ȭ�� �����.
				cGameMap.Draw();
				cursor.Draw();
				ScreenFlipping();
			}
				break;
			}
		}

	}
	ScreenRelease(); //ȭ�� ����
}