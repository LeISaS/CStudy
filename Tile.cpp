#include "Tile.h"
#include "util.h"

CTile::CTile()
{
	m_bOpen = false;
}


CTile::~CTile()
{
}
void CTile::Draw()
{
	const char *imgs[] = { "��","��","��","��","��","��","��","��","��","��"};

	if (!m_bOpen)
		ScreenPrint(m_iX * 2, m_iY, "��");
	else
		ScreenPrint(m_iX * 2, m_iY, imgs[m_iNum]);
	
}
