#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4/customVector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomVecTest
{
	TEST_CLASS(CustomVecTest)
	{
	public:
		
		TEST_METHOD(TestSize)
		{
			customVector<int> vec;
			vec.append(1);
			vec.append(2);
			vec.append(3);
			Assert::AreEqual(vec.size(), 3);
		}
		TEST_METHOD(TestGet) {
			customVector<int> vec;
			vec.append(1);
			vec.append(2);
			vec.append(3);
			vec.append(4);
			Assert::AreEqual(vec.get(0), 1);
			Assert::AreEqual(vec.get(2), 3);
		}
		TEST_METHOD(TestReverse) {
			customVector<int> vec;
			vec.append(1);
			vec.append(2);
			vec.append(3);
			vec.append(4);
			vec.append(5);
			vec.reverse();
			customVector<int> expectDeezNuts;
			expectDeezNuts.append(5);
			expectDeezNuts.append(4);
			expectDeezNuts.append(3);
			expectDeezNuts.append(2);
			expectDeezNuts.append(1);

			for (int i = 0; i < vec.size(); i++) {
				Assert::AreEqual(expectDeezNuts.get(i), vec.get(i));
			}
		}
		TEST_METHOD(TestReverseFail) {
			customVector<int> vec;
			vec.append(1);
			vec.append(2);
			vec.append(253097632409571);
			vec.append(4);
			vec.append(5);
			vec.reverse();
			customVector<int> expectDeezNutsInYourFace;
			expectDeezNutsInYourFace.append(5);
			expectDeezNutsInYourFace.append(4);
			expectDeezNutsInYourFace.append(3);
			expectDeezNutsInYourFace.append(2);
			expectDeezNutsInYourFace.append(1);


			for (int i = 0; i < vec.size(); i++) {
				Assert::AreEqual(expectDeezNutsInYourFace.get(i), vec.get(i));
			}
		}
	};
}
