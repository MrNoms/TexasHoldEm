#include "pch.h"
#include "CppUnitTest.h"
#include "CircleList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircleListTest {
	TEST_CLASS(CircleListTest) {
	public:
		TEST_METHOD(Construction) {
			//create a new circular linked list
			CircleList<int> cl = CircleList<int>();

			//it should start at null and have a 0 size
			Assert::IsTrue(nullptr == cl.begin());
			Assert::AreEqual(0, cl.getSize());
		}

		TEST_METHOD(Put) {
			//create a new list
			CircleList<int> cl = CircleList<int>();

			//put an element
			cl.putNode(4);

			//verify the contents
			Assert::AreEqual(4, cl.begin()->data);
		}

		TEST_METHOD(Delete_Pass) {
			//create a new list and add element
			CircleList<char> cl = CircleList<char>();
			cl.putNode('c');

			//deleting that content will be true
			Assert::IsTrue(cl.deleteNode('c'));
		}

		TEST_METHOD(Delete_Fail) {
			//delete content that doesn't exist will be false
			CircleList<std::string> cl = CircleList<std::string>();

			Assert::IsFalse(cl.deleteNode("exists"));

			cl.putNode("new Data");
			Assert::IsFalse(cl.deleteNode("new data"));
		}
	};
}