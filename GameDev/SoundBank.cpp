#pragma once
#include "SoundBank.h"
#include <iostream>
#include <string>

SoundBank* SoundBank::instance = new SoundBank();

SoundBank::SoundBank() {
	//defining sound effects
	soundPathList = std::unordered_map<SoundEffectType, char*> {
		{ SoundEffectType::CORRECT, "../Assets/soundcorrect.wav" }
	};

	//defining background music
	bgmPathList = std::unordered_map<SoundBgmType, char*>{
		{ SoundBgmType::TESTBGM1, "../Assets/balcony.mp3" },
		{ SoundBgmType::TESTBGM2, "../Assets/lastcave.mp3" }
	};
}

SoundBank::~SoundBank(){
	//nothing to destroy
	FreeMemory(); //might be scary and buggy
}

SoundBank* SoundBank::GetInstance() {
	return (SoundBank::instance);
}

void SoundBank::Play(SoundEffectType type, int volume) {
	//Get the appropriate SoundChunk depending on the SoundEffectType
	Mix_Chunk* tempSound = Mix_LoadWAV(soundPathList.at(type));
	SoundChunk* soundChunk = new SoundChunk(tempSound);

	//Change Volume depending on the given volume in the parameters
	Mix_VolumeChunk(tempSound, volume); //volume = between [0 - 128], 64 = neutral

	//soundChunk->Play();
	//and let SoundChunk remember its channel (which doesn't work correctly yet)
	soundChunk->Play();

	//put SoundChunk into the playingChunks list
	std::pair<SoundEffectType, SoundChunk*> typeChunk(type, soundChunk);
	playingChunks.insert(typeChunk);
}

void SoundBank::PlayBGM(SoundBgmType type, int volume) {
	Mix_Music* tempMusic = Mix_LoadMUS(bgmPathList.at(type));
	if (!Mix_PlayingMusic()) { //there is no music playing yet
		Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
		Mix_VolumeMusic(volume);
	}
	else { //there is already music playing
		Mix_FadeOutMusic(1000);
		Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
		Mix_VolumeMusic(volume);
	}
}

void SoundBank::PauseOrResume() { //TODO not working yet
	if (Mix_PausedMusic()) {
		Mix_ResumeMusic();
	}
	else {
		Mix_PauseMusic();
	}
}

void SoundBank::StopMusic() {
	Mix_HaltMusic();
}

//only use this for clearing SoundBank before shutting down
//and make sure all sounds are finished first
void SoundBank::FreeMemory() {
	std::unordered_map<SoundEffectType, SoundChunk*>::iterator iter = playingChunks.begin();
	
	playingChunks.clear(); //call destructor on every SoundChunk & clear playingChunks list

	//Mix_FreeChunk TODO needed or not??
	//Mix_FreeMusic TODO needed or not??

	//old code, maybe needed in the future if memory leak and stuff

	//for (auto it = playingChunks.begin(); it != playingChunks.end(); ++it) {
	//	//int* channel = iter->second->GetChannel();
	//	//delete(iter->second);
	//}

	//delete(playingChunks);
	//playingChunks = new std::unordered_map<SoundEffectType, SoundChunk*>();
}