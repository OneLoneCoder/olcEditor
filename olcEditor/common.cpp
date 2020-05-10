#include "common.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace olc
{
	// O------------------------------------------------------------------------------O
	// | olc::Pixel IMPLEMENTATION                                                    |
	// O------------------------------------------------------------------------------O
	Pixel::Pixel()
	{
		r = 0; g = 0; b = 0; a = 0xFF;
	}

	Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
	{
		n = red | (green << 8) | (blue << 16) | (alpha << 24);
	} 

	Pixel::Pixel(uint32_t p)
	{
		n = p;
	}

	bool Pixel::operator==(const Pixel& p) const
	{
		return n == p.n;
	}

	bool Pixel::operator!=(const Pixel& p) const
	{
		return n != p.n;
	}

	Pixel PixelF(float red, float green, float blue, float alpha)
	{
		return Pixel(uint8_t(red * 255.0f), uint8_t(green * 255.0f), uint8_t(blue * 255.0f), uint8_t(alpha * 255.0f));
	}


	Sprite::Sprite()
	{
		pColData = nullptr; vSize = { 0,0 };
	}

	Sprite::Sprite(const std::string& sImageFile)
	{
		LoadFromFile(sImageFile);
	}

	Sprite::Sprite(int32_t w, int32_t h)
	{
		if (pColData) delete[] pColData;
		vSize.x = w; vSize.y = h;
		pColData = new Pixel[vSize.x * vSize.y];
		for (int32_t i = 0; i < vSize.x * vSize.y; i++)
			pColData[i] = Pixel();
	}

	Sprite::~Sprite()
	{
		if (pColData) delete[] pColData;
	}

	Pixel Sprite::GetPixel(const olc::vi2d& a) const
	{
		return GetPixel(a.x, a.y);
	}

	bool Sprite::SetPixel(const olc::vi2d& a, Pixel p)
	{
		return SetPixel(a.x, a.y, p);
	}

	Pixel Sprite::GetPixel(int32_t x, int32_t y) const
	{		
		if (x >= 0 && x < vSize.x && y >= 0 && y < vSize.y)
			return pColData[y * vSize.x + x];
		else
			return Pixel(0, 0, 0, 0);
		
	}

	bool Sprite::SetPixel(int32_t x, int32_t y, Pixel p)
	{
		if (x >= 0 && x < vSize.x && y >= 0 && y < vSize.y)
		{
			pColData[y * vSize.x + x] = p;
			return true;
		}
		else
			return false;
	}

	Pixel* Sprite::GetData()
	{
		return pColData;
	}

	bool Sprite::LoadFromFile(const std::string& sImageFile)
	{
		stbi_uc* bytes = nullptr;
		int w = 0, h = 0, cmp = 0;
		bytes = stbi_load(sImageFile.c_str(), &w, &h, &cmp, 4);
		if (!bytes) return false;

		if (pColData) delete[] pColData;
		vSize.x = w; vSize.y = h;
		pColData = new Pixel[vSize.x * vSize.y];
		std::memcpy(pColData, bytes, w * h * 4);
		delete[] bytes;
		return true;
	}
}