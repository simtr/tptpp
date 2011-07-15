#ifndef __SYS_POINT_H__
#define __SYS_POINT_H__

namespace sys
{

struct Point
{
public:
	int X;
	int Y;

	Point(int x, int y) :
		X(x),
		Y(y)
	{
	}

	Point operator + (Point v)
	{
		return Point(X + v.X, Y + v.Y);
	}

	Point operator - (Point v)
	{
		return Point(X - v.X, Y - v.Y);
	}

	Point operator * (Point v)
	{
		return Point(X * v.X, Y * v.Y);
	}

	Point operator / (Point v)
	{
		return Point(X / v.X, Y / v.Y);
	}

	bool operator == (Point v)
	{
		return X == v.X && Y == v.Y;
	}

	bool operator != (Point v)
	{
		return X != v.X || Y != v.Y;
	}

};

}

#endif // __SYS_POINT_H__