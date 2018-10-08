#include "GameMap.h"
#include <Windows.h>
#include"Tile.h"
CGameMap::CGameMap(int w, int h, int n)
{
	//m_cMap = (nullptr);
	SetMap(w, h, n);
}

CGameMap::~CGameMap()
{
}

void CGameMap::InitMap()
{
	for (int y = 0; y < m_iHeight; y++)
	{
		for (int x = 0; x < m_iWidth; x++)
		{
			m_cMap[y][x].SetTile(x, y, 0);
		}
	}
}


void CGameMap::UpdateTile(int x, int y)
{
	int iCurX,iCurY;
	for (int ty = -1; ty <= 1; ty++)
	{
		for (int tx = -1; tx <= 1; tx++)
		{
			iCurX = x + tx;
			iCurY = y + ty;
			if (iCurX < 0 || iCurY < 0 || iCurX > m_iWidth - 1 || iCurY > m_iHeight - 1 || m_cMap[iCurY][iCurX].GetNum() == 9)
				continue;
			int iTimeNum = m_cMap[iCurY][iCurX].GetNum();
			m_cMap[iCurY][iCurX].SetTile(iCurX, iCurY, iTimeNum + 1);
		}
	}
}

void CGameMap::SetMines()
{
	int iCurX, iCurY;
	for (int i = 0; i < m_iMineNum; i++)
	{
		do
		{
			iCurX = rand() % m_iWidth;
			iCurY = rand() % m_iHeight;

		} while (m_cMap[iCurY][iCurX].GetNum() == 9);
		m_cMap[iCurY][iCurX].SetTile(iCurX, iCurY, 9);
		UpdateTile(iCurX, iCurY);
	}
}

void CGameMap::SetMap(int w, int h, int n)
{
	if (m_cMap)
	{
		for (int i = 0; i < m_iHeight; i++)
			delete[] m_cMap[i];
		m_cMap = nullptr;
	}

	m_iWidth = w;
	m_iHeight = h;
	m_iMineNum = n;

	m_cMap = new CTile *[m_iHeight];
	for (int i = 0; i < m_iHeight; i++)
	{
		m_cMap[i] = new CTile[m_iWidth];
	}
	InitMap();
	SetMines();
}
#include<iostream>
#include<Windows.h>
using namespace std;
void CGameMap::setTile(int x, int y)
{
	
	
}

void CGameMap::Draw()
{
	for (int iY = 0; iY < m_iHeight; iY++)
	{
		for (int iX = 0; iX < m_iWidth; iX++)
		{
			m_cMap[iY][iX].Draw();
		}
	}
}