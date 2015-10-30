#pragma once
#include "SDL_mixer.h"

class SoundChunk {
private:
	Mix_Chunk* chunk;
	int* channel;
public:
	SoundChunk(Mix_Chunk* newChunk);
	~SoundChunk();
	//Sound(char* newFile);

	int* Play();

	void SetChannel(int* newChannel);
	int* GetChannel();
};