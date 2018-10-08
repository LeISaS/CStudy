#pragma once

class CMyCursor
{
	int m_iX;      //커서 X
	int m_iY;      //커서 Y
	int m_iWidth;  //화면 가로
	int m_iHeight; //화면 세로
public:
	CMyCursor();
	~CMyCursor();
	CMyCursor(int x, int y, int w, int h) : m_iX(x), m_iY(y), m_iWidth(w), m_iHeight(h) {}
	int GetX() { return m_iX; }
	int GetY() { return m_iY; }
	void GoUp() { m_iY - 1 < 0 ? 0 : m_iY--; }
	void GoDown() { m_iY + 1 > m_iHeight - 1 ? 0 : m_iY++; }
	void GoLeft() { m_iX - 1 < 0 ? 0 : m_iX--; }
	void GoRight() { m_iX + 1 > m_iWidth - 1 ? 0 : m_iX++; }

	void Draw();
};

