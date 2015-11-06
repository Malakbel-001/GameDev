#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameDev/InputManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			InputManager* manager = new InputManager();
			//Assert::AreEqual(expecte)
		}

	};
}