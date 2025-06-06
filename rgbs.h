#pragma once

#include<cstdint>	// TODO: move this maybe? Check if it's already been added?

#define colorint uint8_t

/*
should implement the following:

rgb multiplication
scalar multiplication
scalar division
*/

class RGB
{

public:

	// Colors as unsigned 8bit integers 
	colorint r, g, b;

	static const RGB MAX_RGB;
	static const RGB MIN_RGB;

	/// <summary>
	/// Basic constructor. Accepts RGB as unsigned 8bit ints.
	/// </summary>
	/// <param name="_r">Red</param>
	/// <param name="_g">Green</param>
	/// <param name="_b">Blue</param>
	RGB(colorint _r, colorint _g, colorint _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}

	/// <summary>
	/// Overloaded + for adding to RGBs together
	/// </summary>
	/// <param name="other">Other RGB being added</param>
	/// <returns>Added RGB values</returns>
	RGB operator+(const RGB& other)
	{
		return RGB(
			(r > 255 - other.r) ? 255 : r + other.r,
			(g > 255 - other.g) ? 255 : g + other.g,
			(b > 255 - other.b) ? 255 : b + other.b
		);
	}

	/// <summary>
	/// Overloaded - for subtracting RGBs
	/// </summary>
	/// <param name="other">Other RGB</param>
	/// <returns>RGB minus other</returns>
	RGB operator-(const RGB& other)
	{
		return RGB(
			(r < 0 + other.r) ? 0 : r - other.r,
			(g < 0 + other.g) ? 0 : g - other.g,
			(b < 0 + other.b) ? 0 : b - other.b
		);
	}

	/// <summary>
	/// Overloaded * for multiplying RGBs
	/// </summary>
	/// <param name="other">Other RGB</param>
	/// <returns>RGB multiplied by other</returns>
	RGB operator*(const RGB& other)
	{
		return RGB(
			(r > 255 / other.r) ? 255 : r * other.r,
			(g > 255 / other.g) ? 255 : g * other.g,
			(b > 255 / other.b) ? 255 : b * other.b
		);
	}

	/// <summary>
	/// Overload * operator for scalar multiplication
	/// </summary>
	/// <typeparam name="T">Type of multiplication</typeparam>
	/// <param name="scalar">Real number to scale by</param>
	/// <returns>Scaled RGB value</returns>
	template<typename T>
	RGB operator*(const T& scalar)
	{
		return RGB(
			(r > 255 / scalar) ? 255 : r * scalar,
			(g > 255 / scalar) ? 255 : g * scalar,
			(b > 255 / scalar) ? 255 : b * scalar
		);
	}

	/// <summary>
	/// Custom comparison operator
	/// </summary>
	/// <param name="other">Other RGB being compared</param>
	/// <returns>RGBs are equal</returns>
	bool operator==(const RGB& other) const
	{
		return r == other.r && g == other.g && b == other.b;
	}
};

// Define max and min constants
const RGB RGB::MAX_RGB = RGB(255, 255, 255);
const RGB RGB::MIN_RGB = RGB(0, 0, 0);