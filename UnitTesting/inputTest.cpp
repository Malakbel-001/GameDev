#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameDev/InputManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(KeyInput)
		{
			InputManager* manager = new InputManager();
			manager->SetKeyInput(SDLK_w);
			manager->SetKeyInput(SDLK_d);
			//Expected Key_Input SDLK_w
			Assert::AreEqual(true, manager->GetKeyInput()->at(SDLK_w));
			Assert::AreEqual(true, manager->GetKeyInput()->at(SDLK_d));
		}

	};
}