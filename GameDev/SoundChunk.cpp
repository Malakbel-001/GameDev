#include "SoundChunk.h"

SoundChunk::SoundChunk(Mix_Chunk* newChunk) {
	chunk = newChunk;
}

SoundChunk::~SoundChunk() {
	Mix_FreeChunk(chunk);
}

void SoundChunk::Play() {
	int newChannel = Mix_PlayChannel(-1, this->chunk, 0);
	//channel = &newChannel; //setChannel TODO!! fix.
}

int* SoundChunk::GetChannel() {
	return channel;
}