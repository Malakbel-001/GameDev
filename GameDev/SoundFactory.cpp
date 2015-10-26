#include <iostream>
#include "SoundFactory.h"

SoundFactory::SoundFactory() {
	
}

SoundFactory::~SoundFactory() {

}

/*
Sets Next BackGroundMusic
Move Music File -> Map Assets -> BGM
*/
void SoundFactory::SetNextBGM(Mix_Music *bgm) {
	if (bgm == NULL) { //error handling
		std::cout << "Error: BGM File = NULL!" << std::endl;
	}
	else if (Mix_PlayingMusic()) {
		Mix_FadeOutMusic(1000);
		//Mix_FreeMusic(current_bgm); //Because of Memory Leaks, maybe?
		Mix_FadeInMusic(bgm, -1, 1000);
		//current_bgm = bgm;
	}
	else {
		Mix_FadeInMusic(bgm, -1, 1000);
		//current_bgm = bgm;
	}
}

void SetSoundEffect(Mix_Chunk *soundEffect) {
	Mix_PlayChannel(-1, soundEffect, 0);
	//Mix_FreeChunk(soundEffect);
	//std::cout << Mix_ << std::endl;
}

void LoopSoundEffect(Mix_Chunk *soundEffect) {

}

void StopLoopingSoundEffect(Mix_Chunk *soundEffect) {

}