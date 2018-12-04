#include "stdafx.h"
#include "CppUnitTest.h"
#include "BinarTree.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeUnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(insert)
		{
			BinarTree<int> bt;

			bt.insert(5);
			bt.insert(3);
			bt.insert(1);
			bt.insert(8);

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.print();

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "1 3 5 8 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(min)
		{
			BinarTree<std::string> bt{ "A", "B", "C", "D" };

			const std::string actual = bt.min()->m_value;
			const std::string expected = "A";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(max)
		{
			BinarTree<int> bt;

			bt.insert(5);
			bt.insert(3);
			bt.insert(1);
			bt.insert(8);

			const auto actual = bt.max()->m_value;
			const auto expected = 8;

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(successor)
		{
			BinarTree<std::string> bt{ "A", "B", "C", "D" };

			auto getRoot = bt.getRoot();

			const std::string actual = bt.successor(getRoot, "A")->m_value;
			const std::string expected("B");

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(predecessor)
		{
			BinarTree<int> bt;

			bt.insert(5);
			bt.insert(3);
			bt.insert(1);
			bt.insert(8);

			auto getRoot = bt.getRoot();

			const auto actual = bt.predecessor(getRoot, 5)->m_value;
			const auto expected = 3;

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(getRoot)
		{
			BinarTree<int> bt;

			bt.insert(5);
			bt.insert(3);
			bt.insert(1);
			bt.insert(8);

			const auto actual = bt.getRoot()->m_value;
			const auto expected = 5;

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(initializerList)
		{
			BinarTree<int> bt{ 5, 3, 1, 8 };

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.print();

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "1 3 5 8 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(findTrue)
		{
			BinarTree<int> bt;

			bt.insert(5);
			bt.insert(3);
			bt.insert(1);
			bt.insert(8);

			const auto actual = bt.find(3)->m_value;
			const auto expected = 3;

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(maxDepth)
		{
			BinarTree<int> bt;

			bt.insert(9);
			bt.insert(11);
			bt.insert(1);
			bt.insert(5);
			bt.insert(3);
			bt.insert(17);
			bt.insert(4);
			bt.insert(13);
			bt.insert(15);
			bt.insert(14);

			const auto actual = bt.maxDepth();
			const auto expected = 5;

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(minDepth)
		{
			BinarTree<int> bt;

			bt.insert(9);
			bt.insert(11);
			bt.insert(1);
			bt.insert(5);
			bt.insert(3);
			bt.insert(17);
			//bt.insert(4);
			bt.insert(13);
			bt.insert(15);
			bt.insert(14);

			const auto actual = bt.minDepth();
			const auto expected = 3;

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(inorder)
		{
			BinarTree<int> bt{ 9, 11, 1, 5, 3, 17, 4, 13, 15, 14 };

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.inorder(bt.getRoot());

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "1 3 4 5 9 11 13 14 15 17 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(preorder)
		{
			BinarTree<int> bt{ 9, 11, 1, 5, 3, 17, 4, 13, 15, 14 };

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.preorder(bt.getRoot());

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "9 1 5 3 4 11 17 13 15 14 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(postorder)
		{
			BinarTree<int> bt{ 9, 11, 1, 5, 3, 17, 4, 13, 15, 14 };

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.postorder(bt.getRoot());

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "4 3 5 1 14 15 13 17 11 9 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(bfsTravers)
		{
			BinarTree<int> bt{ 21, 6, 8, 15, 32, 41, -3, 65 };

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.bfsTravers();

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "21 6 32 -3 8 41 15 65 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(dfsTravers)
		{
			BinarTree<int> bt{ 21, 6, 8, 15, 32, 41, -3, 65 };

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.dfsTravers();

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "21 32 41 65 6 8 15 -3 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}

		TEST_METHOD(deleteNode)
		{
			BinarTree<int> bt{ 9, 11, 1, 5, 3, 17, 4, 13, 15, 14 };

			std::ostringstream os;
			auto coutBuff = std::cout.rdbuf();
			auto osBuff = os.rdbuf();
			std::cout.rdbuf(osBuff);

			bt.deleteNode(bt.getRoot(), 11);
			bt.inorder(bt.getRoot());

			std::cout.rdbuf(coutBuff);

			const std::string actual = os.str();
			const std::string expected = "1 3 4 5 9 13 14 15 17 ";

			Assert::AreEqual(expected, actual, L"", LINE_INFO());
		}
	};
}
