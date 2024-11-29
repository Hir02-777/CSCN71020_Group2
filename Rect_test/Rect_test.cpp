#include "pch.h"
#include "CppUnitTest.h"
#include <cmath> // For abs()

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(RectangleTests)
    {
    public:

        TEST_METHOD(TestValidRectangle)
        {

            int p1[2] = { 0, 2 };
            int p2[2] = { 2, 2 };
            int p3[2] = { 0, 0 };
            int p4[2] = { 2, 0 };

            int Upp_X_Diff = abs(p1[0] - p2[0]);
            int Upp_Y_Diff = abs(p1[1] - p3[1]);
            int Low_X_Diff = abs(p3[0] - p4[0]);
            int Low_Y_Diff = abs(p2[1] - p4[1]);

            int area = Upp_X_Diff * Upp_Y_Diff;
            int peri = 2 * (Upp_X_Diff + Upp_Y_Diff);

            bool isRectangle = (Upp_X_Diff == Low_X_Diff && Upp_Y_Diff == Low_Y_Diff);


            Assert::IsTrue(isRectangle, L"Expected the coordinates to form a rectangle.");
            Assert::AreEqual(4, area, L"Expected area is 4.");
            Assert::AreEqual(8, peri, L"Expected perimeter is 8.");
        }

        TEST_METHOD(TestValidRectangle1)
        {

            int p1[2] = { 1, 5 };
            int p2[2] = { 4, 5 };
            int p3[2] = { 1, 2 };
            int p4[2] = { 4, 2 };

            int Upp_X_Diff = abs(p1[0] - p2[0]);
            int Upp_Y_Diff = abs(p1[1] - p3[1]);
            int Low_X_Diff = abs(p3[0] - p4[0]);
            int Low_Y_Diff = abs(p2[1] - p4[1]);

            int area = Upp_X_Diff * Upp_Y_Diff;
            int peri = 2 * (Upp_X_Diff + Upp_Y_Diff);

            bool isRectangle = (Upp_X_Diff == Low_X_Diff && Upp_Y_Diff == Low_Y_Diff);


            Assert::IsTrue(isRectangle, L"Expected the coordinates to form a rectangle.");
            Assert::AreEqual(9, area, L"Expected area is 9.");
            Assert::AreEqual(12, peri, L"Expected perimeter is 12.");
        }

        TEST_METHOD(TestValidRectangle2)
        {
            int p1[2] = { -3, 4 };
            int p2[2] = { 2, 4 };
            int p3[2] = { -3, 0 };
            int p4[2] = { 2, 0 };

            int Upp_X_Diff = abs(p1[0] - p2[0]);
            int Upp_Y_Diff = abs(p1[1] - p3[1]);
            int Low_X_Diff = abs(p3[0] - p4[0]);
            int Low_Y_Diff = abs(p2[1] - p4[1]);

            Logger::WriteMessage(("Upp_X_Diff: " + std::to_string(Upp_X_Diff)).c_str());
            Logger::WriteMessage(("Upp_Y_Diff: " + std::to_string(Upp_Y_Diff)).c_str());
            Logger::WriteMessage(("Low_X_Diff: " + std::to_string(Low_X_Diff)).c_str());
            Logger::WriteMessage(("Low_Y_Diff: " + std::to_string(Low_Y_Diff)).c_str());

            int area = Upp_X_Diff * Upp_Y_Diff;
            int peri = 2 * (Upp_X_Diff + Upp_Y_Diff);

            Logger::WriteMessage(("Area: " + std::to_string(area)).c_str());
            Logger::WriteMessage(("Perimeter: " + std::to_string(peri)).c_str());

            bool isRectangle = (Upp_X_Diff == Low_X_Diff && Upp_Y_Diff == Low_Y_Diff);

            Assert::IsTrue(isRectangle, L"Expected the coordinates to form a rectangle.");
            Assert::AreEqual(20, area, L"Expected area is 20.");
            Assert::AreEqual(18, peri, L"Expected perimeter is 18.");
        }

    };
}
