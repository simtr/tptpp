#ifndef __SYS_COLOR_H__
#define __SYS_COLOR_H__

namespace ui
{

struct Color3
{
public:
	float R;
	float G;
	float B;

	Color3() {}

	Color3(float r, float g, float b)
		:
		R(r),
		G(g),
		B(b)
	{ }

	Color3(unsigned char r, unsigned char g, unsigned char b)
		:
		R(static_cast<float>(r) / 255),
		G(static_cast<float>(g) / 255),
		B(static_cast<float>(b) / 255)
	{ }

	Color3 GetClamp()
	{
		return Color3(
			(R > 1.0f ? 1.0f : R < 0.0f ? 0.0f : R),
			(G > 1.0f ? 1.0f : G < 0.0f ? 0.0f : G),
			(B > 1.0f ? 1.0f : B < 0.0f ? 0.0f : B)
		);
	}

	Color3 Clamp()
	{
		R = (R > 1.0f ? 1.0f : R < 0.0f ? 0.0f : R);
		G = (G > 1.0f ? 1.0f : G < 0.0f ? 0.0f : G);
		B = (B > 1.0f ? 1.0f : B < 0.0f ? 0.0f : B);
	}

	bool operator == (Color3 v)
	{
		return R == v.R && G == v.G && B == v.B;
	}
	bool operator != (Color3 v)
	{
		return R != v.R || G != v.G || B != v.B;
	}

	Color3 operator + (Color3 v)
	{
		return Color3(R + v.R, G + v.G, B + v.B);
	}
	Color3 operator - (Color3 v)
	{
		return Color3(R - v.R, G - v.G, B - v.B);
	}
	Color3 operator * (Color3 v)
	{
		return Color3(R * v.R, G * v.G, B * v.B);
	}
	Color3 operator / (Color3 v)
	{
		return Color3(R / v.R, G / v.G, B / v.B);
	}

};

struct Color4
{
public:
	float R;
	float G;
	float B;
	float A;

	Color4() {}

	Color4(float r, float g, float b)
		:
		R(r),
		G(g),
		B(b),
		A(1.0f)
	{ }

	Color4(float r, float g, float b, float a)
		:
		R(r),
		G(g),
		B(b),
		A(a)
	{ }

	Color4(unsigned char r, unsigned char g, unsigned char b)
		:
		R(static_cast<float>(r) / 255),
		G(static_cast<float>(g) / 255),
		B(static_cast<float>(b) / 255),
		A(1.0f)
	{ }

	Color4(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		:
		R(static_cast<float>(r) / 255),
		G(static_cast<float>(g) / 255),
		B(static_cast<float>(b) / 255),
		A(static_cast<float>(a) / 255)
	{ }

	Color4 GetClamp()
	{
		return Color4(
			(R > 1.0f ? 1.0f : R < 0.0f ? 0.0f : R),
			(G > 1.0f ? 1.0f : G < 0.0f ? 0.0f : G),
			(B > 1.0f ? 1.0f : B < 0.0f ? 0.0f : B),
			(A > 1.0f ? 1.0f : A < 0.0f ? 0.0f : A)
		);
	}

	Color4 Clamp()
	{
		R = (R > 1.0f ? 1.0f : R < 0.0f ? 0.0f : R);
		G = (G > 1.0f ? 1.0f : G < 0.0f ? 0.0f : G);
		B = (B > 1.0f ? 1.0f : B < 0.0f ? 0.0f : B);
		A = (A > 1.0f ? 1.0f : A < 0.0f ? 0.0f : A);
	}

	bool operator == (Color4 v)
	{
		return R == v.R && G == v.G && B == v.B && A == v.A;
	}
	bool operator != (Color4 v)
	{
		return R != v.R || G != v.G || B != v.B || A != v.A;
	}

	Color4 operator + (Color4 v)
	{
		return Color4(R + v.R, G + v.G, B + v.B, A + v.A);
	}
	Color4 operator - (Color4 v)
	{
		return Color4(R - v.R, G - v.G, B - v.B, A - v.A);
	}
	Color4 operator * (Color4 v)
	{
		return Color4(R * v.R, G * v.G, B * v.B, A * v.A);
	}
	Color4 operator / (Color4 v)
	{
		return Color4(R / v.R, G / v.G, B / v.B, A / v.A);
	}

};

}

#endif // __SYS_COLOR_H__