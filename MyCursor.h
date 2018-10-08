#pragma once

class CMyCursor
{
	int m_iX;      //Ŀ�� X
	int m_iY;      //Ŀ�� Y
	int m_iWidth;  //ȭ�� ����
	int m_iHeight; //ȭ�� ����
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

