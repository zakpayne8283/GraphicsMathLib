#pragma once

#include<cstdio>	// TODO: move this maybe? Check if it's already been added?

/* TODO definitions :
vector2 - 2d vector
	scalar division
vector3 - 3d vector
	scalar division
hvector - 4d vector
*/

/// <summary>
/// Implementation of a 2d vector
/// </summary>
class Vector2
{

public:
	// X & Y position coordinates
	float x, y;

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
	/// <param name="other">Other vector being added</param>
	/// <returns>New Vector2</returns>
	Vector2 operator+(const Vector2& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	/// <summary>
	/// Custom subtraction operator
	/// </summary>
	/// <param name="other">Other vector being subtracted</param>
	/// <returns></returns>
	Vector2 operator-(const Vector2& other)
	{
		return Vector2(x - other.x, y - other.y);
	}
	
	/// <summary>
	/// Custom multiplation operator for scalar multiplication
	/// </summary>
	/// <param name="scalar">Value to scale by</param>
	/// <returns>Vector2 with scale</returns>
	template <typename T>
	Vector2 operator*(const T& scalar)
	{
		return Vector2(x * scalar, y * scalar);
	}

	/// <summary>
	/// Custom division operator for scalar division
	/// </summary>
	/// <param name="scalar">Value to scale by</param>
	/// <returns>Vector2 with scale</returns>
	template <typename T>
	Vector2 operator/(const T& scalar)
	{
		return Vector2(x / scalar, y / scalar);
	}

	/// <summary>
	/// Returns the dot product of two Vector2
	/// </summary>
	/// <param name="a">First vector</param>
	/// <param name="b">Second vector</param>
	/// <returns>Dot product results</returns>
	static float dotProduct(const Vector2& a, const Vector2& b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}

	/// <summary>
	/// Custom comparison operator
	/// </summary>
	/// <param name="other">Other vector being compared</param>
	/// <returns>Vector2s are equal</returns>
	bool operator==(const Vector2& other) const {
		return x == other.x && y == other.y;
	}


	// Custom print - used for testing
	void print()
	{
		printf("Vector2 - (X: %f, Y: %f)", x, y);
	}
};

class Vector3
{

public:

	// X, Y, & Z position coordinates
	float x, y, z;

	/// <summary>
	/// Basic constructor taking x,y,z coordinates
	/// </summary>
	/// <param name="_x">X value</param>
	/// <param name="_y">Y value</param>
	/// <param name="_z">Z value
	Vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	/// <summary>
	/// Custom addition operator
	/// </summary>
	/// <param name="other">Other vector being aded</param>
	/// <returns>New Vector3</returns>
	Vector3 operator+(const Vector3& other)
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}

	/// <summary>
	/// Custom subtraction operator
	/// </summary>
	/// <param name="other">Other vector being subtracted</param>
	/// <returns></returns>
	Vector3 operator-(const Vector3& other)
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}

	/// <summary>
	/// Returns the dot product of two Vector3
	/// </summary>
	/// <param name="a">First vector</param>
	/// <param name="b">Second vector</param>
	/// <returns>Dot product results</returns>
	static float dotProduct(const Vector3& a, const Vector3& b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}

	/// <summary>
	/// Returns the cross product of two Vector3
	/// </summary>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	static Vector3 crossProduct(const Vector3& a, const Vector3& b)
	{
		return Vector3((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x));
	}

	/// <summary>
	/// Custom multiplation operator for scalar multiplication
	/// </summary>
	/// <param name="scalar">Value to scale by</param>
	/// <returns>Vector3 with scale</returns>
	template <typename T>
	Vector3 operator*(const T& scalar)
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	/// <summary>
	/// Custom division operator for scalar division
	/// </summary>
	/// <param name="scalar">Value to scale by</param>
	/// <returns>Vector3 with scale</returns>
	template <typename T>
	Vector3 operator/(const T& scalar)
	{
		return Vector3(x / scalar, y / scalar, z / scalar);
	}

	/// <summary>
	/// Custom comparison operator
	/// </summary>
	/// <param name="other">Other vector being compared</param>
	/// <returns>Vector2s are equal</returns>
	bool operator==(const Vector3& other) const {
		return x == other.x && y == other.y && z == other.z;
	}

	// Custom print - used for testing
	void print()
	{
		printf("Vector3 - (X: %f, Y: %f, Z: %f)", x, y, z);
	}
};