#include "SoundChunk.h"

SoundChunk::SoundChunk(Mix_Chunk* newChunk) {
	chunk = newChunk;
}

SoundChunk::~SoundChunk() {
	Mix_FreeChunk(chunk);
}

int* SoundChunk::Play() {
	int channel = Mix_PlayChannel(-1, this->chunk, 0);
	return &channel; //TODO: one-liner?
}

void SoundChunk::SetChannel(int* newChannel) {
	channel = newChannel;
}

int* SoundChunk::GetChannel() {
	return channel;
}

//Sound::Sound(char* newFile) {
//	file = newFile;
//}
//Sound::~Sound() {
//	file = nullptr; //idk
//}
//
//Sound* Sound::Clone(){
//	return new Sound(file); 
//	//TODO don't know if this is an appropriate clone, especially giving new Sound -> file
//}
//

//
//void Sound::SetFile(char* newFile) {
//	file = newFile;
//}
//

//
//char* Sound::GetFile() {
//	return file;
//}