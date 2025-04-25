#pragma once

#include<cstdint>	// TODO: move this maybe? Check if it's already been added?

#define colorint uint8_t

/*
should implement the following:

rgb addition
rgb subtraction
rgb multiplication
scalar multiplication
scalar division
*/

class RGB
{

public:

	// Colors as unsigned 8bit integers 
	colorint r, g, b;

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


};