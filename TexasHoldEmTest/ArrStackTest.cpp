#include "pch.h"
#include "CppUnitTest.h"
#include "..\cpp\ArrStack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrStackTest
{
	TEST_CLASS(ArrStackTest)
	{
	public:

		TEST_METHOD(Good_Construction) {
			//create a stack
			ArrStack<char> tester(2);

			//verify size
			Assert::AreEqual(0, tester.size());
		}

		TEST_METHOD(Empty_Construction) {
			//catch exception of constructed 0 stack
			Assert::ExpectException<std::out_of_range>(
				[]() {ArrStack<int> tester(0); }
				);
		}

		TEST_METHOD(Empty) {
			//create a stack
			ArrStack<std::string> tester(3);

			//ensure it's empty
			Assert::IsTrue(tester.isEmpty());

			//add to it
			tester.add("one");

			//see that it's not empty
			Assert::IsFalse(tester.isEmpty());
		}

		TEST_METHOD(Full) {
			//create array and populate
			ArrStack<char> tester(2);
			tester.add('c');

			//ensure it's not full
			Assert::IsFalse(tester.isFull());

			//fill the stack and verify is full
			tester.add('a');
			Assert::IsTrue(tester.isFull());
		}
		TEST_METHOD(Add_To_Stack) {
			//create a stack
			ArrStack<double> tester(3);

			//add to it
			tester.add(3.2);
			tester.add(5.3);

			//verify the size
			Assert::AreEqual(2, tester.size());
		}

		TEST_METHOD(Add_To_Full) {
			//create stack and fill it
			ArrStack<std::string> tester(1);
			tester.add("all");

			//add again and catch exception
			Assert::ExpectException<std::length_error>(
				[&tester]() { tester.add("over"); }
				);
		}

		TEST_METHOD(Pop_From_Stack) {
			//create stack and populate it
			ArrStack<int> tester(1);
			tester.add(3);

			//pop from it and verify size
			Assert::AreEqual(3, tester.pop());
			Assert::AreEqual(0, tester.size());
		}

		TEST_METHOD(Pop_From_Empty) {
			//create stack
			ArrStack<void*> tester(1);

			//pop and catch exception
			Assert::ExpectException<std::out_of_range>(
				[&tester]() { tester.pop(); }
				);
		}

		TEST_METHOD(Peek_At_Stack) {
			//Create and populate stack
			ArrStack<char> tester(2);
			tester.add('4');
			tester.add(' ');

			//ensure proper peek
			Assert::AreEqual(' ', tester.peek());
		}

		TEST_METHOD(Peek_At_Nothing) {
			//create stack
			ArrStack<std::string> tester(1);

			//peek and catch exception
			Assert::ExpectException<std::out_of_range>(
				[&tester]() { tester.peek(); }
			);
		}

		TEST_METHOD(Display) {
			std::string a = " ", b = "caT";

			//Create stacks and check toString
			ArrStack<std::string> tester(2);

			Assert::AreEqual("---", tester.toString().c_str());

			tester.add(a);
			tester.add(b);

			Assert::AreEqual("caT\n \n---", tester.toString().c_str());
		}
	};
}