#include "pch.h"
#include "CppUnitTest.h"


extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" double calculateangle(int a, int b, int c);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace triangletest
{
	TEST_CLASS(triangletest)
	{
	public:
		
		TEST_METHOD(Test1)
		{
			const char* answer = "Not a triangle, the length cannot be negative";
			const char* actual = analyzeTriangle(-1, 2, 3);
			Assert::AreEqual(answer, actual);
		}
		TEST_METHOD(Test2)
		{
			const char* answer = "Cannot form a triangle, the sum of two sides must be bigger than the third for all three combinations.";
			const char* actual = analyzeTriangle(2, 2, 5);
			Assert::AreEqual(answer, actual);
		}
		TEST_METHOD(Test3)
		{
			const char* answer = "Equilateral triangle";
			const char* actual = analyzeTriangle(5, 5, 5);
			Assert::AreEqual(answer, actual);
		}
		TEST_METHOD(Test4)
		{
			const char* answer = "Isosceles triangle";
			const char* actual = analyzeTriangle(10, 10, 15);
			Assert::AreEqual(answer, actual);
		}
		TEST_METHOD(Test5)
		{
			const char* answer = "Scalene triangle";
			const char* actual = analyzeTriangle(4, 5, 3);
			Assert::AreEqual(answer, actual);
		}


	};

	TEST_CLASS(angletest) {
		TEST_METHOD(test1) {
			double angle = 60;
			double answer = calculateangle(3, 3, 3);
			Assert::IsTrue(angle - 1 <= answer && answer <= angle + 1);
		}
		TEST_METHOD(test2) {
			double angle = 90.0;
			double answer = calculateangle(5,3,4);
			Assert::IsTrue(angle - 1 <= answer && answer <= angle + 1);
		}
		TEST_METHOD(test3) {
			double angle = 60;
			double answer = calculateangle(3, 3, 3);
			Assert::IsTrue(angle - 1 <= answer && answer <= angle + 1);
		}
		TEST_METHOD(test4) {
			double angle = 87.13;
			double answer = calculateangle(9, 6, 7);
			Assert::IsTrue(angle-1 <= answer && answer <= angle + 1);
		}

	};
	TEST_CLASS(getangletest) {
		TEST_METHOD(test1) {

		}
	};
}
