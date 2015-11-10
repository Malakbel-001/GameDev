#pragma once
#include "SoundBank.h"

SoundBank* SoundBank::instance = new SoundBank();

//initialize & implement Sound Effects & Background Music here
SoundBank::SoundBank() {
	//defining sound effects
	soundPathList = std::unordered_map<SoundEffectType, char*> {
		{ SoundEffectType::CORRECT, "../Assets/soundcorrect.wav" }
	};

	//defining background music
	bgmPathList = std::unordered_map<SoundBgmType, char*>{
		{ SoundBgmType::TESTBGM1, "../Assets/balcony.mp3" },
		{ SoundBgmType::TESTBGM2, "../Assets/lastcave.mp3" },
		{ SoundBgmType::THUNDERSTRUCK, "../Assets/thunderstruck.mp3" }
	};
}

SoundBank::~SoundBank(){
	//nothing to destroy
	FreeMemory(); //might be scary in the future fyi
}

SoundBank* SoundBank::GetInstance() {
	return (SoundBank::instance);
}

//SoundEffect, volume = between [0 - 128], 64 = neutral
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

//BackGroundMusic, volume = between [0 - 128], 64 = neutral
void SoundBank::PlayBGM(SoundBgmType type, int volume) {
	Mix_Music* tempMusic = Mix_LoadMUS(bgmPathList.at(type));
	if (!Mix_PlayingMusic()) { //there is no music playing yet
		Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
		Mix_VolumeMusic(volume);
	}
	else if(!Mix_PausedMusic()) { //there is already music playing
		Mix_FadeOutMusic(1000);
		Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
		Mix_VolumeMusic(volume);
	}
}

void SoundBank::PauseOrResume() {
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
}

void SoundBank::SetMusicVolume(int newVolume) {
	musicVolume = newVolume;
}

void SoundBank::SetMusicVolume(int newVolume) {
	sfxVolume = newVolume;
}

void SoundBank::DisableOrEnableMusic() {
	if (MusicEnabled) {
		MusicEnabled = false;
	}
	else {
		MusicEnabled = true;
	}
}

void SoundBank::DisableOrEnableSFX() {
	if (SfxEnabled) {
		SfxEnabled = false;
	}
	else {
		SfxEnabled = true;
	}
}

bool SoundBank::IsEnabledMusic() {
	return SfxEnabled;
}

bool SoundBank::IsEnabledSFX() {
	return MusicEnabled;
}