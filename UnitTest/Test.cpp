#include "pch.h"
#include "CppUnitTest.h"

#include "../Domain/Circle.h"
#include "../Domain/Circle.cpp"

#include <string>
#include <sstream>
#include <iomanip>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(CircleTests)
	{
	public:

		TEST_METHOD(Constructor_NegativeRadius_ExpectedException)
		{
			// Assert 
			Assert::ExpectException<std::invalid_argument>([]() { circle::Circle obj(-2.8); });
		}

		TEST_METHOD(GetRadius_ValidData_Success)
		{
			// Arrange
			const double R = 2.8;
			circle::Circle obj{ R };
			const double expected = R;
			const double epsilon = 0.001;
			// Act
			const double actual = obj.GetRadius();
			// Assert 
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}

		TEST_METHOD(GetDiameter_ValidData_Success)
		{
			// Arrange
			const double R = 2.8;
			circle::Circle obj{ R };
			const double expected = R * 2;
			const double epsilon = 0.001;
			// Act
			const double actual = obj.GetDiameter();
			// Assert 
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}

		TEST_METHOD(GetLength_ValidData_Success)
		{
			// Arrange
			const double R = 2.8;
			circle::Circle obj{ R };
			const double expected = 2 * 3.14 * R;
			const double epsilon = 0.01;
			// Act
			const double actual = obj.GetLength();
			// Assert 
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}

		TEST_METHOD(GetArea_ValidData_Success)
		{
			// Arrange
			const double R = 2.8;
			circle::Circle obj{ R };
			const double expected = 3.14 * R * R;
			const double epsilon = 0.1;
			// Act
			const double actual = obj.GetArea();
			// Assert 
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}
	};
}