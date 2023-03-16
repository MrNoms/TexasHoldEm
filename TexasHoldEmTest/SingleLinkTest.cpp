#include "pch.h"
#include "CppUnitTest.h"
#include "..\cpp\SingleLink.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SingleLinkTest
{
	TEST_CLASS(SingleLinkTest)
	{
	public:
		
		TEST_METHOD(Primitive_Construction)
		{
			Assert::AreEqual(5, SingleLink<int>(5).data);
		}

		TEST_METHOD(Object_Construction) {
			Assert::AreEqual("cat", SingleLink<std::string>("cat").data.c_str());
		}

		TEST_METHOD(Chain) {
			SingleLink<std::string> tester("cat");
			tester.next = new SingleLink<std::string>("dog");

			Assert::AreEqual("dog", tester.next->data.c_str());
		}

		TEST_METHOD(Display) {
			Assert::AreEqual(SingleLink<double>(2.5).toString(), std::string("{ 2.5 }->"));
		}
	};
}
