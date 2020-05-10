#include "cTiledResourceViewer.h"

cTiledResourceViewer::cTiledResourceViewer(wxWindow* parent, wxGLContext* gl) : cPanAndZoomRenderer(parent, gl)
{
}

cTiledResourceViewer::~cTiledResourceViewer()
{
}

void cTiledResourceViewer::SetImageResource(std::shared_ptr<cImageResource> image)
{
	m_image = image;
}

void cTiledResourceViewer::OnRender()
{
	// Clear background
	gfx.Clear({ 128, 128, 128, 255 });

	// Draw sprite 1:1 scale
	gfx.DrawImage(m_image->GetHardwareID(), { 0, 0 }, m_image->GetSprite()->vSize);

	glBindTexture(GL_TEXTURE_2D, 0);

	olc::vi2d vMaxCells = m_image->GetSprite()->vSize / (m_vGridSize + m_vGridSpacing);
	olc::vi2d cell;
	for (cell.y = 0; cell.y < vMaxCells.y; cell.y++)
	{
		for (cell.x = 0; cell.x < vMaxCells.x; cell.x++)
		{
			gfx.DrawRect(m_vGridOffset + (m_vGridSize + m_vGridSpacing) * cell, m_vGridSize, { 255,255,255 });
		}
	}
}


void cTiledResourceViewer::SetGridSize(const olc::vi2d& size)
{
	m_vGridSize = size;
	Refresh();
}

void cTiledResourceViewer::SetGridOffset(const olc::vi2d& offset)
{
	m_vGridOffset = offset;
	Refresh();
}

void cTiledResourceViewer::SetGridSpacing(const olc::vi2d& spacing)
{
	m_vGridSpacing = spacing;
	Refresh();
}
