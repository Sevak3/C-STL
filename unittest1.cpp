#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorUnitTest
{		
	TEST_CLASS(VectorUnitTest)
	{
	private:
		static std::string toString(Vector& vec)
		{
			std::string result;

			for (int i = 0; i < vec.size(); ++i)
			{
				const int value = vec[i];

				result += std::to_string(value);
				result += ' ';
			}

			return result;
		}

	public:
		
		TEST_METHOD(CTOR)
		{
			Vector vec;
		}

		TEST_METHOD(CCTOR)
		{
			Vector vec1;
			for (int i = 0; i < 5; ++i)
			{
				vec1.pushBackInMemory(i);
			}
			Vector vec2(vec1);

			const int actual = vec2.size();
			const int expected = 5;
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(beginTest)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			const int expected = 10;
			const int actual = *(vec.begin());
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(endTest)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			vec.pushBackInMemory(30);
			const int expected = 30;
			const int actual = *(vec.end() - 1);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isEmptyTest)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			const bool expected = false;
			const bool actual = vec.isEmpty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isNotEmptyTest)
		{
			Vector vec;
			const bool expected = true;
			const bool actual = vec.isEmpty();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isFullTest)
		{
			Vector vec;
			for (int i = 0; i < 10; ++i)
			{
				vec.pushBackInMemory(i);
			}
			const bool expected = true;
			const bool actual = vec.isFull();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(isNotFullTest)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			const bool expected = false;
			const bool actual = vec.isFull();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushBackTestBySize)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			const int expected = 2;
			const int actual = vec.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushBackTestByElement)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			const int expected = 10;
			const int actual = vec.getElement(0);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(popBackTestBySize)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			vec.popBackInMemory();
			const int expected = 1;
			const int actual = vec.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(popBackTestByElement)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			vec.popBackInMemory();
			const int expected = 10;
			const int actual = vec.getElement(0);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(sizeTest)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			const int expected = 2;
			const int actual = vec.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(getCapacityTest)
		{
			Vector vec;
			const int expected = 10;
			const int actual = vec.getCapacity();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(getElementTest)
		{
			Vector vec;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			const int expected = 20;
			const int actual = vec.getElement(1);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(insertBeginTest)
		{
			Vector vec;
			Vector::Iterator itr = vec.begin();
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			vec.pushBackInMemory(30);
			vec.insert(itr, 40);
			const std::string expected = "40 10 20 30 ";
			const std::string actual = toString(vec);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(insertEndTest)
		{
			Vector vec;
			Vector::Iterator itr = vec.begin() + 2;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			vec.pushBackInMemory(30);
			vec.insert(itr, 40);
			const std::string expected = "10 20 40 30 ";
			const std::string actual = toString(vec);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(eraseBeginTest)
		{
			Vector vec;
			Vector::Iterator itr = vec.begin();
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			vec.pushBackInMemory(30);
			vec.erase(itr);
			const std::string expected = "20 30 ";
			const std::string actual = toString(vec);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(eraseEndTest)
		{
			Vector vec;
			Vector::Iterator itr = vec.begin() + 2;
			vec.pushBackInMemory(10);
			vec.pushBackInMemory(20);
			vec.pushBackInMemory(30);
			vec.erase(itr);
			const std::string expected = "10 20 ";
			const std::string actual = toString(vec);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(appendElementSizeTest)
		{
			Vector vec;
			for (int i = 1; i <= vec.getCapacity(); ++i)
			{
				vec.pushBackInMemory(i);
			}
			vec.appendElement(10);
			const int expected = 20;
			const int actual = vec.getCapacity();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(appendElementPushBackTest)
		{
			Vector vec;
			for (int i = 1; i <= 5; ++i)
			{
				vec.pushBackInMemory(i);
			}
			vec.appendElement(10);
			const std::string expected = "1 2 3 4 5 10 ";
			const std::string actual = toString(vec);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(reducinglementSizeTest)
		{
			Vector vec;
			for (int i = 0; i < 4; ++i)
			{
				vec.pushBackInMemory(i);
			}
			vec.reducingElment(1);
			const int expected = 5;
			const int actual = vec.getCapacity();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(reducinglementPopBackTest)
		{
			Vector vec;
			for (int i = 0; i < 5; ++i)
			{
				vec.pushBackInMemory(i);
			}
			vec.reducingElment(1);
			const std::string expected = "0 1 2 3 ";
			const std::string actual = toString(vec);
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}
	};
}