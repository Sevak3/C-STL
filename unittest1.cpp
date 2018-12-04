#include "stdafx.h"
#include "CppUnitTest.h"
#include "List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		std::string toString(List& list)
		{
			std::string result("");
			for(auto it = list.begin(); it != list.end(); ++it)
			{
				result += std::to_string(*it);
				result += std::string(" ");
			}
			return result;
		}
		
		TEST_METHOD(CTOR)
		{
			List list;
			Assert::IsTrue(true, L"", LINE_INFO());
		}

		TEST_METHOD(size)
		{
			List list;
			const auto expected = 0;
			const auto actual = list.size();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(pushBack)
		{
			List list;
			list.pushBack(5);
			const int expectedSize = 1;
			const int actual = list.size();
			Assert::AreEqual(expectedSize, actual, L"", LINE_INFO());
		}

		TEST_METHOD(begin_read)
		{
			List list;
			list.pushBack(5);
			const int expected = 5;
			const int actual = *(list.begin());
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(begin_write)
		{
			List list;
			list.pushBack(5);
			*(list.begin()) = 8;

			const int expected = 8;
			const int actual = *(list.begin());
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(multiple_pushBack)
		{
			List list;
			list.pushBack(5);
			list.pushBack(6);
			list.pushBack(7);

			const int expected = 5;
			const int actual = *(list.begin());
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
			Assert::IsTrue(list.size() == 3, L"", LINE_INFO());
		}

		TEST_METHOD(begin_end)
		{
			List list;
			const auto expected = list.begin();
			const auto actual = list.end();

			Assert::IsTrue(list.begin() == list.end(), L"", LINE_INFO());
		}

		TEST_METHOD(multiple_popBack)
		{
			List list;
			list.pushBack(5);
			list.pushBack(6);
			list.pushBack(7);
			list.popBack();
			const int expected = 6;
			const int actual = list.back();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
			Assert::IsTrue(list.size() == 2, L"", LINE_INFO());
		}

		TEST_METHOD(pushFront)
		{
			List list;
			list.pushFront(5);
			list.pushFront(6);
			list.pushFront(7);

			const int expected = 7;
			const int actual = list.front();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
			Assert::IsTrue(list.size() == 3, L"", LINE_INFO());
		}

		TEST_METHOD(popFront)
		{
			List list;
			list.pushFront(5);
			list.pushFront(6);
			list.pushFront(7);
			list.popFront();

			const int expected = 6;
			const int actual = list.front();
			Assert::AreEqual(expected, actual, L"", LINE_INFO());
			Assert::IsTrue(list.size() == 2, L"", LINE_INFO());
		}

		TEST_METHOD(isEmpty)
		{
			List list;

			Assert::IsTrue(list.isEmpty(), L"", LINE_INFO());
			Assert::IsTrue(list.size() == 0, L"", LINE_INFO());
		}
	};
}