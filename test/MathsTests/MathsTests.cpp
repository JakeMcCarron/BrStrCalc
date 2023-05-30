#include "CppUnitTest.h"
import BasicMaths;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathsTests
{
	TEST_CLASS(AdditionTests)
	{
	public:		
		TEST_METHOD(AdditionTestBothPos)
		{
			const long x = 100, y = 500;
			const long z = 600;
			Assert::IsTrue(Addition(x, y) == z);
		}
		TEST_METHOD(AdditionTestOnePos)
		{
			const long x = 100, y = -500;
			const long long z = -400;
			Assert::IsTrue(Addition(x, y) == z);
		}
		TEST_METHOD(AdditionTestBothNeg)
		{
			const long x = -100, y = -500;
			const long long z = -600;
			Assert::IsTrue(Addition(x, y) == z);
		}
	};
	TEST_CLASS(SubtractionTests)
	{
	public:
		TEST_METHOD(SubtractionTestBothPos)
		{
			const long x = 100, y = 500;
			const long z = -400;
			Assert::IsTrue(Subtraction(x, y) == z);
		}
		TEST_METHOD(SubtractionTestOnePos)
		{
			const long x = 100, y = -500;
			const long long z = 600;
			Assert::IsTrue(Subtraction(x, y) == z);
		}
		TEST_METHOD(ASubtractionTestBothNeg)
		{
			const long x = -100, y = -500;
			const long long z = 400;
			Assert::IsTrue(Subtraction(x, y) == z);
		}
	};
	TEST_CLASS(MultiplicationTests)
	{
	public:
		TEST_METHOD(MultiplicationTestBothPos)
		{
			const long x = 100, y = 500;
			const long z = 50000;
			Assert::IsTrue(Multiplication(x, y) == z);
		}
		TEST_METHOD(MultiplicationTestOnePos)
		{
			const long x = 100, y = -500;
			const long long z = -50000;
			Assert::IsTrue(Multiplication(x, y) == z);
		}
		TEST_METHOD(MultiplicationTestBothNeg)
		{
			const long x = -100, y = -500;
			const long long z = 50000;
			Assert::IsTrue(Multiplication(x, y) == z);
		}
	};
	TEST_CLASS(DivisionTests)
	{
	public:
		TEST_METHOD(DivisionTestBothPos)
		{
			const double x = 100, y = 20;
			const long double z = 5;
			Assert::IsTrue(Division(x, y) == z);
		}
		TEST_METHOD(DivisionTestOnePos)
		{
			const double x = 100, y = -500;
			const long double z = -0.2;
			Assert::IsTrue(Division(x, y) == z);
		}
		TEST_METHOD(DivisionTestBothNeg)
		{
			const double x = -1000, y = -500;
			const long double z = 2;
			Assert::IsTrue(Division(x, y) == z);
		}
	};
	TEST_CLASS(FactorialTests)
	{
		TEST_METHOD(FactorialTest6)
		{
			const long x = 6;
			const long long z = 720;
			Assert::IsTrue(Factorial(x) == z);
		}
		TEST_METHOD(FactorialTest10)
		{
			const long x = 10;
			const long long z = 3628800;
			Assert::IsTrue(Factorial(x) == z);
		}
		TEST_METHOD(FactorialTest18)
		{
			const long x = 18;
			const long long z = 6402373705728000;
			Assert::IsTrue(Factorial(x) == z);
		}
	};
	TEST_CLASS(PowerLonglongTests)
	{
		TEST_METHOD(PowerLongTest10_5)
		{
			const long x = 10 , y = 5;
			const long long z = 100000;
			Assert::IsTrue(powll(x, y) == z);
		}
		TEST_METHOD(PowerLongTest5_8)
		{
			const long x = 5, y = 8;
			const long long z = 390625;
			Assert::IsTrue(powll(x, y) == z);
		}
		TEST_METHOD(PowerLongTestM10_5)
		{
			const long x = -10, y = 5;
			const long long z = -100000;
			Assert::IsTrue(powll(x, y) == z);
		}
	};
}
