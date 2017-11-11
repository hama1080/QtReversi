#include "stdafx.h"
#include "CppUnitTest.h"
#include "vector2d.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Vector2dEqualTest)
		{
			Vector2d vec0(1, 1);
			Vector2d vec1(1, 1);
			Assert::AreEqual(vec0 == vec1, true, L"message", LINE_INFO());
		}

		TEST_METHOD(Vector2dAddTest)
		{
			Vector2d vec0(1, 1);
			Vector2d vec1(1, 1);
			Vector2d ans(2, 2);
			Vector2d sum = vec0 + vec1;
			Assert::AreEqual(sum == ans, true, L"message", LINE_INFO());
		}

		TEST_METHOD(Vector2dSubTest)
		{
			Vector2d vec0(1, 1);
			Vector2d vec1(1, 1);
			Vector2d ans(0, 0);
			Vector2d sum = vec0 - vec1;
			Assert::AreEqual(sum == ans, true, L"message", LINE_INFO());
		}

	};
}