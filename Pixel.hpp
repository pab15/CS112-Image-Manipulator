#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <istream>
#include <exception>
using namespace std;

class Pixel
{
private:
	int _red = -1;
	int _green = -1;
	int _blue = -1;

public:
	void setRed(int r)
	{
		_red = r;
	}

	int getRed()
	{
		return _red;
	}

	void setGreen(int g)
	{
		_green = g;
	}

	int getGreen()
	{
		return _green;
	}

	void setBlue(int b)
	{
		_blue = b;
	}

	int getBlue()
	{
		return _blue;
	}

	friend istream& operator>>(istream& stream, Pixel& pixel);
	friend ostream& operator<<(ostream& stream, Pixel& pixel);
};

istream& operator>>(istream& stream, Pixel& pixel)
{
	stream >> pixel._red >> pixel._green >> pixel._blue;
	return stream;
}

ostream& operator<<(ostream& stream, Pixel& pixel)
{
	stream << pixel._red << " " << pixel._green << " " << pixel._blue;
	return stream;
}

#endif // !PIXEL_H
