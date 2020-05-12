#pragma once
#include <cstdint>
#include <cmath>
#include <list>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <unordered_set>
#include <cstring>

namespace olc
{

	template <class T>
	struct v2d_generic
	{
		T x = 0;
		T y = 0;
		inline v2d_generic() : x(0), y(0) {                                                            }
		inline v2d_generic(T _x, T _y) : x(_x), y(_y) {                                                            }
		inline v2d_generic(const v2d_generic& v) : x(v.x), y(v.y) {                                                            }
		inline T mag() { return std::sqrt(x * x + y * y); }
		inline T mag2() { return x * x + y * y; }
		inline v2d_generic  norm() { T r = 1 / mag(); return v2d_generic(x * r, y * r); }
		inline v2d_generic  perp() { return v2d_generic(-y, x); }
		inline T dot(const v2d_generic& rhs) { return this->x * rhs.x + this->y * rhs.y; }
		inline T cross(const v2d_generic& rhs) { return this->x * rhs.y - this->y * rhs.x; }
		inline v2d_generic  operator +  (const v2d_generic& rhs) const { return v2d_generic(this->x + rhs.x, this->y + rhs.y); }
		inline v2d_generic  operator -  (const v2d_generic& rhs) const { return v2d_generic(this->x - rhs.x, this->y - rhs.y); }
		inline v2d_generic  operator *  (const T& rhs)           const { return v2d_generic(this->x * rhs, this->y * rhs); }
		inline v2d_generic  operator *  (const v2d_generic& rhs) const { return v2d_generic(this->x * rhs.x, this->y * rhs.y); }
		inline v2d_generic  operator /  (const T& rhs)           const { return v2d_generic(this->x / rhs, this->y / rhs); }
		inline v2d_generic  operator /  (const v2d_generic& rhs) const { return v2d_generic(this->x / rhs.x, this->y / rhs.y); }
		inline v2d_generic& operator += (const v2d_generic& rhs) { this->x += rhs.x; this->y += rhs.y; return *this; }
		inline v2d_generic& operator -= (const v2d_generic& rhs) { this->x -= rhs.x; this->y -= rhs.y; return *this; }
		inline v2d_generic& operator *= (const T& rhs) { this->x *= rhs; this->y *= rhs; return *this; }
		inline v2d_generic& operator /= (const T& rhs) { this->x /= rhs; this->y /= rhs; return *this; }
		inline operator v2d_generic<int32_t>() const { return { static_cast<int32_t>(this->x), static_cast<int32_t>(this->y) }; }
		inline operator v2d_generic<float>() const { return { static_cast<float>(this->x), static_cast<float>(this->y) }; }
		inline operator v2d_generic<double>() const { return { static_cast<double>(this->x), static_cast<double>(this->y) }; }
	};

	template<class T> inline v2d_generic<T> operator * (const float& lhs, const v2d_generic<T>& rhs)
	{
		return v2d_generic<T>((T)(lhs * (float)rhs.x), (T)(lhs * (float)rhs.y));
	}
	template<class T> inline v2d_generic<T> operator * (const double& lhs, const v2d_generic<T>& rhs)
	{
		return v2d_generic<T>((T)(lhs * (double)rhs.x), (T)(lhs * (double)rhs.y));
	}
	template<class T> inline v2d_generic<T> operator * (const int& lhs, const v2d_generic<T>& rhs)
	{
		return v2d_generic<T>((T)(lhs * (int)rhs.x), (T)(lhs * (int)rhs.y));
	}
	template<class T> inline v2d_generic<T> operator / (const float& lhs, const v2d_generic<T>& rhs)
	{
		return v2d_generic<T>((T)(lhs / (float)rhs.x), (T)(lhs / (float)rhs.y));
	}
	template<class T> inline v2d_generic<T> operator / (const double& lhs, const v2d_generic<T>& rhs)
	{
		return v2d_generic<T>((T)(lhs / (double)rhs.x), (T)(lhs / (double)rhs.y));
	}
	template<class T> inline v2d_generic<T> operator / (const int& lhs, const v2d_generic<T>& rhs)
	{
		return v2d_generic<T>((T)(lhs / (int)rhs.x), (T)(lhs / (int)rhs.y));
	}

	template<class T> inline bool operator == (const v2d_generic<T>& lhs, const v2d_generic<T>& rhs)
	{
		return (lhs.x == rhs.x && lhs.y == rhs.y);
	}



	typedef v2d_generic<int32_t> vi2d;
	typedef v2d_generic<uint32_t> vu2d;
	typedef v2d_generic<float> vf2d;
	typedef v2d_generic<double> vd2d;

	struct Pixel
	{
		union
		{
			uint32_t n = 0xFF000000;
			struct { uint8_t r; uint8_t g; uint8_t b; uint8_t a; };
		};

		enum Mode { NORMAL, MASK, ALPHA, CUSTOM };

		Pixel();
		Pixel(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0xFF);
		Pixel(uint32_t p);
		bool operator==(const Pixel& p) const;
		bool operator!=(const Pixel& p) const;
	};

	Pixel PixelF(float red, float green, float blue, float alpha = 1.0f);


	class Sprite
	{
	public:
		Sprite();
		Sprite(const std::string& sImageFile);
		Sprite(int32_t w, int32_t h);
		~Sprite();

	public:
		bool LoadFromFile(const std::string& sImageFile);

	public:
		olc::vi2d vSize;

	public:
		Pixel GetPixel(int32_t x, int32_t y) const;
		bool  SetPixel(int32_t x, int32_t y, Pixel p);
		Pixel GetPixel(const olc::vi2d& a) const;
		bool  SetPixel(const olc::vi2d& a, Pixel p);
		Pixel* GetData();
		Pixel* pColData = nullptr;
	};
}

namespace std
{
	template<>
	struct hash<olc::vi2d>
	{
		size_t operator()(const olc::vi2d& obj) const
		{
			return hash<uint64_t>()(uint64_t(obj.y) << 32 | uint64_t(obj.x));
		}
	};
}