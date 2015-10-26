#pragma once
#include "CSoundBank.h"
#include <iostream>

CSoundBank CSoundBank::SoundControl;

CSoundBank::CSoundBank() {
	currentBGM = NULL;
}

int CSoundBank::OnLoad(char* file) {
	Mix_Chunk* tempSound = Mix_LoadWAV(file);

	if (tempSound == NULL) {
		std::cout << "Error: Sound Effect File = NULL!" << std::endl;
		return -1;
	}

	soundList.push_back(tempSound);

	return (soundList.size() - 1);
}

void CSoundBank::OnCleanup() {
	for (int i = 0; i < soundList.size(); i++) {
		Mix_FreeChunk(soundList[i]);
	}

	soundList.clear();
}

void CSoundBank::Play(int ID) {
	if (ID < 0 || ID >= soundList.size()) return;
	if (soundList[ID] == NULL) return;

	Mix_PlayChannel(-1, soundList[ID], 0);
}

void PlayBGM(char* file) {
	Mix_Music* tempBGM = NULL;
	if ((tempBGM = Mix_LoadMUS(file)) == NULL) { //error handling
		std::cout << "Error: BGM File = NULL!" << std::endl;
		return;
	}
	else if (Mix_PlayingMusic()) {
		Mix_FadeOutMusic(1000);
		Mix_FreeMusic(CSoundBank::SoundControl.currentBGM); //Because of Memory Leaks, maybe?
		Mix_FadeInMusic(tempBGM, -1, 1000);
		CSoundBank::SoundControl.currentBGM = tempBGM;
	}
	else {
		Mix_FadeInMusic(tempBGM, -1, 1000);
		CSoundBank::SoundControl.currentBGM = tempBGM;
	}
}