#include "vectors.h"

int main()
{
	// Vector2 tests
	Vector2 a = Vector2(5, 1);
	Vector2 b = Vector2(-4, 8);

	// Add the vector together
	Vector2 c = a + b;
	c.print();

	return 0;
}