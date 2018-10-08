#pragma once
class CTile
{
	int m_iX;
	int m_iY;
	int m_iNum;
	bool m_bOpen;
public:
	CTile();
	~CTile();
	CTile(int x,int y, int n) : m_iX(x), m_iY(y), m_iNum(n), m_bOpen(false){}
	void SetTile(int x, int y, int n) { m_iX = x; m_iY = y; m_iNum = n; }
	int GetX() { return m_iX; }
	int GetY() { return m_iY; }
	int GetNum() { return m_iNum; }
	bool IsOpen() { return m_bOpen; }
	void SetOpen(bool bOpen) { m_bOpen = bOpen; }
	void Draw();
};

