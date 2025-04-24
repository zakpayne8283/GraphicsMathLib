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
	};
}
