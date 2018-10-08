#include "MyCursor.h"
#include "util.h"
#include<string >

CMyCursor::CMyCursor() : m_iX(0),m_iY(0),m_iWidth(80),m_iHeight(25)
{
}


CMyCursor::~CMyCursor()
{
}

void CMyCursor::Draw()
{
	const char *cursorImg = "бу";
	ScreenPrint(m_iX * 2, m_iY, cursorImg);
}
