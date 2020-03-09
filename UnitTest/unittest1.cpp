#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			unordered_set<RationalPoint*, my_hash, my_equal> *test = new unordered_set<RationalPoint*, my_hash, my_equal>();

			for (int i = 0; i < 1000; ++i) {
				RationalNumber a = RationalNumber(3, 4);
				RationalNumber b = RationalNumber(6, 800);
				test->insert(new RationalPoint(a, b));
			}
			Assert::AreEqual((int) test->size(), 1);
		}

	};
}