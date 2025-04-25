#include "pch.h"
#include "CppUnitTest.h"

#include "../vectors.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Custom ToString methods for testing
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <>
			inline std::wstring ToString<Vector2>(const Vector2& v) {
				return L"Vector2(" + std::to_wstring(v.x) + L", " + std::to_wstring(v.y) + L")";
			}

			template<>
			inline std::wstring ToString<Vector3>(const Vector3& v) {
				return L"Vector3(" + std::to_wstring(v.x) + L", " + std::to_wstring(v.y) + L", " + std::to_wstring(v.z) + L")";
			}
		}
	}
}


namespace UnitTests
{

	TEST_CLASS(UnitTests)
	{

		const float FLOAT_TOLERANCE = 0.00001f;

	public:
		
		TEST_METHOD(Vector2Addition)
		{
			// Basic addition
			Vector2 a = Vector2(1, 1);
			Vector2 b = Vector2(1, 1);

			Assert::AreEqual(Vector2(2, 2), a + b);

			// Addition with negative vectors
			a = Vector2(-5,  3);
			b = Vector2( 6, -2);

			Assert::AreEqual(Vector2(1, 1), a + b);
		}

		TEST_METHOD(Vector2Subtraction)
		{
			// Basic subtraction
			Vector2 a = Vector2(1, 1);
			Vector2 b = Vector2(1, 1);

			Assert::AreEqual(Vector2(0, 0), a - b);

			// subtraction with negative vectors
			a = Vector2(-5, 3);
			b = Vector2(6, -2);

			Assert::AreEqual(Vector2(-11, 5), a - b);
		}

		TEST_METHOD(Vector2ScalarMultiplication)
		{
			Vector2 a = Vector2(1, 1);

			// Basic scalar multiplication
			Assert::AreEqual(Vector2(3, 3), a * 3);

			// Scalar multiplication with floats and negatives
			Assert::AreEqual(Vector2(-2.4f, -2.4f), a * -2.4f);
		}

		TEST_METHOD(Vector2DotProduct)
		{
			// Dot product with positive ints
			Vector2 a = Vector2(1, 1);
			Vector2 b = Vector2(1, 1);

			Assert::AreEqual(Vector2::dotProduct(a, b), 2.0f);
		
			// Dot product with negatives and floats
			a = Vector2(0.6f, -8.4f);
			b = Vector2(1.7f, 2.2f);
			Assert::AreEqual(Vector2::dotProduct(a, b), -17.46f);
		}

		TEST_METHOD(Vector3Addition)
		{
			// Basic addition
			Vector3 a = Vector3(1, 1, 1);
			Vector3 b = Vector3(1, 1, 1);

			Assert::AreEqual(Vector3(2, 2, 2), a + b);

			// Addition with negative vectors
			a = Vector3(-5,  3, 0);
			b = Vector3( 6, -2, 4);

			Assert::AreEqual(Vector3(1, 1, 4), a + b);
		}

		TEST_METHOD(Vector3Subtraction)
		{
			// Basic subtraction
			Vector3 a = Vector3(1, 1, 1);
			Vector3 b = Vector3(1, 1, 1);

			Assert::AreEqual(Vector3(0, 0, 0), a - b);

			// subtraction with negative vectors
			a = Vector3(-5, 3, 0);
			b = Vector3(6, -2, 4);

			Assert::AreEqual(Vector3(-11, 5, -4), a - b);
		}

		TEST_METHOD(Vector3ScalarMultiplication)
		{
			Vector3 a = Vector3(1, 1, 1);

			// Basic scalar multiplication
			Assert::AreEqual(Vector3(3, 3, 3), a * 3);

			// Scalar multiplication with floats and negatives
			Assert::AreEqual(Vector3(-2.4f, -2.4f, -2.4f), a * -2.4f);
		}

		TEST_METHOD(Vector3DotProduct)
		{
			// Dot product with positive ints
			Vector3 a = Vector3(1, 1, 1);
			Vector3 b = Vector3(1, 1, 1);

			Assert::AreEqual(Vector3::dotProduct(a, b), 3.0f);

			// Dot product with negatives and floats
			a = Vector3(0.6f, -8.4f,  2.3f);
			b = Vector3(1.7f,  2.2f, -2.3f);
			Assert::AreEqual(Vector3::dotProduct(a, b), -22.75f);
		}
	
		TEST_METHOD(Vector3CrossProduct)
		{
			// Cross product with positive ints
			Vector3 a = Vector3(1, 1, 1);
			Vector3 b = Vector3(2, 2, 2);

			Assert::AreEqual(Vector3(0, 0, 0), Vector3::crossProduct(a, b));

			// Cross product with negatives and floats
			a = Vector3(0.6f, -8.4f, 2.3f);
			b = Vector3(1.7f, 2.2f, -2.3f);

			// Because of floating point percision, assess using a floating point percision const
			// zeroVector - all values should be less than the float percision const
			Vector3 zeroVector   = Vector3(14.26f, 5.29f, 15.6f) - Vector3::crossProduct(a, b);

			Assert::IsTrue(zeroVector.x < FLOAT_TOLERANCE && zeroVector.y < FLOAT_TOLERANCE && zeroVector.z < FLOAT_TOLERANCE);
		}
	
	};
}
