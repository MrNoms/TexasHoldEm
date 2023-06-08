#include "pch.h"
#include "CppUnitTest.h"
#include "..\include\Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTest
{
	TEST_CLASS(StackTest)
	{
	public:

		TEST_METHOD(Construction) {
			//create a stack
			Stack<char> tester;

			//verify size
			Assert::AreEqual(0, tester.getSize());
		}

		TEST_METHOD(Add_To_Stack) {
			//create a stack
			Stack<double> tester;

			//add to it
			Assert::IsTrue(tester.add(3.2));
			Assert::IsTrue(tester.add(5.3));

			//verify the size
			Assert::AreEqual(2, tester.getSize());
		}

		TEST_METHOD(Empty) {
			//create a stack
			Stack<std::string> tester;

			//ensure it's empty
			Assert::IsTrue(tester.isEmpty());

			//add to it
			tester.add("one");

			//see that it's not empty
			Assert::IsFalse(tester.isEmpty());
		}

		TEST_METHOD(Pop_From_Stack) {
			//create stack and populate it
			Stack<int> tester;
			tester.add(3);

			//pop from it and verify size
			Assert::AreEqual(3, tester.pop());
			Assert::AreEqual(0, tester.getSize());
		}

		TEST_METHOD(Pop_From_Empty) {
			//create stack
			Stack<void*> tester;

			//pop and catch exception
			Assert::ExpectException<std::logic_error>(
				[&tester]() { tester.pop(); }
				);
		}

		TEST_METHOD(Peek_At_Stack) {
			//Create and populate stack
			Stack<char> tester;
			tester.add('4');
			tester.add(' ');

			//ensure proper peek
			Assert::AreEqual(' ', tester.peek());
		}

		TEST_METHOD(Peek_At_Nothing) {
			//create stack
			Stack<std::string> tester;

			//peek and catch exception
			Assert::ExpectException<std::logic_error>(
				[&tester]() { tester.peek(); }
			);
		}

		TEST_METHOD(Display) {
			std::string a = " ", b = "caT";

			//Create stacks and check toString
			Stack<std::string> tester;

			Assert::AreEqual("---", tester.toString().c_str());

			tester.add(a);
			tester.add(b);

			Assert::AreEqual(SingleLink<std::string>(b).toString()
				.append("\n")
				.append(SingleLink<std::string>(a).toString())
				.append("\n---"), tester.toString());
		}
	};
}