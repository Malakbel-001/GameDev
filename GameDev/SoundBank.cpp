#pragma once
#include "SoundBank.h"
#include <iostream>
#include <string>

SoundBank* SoundBank::instance = new SoundBank();

SoundBank::SoundBank() {
	/*soundList = std::unordered_map<SoundEffectType, Sound>{
		{ SoundEffectType::CORRECT, Sound("../Assets/soundcorrect.wav") }
		};
		soundBGMList = std::unordered_map<SoundBgmType, Sound>{
		{ SoundBgmType::TESTBGM, Sound("") }
		};*/

	soundPathList = std::unordered_map<SoundEffectType, char*> {
		{ SoundEffectType::CORRECT, "../Assets/soundcorrect.wav" }
	};
	
}

//make sure to destruct SoundBank before you SDL_Mixer = closed because of FreeMemory -> FreeChunk
SoundBank::~SoundBank(){
	FreeMemory();
	//delete(playingChunks);
}

void SoundBank::FreeMemory() {
	std::unordered_map<SoundEffectType, SoundChunk*>::iterator iter = playingChunks.begin();
	
	while (iter != playingChunks.end()) {
		int* channel = iter->second->GetChannel();
		if (Mix_Playing(*channel) == 0) {
			delete(iter->second);
		}
		iter++;
	}
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
	soundChunk->SetChannel(soundChunk->Play());

	//throw SoundChunk into the playingChunks list
	std::pair<SoundEffectType, SoundChunk*> typeChunk(type, soundChunk);
	playingChunks.insert(typeChunk);
}

void PlayBGM(char* file) {
	//Mix_Music* tempBGM = NULL;
	//if ((tempBGM = Mix_LoadMUS(file)) == NULL) { //error handling
	//	std::cout << "Error: BGM File = NULL!" << std::endl;
	//	return;
	//}
	//else if (Mix_PlayingMusic()) {
	//	Mix_FadeOutMusic(1000);
	//	Mix_FreeMusic(SoundBank::SoundControl.currentBGM); //Because of Memory Leaks, maybe?
	//	Mix_FadeInMusic(tempBGM, -1, 1000);
	//	SoundBank::SoundControl.currentBGM = tempBGM;
	//}
	//else {
	//	Mix_FadeInMusic(tempBGM, -1, 1000);
	//	SoundBank::SoundControl.currentBGM = tempBGM;
	//}
}


//std::string* SoundBank::checkValidPath(std::string* path) {
//	if (Mix_LoadWAV(path->c_str) == NULL) {
//		//throw error (runtime_error?)
//		std::cout << "Unable to load <"+(*path)+">" << std::endl; //might throw errors
//	}
//	//else
//	return path;
//}



//void CSoundBank::OnLoad(SoundEffectType type) {
//	Mix_Chunk* tempSound = Mix_LoadWAV(file);
//	Sound* sound = soundList.at(type).Clone();
//	b2BodyDef bodydef;
//	bodydef.position.Set(x, y);
//	b2Body* b2body = world.CreateBody(&bodydef);
//	ent->Init(b2body);
//	return ent;
//
//	
//
//
//	if (tempSound == NULL) {
//		std::cout << "Error: Sound Effect File = NULL!" << std::endl;
//		return -1;
//	}
//
//	soundList.push_back(tempSound);
//
//	return (soundList.size() - 1);
//}

//void CSoundBank::OnCleanup() {
	/*for (int i = 0; i < soundList.size(); i++) {
		Mix_FreeChunk(soundList[i]);
	}

	soundList.clear();*/
//}