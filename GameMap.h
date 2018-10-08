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
	bool index(int y, int x) { return (x >= 0 && x < 10 && y >= 0 && y < 10); }
	void setTile(int y, int x);
	void Draw();
};