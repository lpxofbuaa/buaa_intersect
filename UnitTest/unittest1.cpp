#include "stdafx.h"
#include "CppUnitTest.h"
#include "GeometryStatistic.h"
#include "Point.h"
#include "RationalNumber.h"
#include "GeometryShape.h"

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
				RationalNumber *a = new RationalNumber(3, 4);
				RationalNumber *b = new RationalNumber(6, 800);
				test->insert(new RationalPoint(*a, *b));
			}
			Assert::AreEqual((int) test->size(), 1);
		}


		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			GeometryStatistic *test = new GeometryStatistic();
			RationalNumber a(4, 3);
			RationalNumber b(1, 2);
			RationalNumber c(3, 1);
			RationalNumber d(-2, 1);
			RationalPoint p1(a, a);
			RationalPoint p2(b, b);
			RationalPoint p3(c, d);
			Line l1(0, 0, 1, 1);
			Line l2(1, 0, 0, 1);
			Line l3(1, 2, 2, 0);
			test->feed(l1);
			test->feed(l2);
			test->feed(l3);
			Assert::AreEqual(test->getPointCount(), 3);
			Assert::AreEqual(test->containsPoint(&p1), true);
			Assert::AreEqual(test->containsPoint(&p2), true);
			Assert::AreEqual(test->containsPoint(&p3), true);
		}

	};
}