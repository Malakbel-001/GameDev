#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameDev/InputManager.h"
#include "../GameDev/BehaviourFactory.h"
#include "../GameDev/EntityType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int screenheight = 600;
			int screenwidth = 800;

			SDL_Window* window = SDL_CreateWindow("titel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenheight, screenwidth, false);
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

			BehaviourFactory* factory = new BehaviourFactory(renderer, screenwidth, screenheight);
			DrawableBehaviour* behaviour = factory->CreateDrawableBehaviour(EntityType::PLAYER);
		}
	};
}