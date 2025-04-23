#pragma once

#include<cstdio>	// TODO: move this maybe? Check if it's already been added?

/* TODO definitions :
vector2 - 2d vector
	subtration
	dot product
	cross product
	scalar multiplication
	scalar division
vector3 - 3d vector
	addition
	subtraction
	dot product
	cross product
	scalar multiplication
	scalar division
hvector - 4d vector
*/

/// <summary>
/// Implementation of a 2d vector
/// </summary>
class Vector2
{
	// X & Y coordinates
	float x, y;

public:
	/// <summary>
	/// Basic constructor taking x,y coordinates
	/// </summary>
	/// <param name="_x">X value</param>
	/// <param name="_y">Y value</param>
	Vector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	/// <summary>
	/// Custom addition operator
	/// </summary>
	/// <param name="other">Other vector being aded</param>
	/// <returns>New vector</returns>
	Vector2 operator+(const Vector2& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	void print()
	{
		printf("Vector2 - (X: %f, Y: %f)", x, y);
	}
};

class Vector3
{

};