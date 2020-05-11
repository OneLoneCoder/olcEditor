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
	Refresh();
}

void cTiledResourceViewer::OnRender()
{
	// Clear background
	gfx.Clear({ 128, 128, 128, 255 });

	// Draw sprite 1:1 scale
	if (m_image)
	{
		if (m_image->GetSprite() != nullptr)
		{
			gfx.DrawImage(m_image->GetHardwareID(), { 0, 0 }, m_image->GetSprite()->vSize);

			glBindTexture(GL_TEXTURE_2D, 0);

			olc::vi2d vMaxCells = m_image->GetSprite()->vSize / (m_image->GetGridSize() + m_image->GetGridSpacing());
			olc::vi2d cell;
			for (cell.y = 0; cell.y < vMaxCells.y; cell.y++)
			{
				for (cell.x = 0; cell.x < vMaxCells.x; cell.x++)
				{
					gfx.DrawRect(m_image->GetGridOffset() + (m_image->GetGridSize() + m_image->GetGridSpacing()) * cell, m_image->GetGridSize(), { 255,255,255 });
				}
			}
		}
	}
}



