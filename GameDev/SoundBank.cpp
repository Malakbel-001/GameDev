#pragma once
#include "SoundBank.h"
#include <iostream>
#include <string>

SoundBank* SoundBank::instance = new SoundBank();

SoundBank::SoundBank() {
	soundPathList = std::unordered_map<SoundEffectType, char*> {
		{ SoundEffectType::CORRECT, "../Assets/soundcorrect.wav" }
	};
	bgmPathList = std::unordered_map<SoundBgmType, char*>{
		{ SoundBgmType::TESTBGM1, "../Assets/balcony.mp3" },
		{ SoundBgmType::TESTBGM2, "../Assets/lastcave.mp3" }
	};
}

SoundBank::~SoundBank(){
	//nothing to destroy
	//FreeMemory(); //might be scary
}

SoundBank* SoundBank::getInstance() {
	return (SoundBank::instance);
}

void SoundBank::Play(SoundEffectType type) {
	//Get the appropriate SoundChunk depending on the SoundEffectType
	Mix_Chunk* tempSound = Mix_LoadWAV(soundPathList.at(type));
	SoundChunk* soundChunk = new SoundChunk(tempSound);

	//Change Volume depending on the given volume in the parameters
	//TODO

	//soundChunk->Play();
	//and let SoundChunk remember its channel
	soundChunk->Play();

	//throw SoundChunk into the playingChunks list
	std::pair<SoundEffectType, SoundChunk*> typeChunk(type, soundChunk);
	playingChunks.insert(typeChunk);
}

void SoundBank::PlayBGM(SoundBgmType type) {
	if (!Mix_PlayingMusic()) { //not playing yet
		Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
	}
	else { //there is already music playing
		Mix_FadeOutMusic(1000);
		Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
	}
}

//only use this for clearing SoundBank before shutting down
//and make sure all sounds are finished first
void SoundBank::FreeMemory() {
	std::unordered_map<SoundEffectType, SoundChunk*>::iterator iter = playingChunks.begin();
	
	playingChunks.clear();

	//Mix_FreeChunk !?
	//Mix_FreeMusic !?

	//for (auto it = playingChunks.begin(); it != playingChunks.end(); ++it) {
	//	//int* channel = iter->second->GetChannel();
	//	//delete(iter->second);
	//}

	//delete(playingChunks);
	//playingChunks = new std::unordered_map<SoundEffectType, SoundChunk*>();
}