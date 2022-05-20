#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab12_6.4A\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L = nullptr;
			insert(L, 3);
			insert(L, -5);
			removes(L, 3);
			Assert::AreEqual(L->info, -5);
		}
	};
}
