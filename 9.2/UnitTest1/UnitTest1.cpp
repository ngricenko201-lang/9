#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include "../9.2/macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92
{
	TEST_CLASS(UnitTest92)
	{
	public:

		TEST_METHOD(TestMin)
		{
			Assert::AreEqual(2, MIN(2, 7));
			Assert::AreEqual(-5, MIN(-3, -5));
		}

		TEST_METHOD(TestMax)
		{
			Assert::AreEqual(14, MAX(9, 14));
			Assert::AreEqual(-1, MAX(-1, -4));
		}

		TEST_METHOD(TestAbs)
		{
			Assert::AreEqual(8, ABS(-8));
			Assert::AreEqual(5, ABS(5));
			Assert::AreEqual(0, ABS(0));
		}

		TEST_METHOD(TestSqr)
		{
			Assert::AreEqual(25, SQR(5));
			Assert::AreEqual(9, SQR(-3));
			Assert::AreEqual(9, SQR(2 + 1));   // перевірка дужок у макросі
		}

		// Гілка 5 < z < 10: w = min(x, z) * max(x + z, x * z)
		TEST_METHOD(TestBranch1)
		{
			int x = 2, z = 7;
			Assert::AreEqual(28, MIN(x, z) * MAX(x + z, x * z));
		}

		// Гілка z <= 5, z >= 10: w = max^2(|x - z|, z)
		TEST_METHOD(TestBranch2)
		{
			int x = 2, z = 3;
			Assert::AreEqual(9, SQR(MAX(ABS(x - z), z)));

			z = 10;
			Assert::AreEqual(100, SQR(MAX(ABS(x - z), z)));
		}
	};
}