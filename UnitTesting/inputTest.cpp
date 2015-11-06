#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameDev/InputManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(KeyInput_W)
		{
			InputManager* manager = new InputManager();
			manager->SetKeyInput(SDLK_w);
			Assert::AreEqual(true, manager->GetKeyInput()->at(SDLK_w));
		}

		TEST_METHOD(KeyInput_A) {
			InputManager* manager = new InputManager();
			manager->SetKeyInput(SDLK_a);
			Assert::AreEqual(true, manager->GetKeyInput()->at(SDLK_a));
		}

		TEST_METHOD(KeyInput_S) {
			InputManager* manager = new InputManager();
			manager->SetKeyInput(SDLK_s);
			Assert::AreEqual(true, manager->GetKeyInput()->at(SDLK_s));
		}

		TEST_METHOD(KeyInput_D) {
			InputManager* manager = new InputManager();
			manager->SetKeyInput(SDLK_d);
			Assert::AreEqual(true, manager->GetKeyInput()->at(SDLK_d));
		}

		TEST_METHOD(KeyInput_ESC) {
			InputManager* manager = new InputManager();
			manager->SetKeyInput(SDLK_ESCAPE);
			Assert::AreEqual(true, manager->GetKeyInput()->at(SDLK_ESCAPE));
		}

	};
}