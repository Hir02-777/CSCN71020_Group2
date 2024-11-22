#include "pch.h"
#include "CppUnitTest.h"


extern "C" char* analyzeTriangle(int side1, int side2, int side3);

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
	};
}
