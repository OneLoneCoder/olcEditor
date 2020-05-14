#include "cTiledResourceViewer.h"

cTiledResourceViewer::cTiledResourceViewer(wxWindow* parent, wxGLContext* gl, std::shared_ptr<cGridSelection> gridselect) : cPanAndZoomRenderer(parent, gl)
{
	m_selection = gridselect;
	if(m_selection) m_selection->Clear();
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
					//gfx.DrawRect(m_image->GetGridOffset() + (m_image->GetGridSize() + m_image->GetGridSpacing()) * cell, m_image->GetGridSize(), { 255,255,255 });

					if (m_selection && !m_selection->setSelected.empty())
					{
						if(!m_selection->InSelection(cell))
							gfx.FillRect(m_image->GetGridOffset() + (m_image->GetGridSize() + m_image->GetGridSpacing()) * cell, m_image->GetGridSize(), { 0,0,0, 64 });
						else
							gfx.DrawRect(m_image->GetGridOffset() + (m_image->GetGridSize() + m_image->GetGridSpacing()) * cell, m_image->GetGridSize(), { 255,255,255 });

					}
					else
						gfx.DrawRect(m_image->GetGridOffset() + (m_image->GetGridSize() + m_image->GetGridSpacing()) * cell, m_image->GetGridSize(), { 255,255,255 });

				}
			}

			// Draw Selection root
			if (m_selection && !m_selection->setSelected.empty())
				gfx.DrawRect(m_image->GetGridOffset() + (m_image->GetGridSize() + m_image->GetGridSpacing()) * m_selection->vRoot, m_image->GetGridSize(), { 255,255,0 });


			//// Draw Transient Selection
			//for (auto& s : m_selection.setSelected)
			//{
			//	gfx.DrawRect(m_image->GetGridOffset() + (m_image->GetGridSize() + m_image->GetGridSpacing()) * s, m_image->GetGridSize(), { 255,255,0 });
			//}
		}
	}
}

void cTiledResourceViewer::OnMouseLeftUp(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
	m_bDragging = false;
}

void cTiledResourceViewer::OnMouseLeftDown(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
	if (m_image)
	{		
		olc::vi2d cell = (vWorldPos - m_image->GetGridOffset()) / (m_image->GetGridSize() + m_image->GetGridSpacing());

		if (m_selection)
		{
			if (!bControl)
				m_selection->Clear();

			m_selection->Select(cell);
		}
		m_bDragging = true;
		m_vStartDrag = cell;
		Refresh();
	}
}

void cTiledResourceViewer::OnMouseMove(const olc::vf2d& vWorldPos, const bool bShift, const bool bControl)
{
	if (m_image)
	{
		if (m_bDragging)
		{
			olc::vi2d cell = (vWorldPos - m_image->GetGridOffset()) / (m_image->GetGridSize() + m_image->GetGridSpacing());
			if(m_selection) m_selection->Region(m_vStartDrag, cell);
			Refresh();
		}
	}
}



