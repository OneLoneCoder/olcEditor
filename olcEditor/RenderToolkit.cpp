#include "RenderToolkit.h"

RenderToolkit::RenderToolkit()
{
}

olc::vf2d RenderToolkit::WorldToScreen(const olc::vf2d& point)
{
	return (point - vWorldOffset) * vWorldScale;
}

olc::vf2d RenderToolkit::ScreenToWorld(const olc::vf2d& point)
{
	return point / vWorldScale + vWorldOffset;
}

olc::vf2d RenderToolkit::ProjectToView(const olc::vf2d& point)
{
	olc::vf2d out;
	out.x = point.x / vWorldView.x - 1.0f;
	out.y = -(point.y / vWorldView.y - 1.0f);
	return out;
}

void RenderToolkit::Clear(const olc::Pixel& colour)
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void RenderToolkit::DrawLine(const olc::vf2d& start, const olc::vf2d& end, const olc::Pixel col, const float width)
{
	olc::vf2d s = ProjectToView(WorldToScreen({ start.x, start.y }));
	olc::vf2d e = ProjectToView(WorldToScreen({ end.x, end.y }));

	glLineWidth(width);
	glBegin(GL_LINES);
	glColor4ub(col.r, col.g, col.b, col.a);
	glVertex2f(s.x, s.y);
	glVertex2f(e.x, e.y);
	glEnd();
}

void RenderToolkit::DrawRect(const olc::vf2d& start, const olc::vf2d& size, const olc::Pixel col, const float width)
{
	olc::vf2d s = ProjectToView(WorldToScreen({ start.x, start.y }));
	olc::vf2d e = ProjectToView(WorldToScreen({ start.x + size.x, start.y + size.y }));

	glLineWidth(width);
	glBegin(GL_LINES);
	glColor4ub(col.r, col.g, col.b, col.a);
	glVertex2f(s.x, s.y);
	glVertex2f(s.x, e.y);
	glVertex2f(s.x, e.y);
	glVertex2f(e.x, e.y);
	glVertex2f(e.x, e.y);
	glVertex2f(e.x, s.y);
	glVertex2f(e.x, s.y);
	glVertex2f(s.x, s.y);
	glEnd();
}

void RenderToolkit::FillRect(const olc::vf2d& start, const olc::vf2d& size, const olc::Pixel col, const float width)
{
	olc::vf2d s = ProjectToView(WorldToScreen({ start.x, start.y }));
	olc::vf2d e = ProjectToView(WorldToScreen({ start.x + size.x, start.y + size.y }));

	glBegin(GL_QUADS);
	glColor4ub(col.r, col.g, col.b, col.a);
	glVertex2f(s.x, s.y);
	glVertex2f(s.x, e.y);
	glVertex2f(e.x, e.y);
	glVertex2f(e.x, s.y);
	glEnd();
}

void RenderToolkit::DrawImage(int nResourceID, const olc::vf2d& start, const olc::vf2d& size, const olc::Pixel col)
{
	olc::vf2d s = ProjectToView(WorldToScreen({ start.x, start.y }));
	olc::vf2d e = ProjectToView(WorldToScreen({ start.x + size.x, start.y + size.y }));
	glBindTexture(GL_TEXTURE_2D, nResourceID);
	glBegin(GL_QUADS);
	glColor4ub(col.r, col.g, col.b, col.a);
	glTexCoord2f(0,0); glVertex2f(s.x, s.y);
	glTexCoord2f(0,1); glVertex2f(s.x, e.y);
	glTexCoord2f(1,1); glVertex2f(e.x, e.y);
	glTexCoord2f(1,0); glVertex2f(e.x, s.y);
	glEnd();
}


void RenderToolkit::DrawSubImage(int nResourceID, const olc::vf2d& pos, const olc::vf2d& size, const olc::vf2d& sourcepos, const olc::vf2d& sourcesize, const olc::Pixel col)
{
	olc::vf2d s = ProjectToView(WorldToScreen({ pos.x, pos.y }));
	olc::vf2d e = ProjectToView(WorldToScreen({ pos.x + size.x, pos.y + size.y }));
	glBindTexture(GL_TEXTURE_2D, nResourceID);
	glBegin(GL_QUADS);
	glColor4ub(col.r, col.g, col.b, col.a);
	glTexCoord2f(sourcepos.x, sourcepos.y); glVertex2f(s.x, s.y);
	glTexCoord2f(sourcepos.x, sourcepos.y + sourcesize.y); glVertex2f(s.x, e.y);
	glTexCoord2f(sourcepos.x + sourcesize.x, sourcepos.y + sourcesize.y); glVertex2f(e.x, e.y);
	glTexCoord2f(sourcepos.x + sourcesize.x, sourcepos.y); glVertex2f(e.x, s.y);
	glEnd();
}