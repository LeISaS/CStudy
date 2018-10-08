#pragma once

#include "Tile.h"

class CGameMap
{
	int m_iWidth;
	int m_iHeight;
	int m_iMineNum;
	CTile **m_cMap;

public:
	~CGameMap();
	CGameMap(int w, int h, int n);
	void InitMap();
	void UpdateTile(int x, int y);
	void SetMines();
	void SetMap(int w, int h, int n);
	CTile ** GetMap() { return m_cMap; }
	void setTile(int x, int y);
	void Draw();
};