#pragma once
#include "SoundBank.h"

SoundBank* SoundBank::instance = new SoundBank();

//initialize & implement Sound Effects & Background Music here
SoundBank::SoundBank() {
	//defining sound effects
	soundPathList = std::unordered_map<SoundEffectType, char*> {
		{ SoundEffectType::CORRECT, "Resources/sound/sfx/soundcorrect.wav" },
		{SoundEffectType::SHOTGUN, "Resources/sound/sfx/shotgun.wav"},
		{ SoundEffectType::GAMEOVER, "Resources/sound/sfx/Announcer/ACDDATA_0088.wav" },
		{ SoundEffectType::YOU, "Resources/sound/sfx/Announcer/ACDDATA_0082.wav" },
		{ SoundEffectType::LOSE, "Resources/sound/sfx/Announcer/ACDDATA_0085.wav" },
		{ SoundEffectType::WIN, "Resources/sound/sfx/Announcer/ACDDATA_0084.wav" },
		{ SoundEffectType::LETSROCK, "Resources/sound/sfx/Announcer/ACDDATA_0102.wav" }

	};

	//defining background music
	bgmPathList = std::unordered_map<SoundBgmType, char*>{
		{ SoundBgmType::TESTBGM1, "Resources/sound/bg/balcony.mp3" },
		{ SoundBgmType::TESTBGM2, "Resources/sound/bg/lastcave.mp3" },
		{ SoundBgmType::THUNDERSTRUCK, "Resources/sound/bg/thunderstruck.mp3" },
		{ SoundBgmType::REDALERT1, "Resources/sound/bg/17-ost-allied_combat_2-daw.mp3" },
		{ SoundBgmType::REDALERT2, "Resources/sound/bg/33-ost-allied_-_up_yours-daw.mp3" }
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
void SoundBank::PlaySFX(SoundEffectType type) {
	if (sfxEnabled) {
		//Get the appropriate SoundChunk depending on the SoundEffectType
		Mix_Chunk* tempSound = Mix_LoadWAV(soundPathList.at(type));
		SoundChunk* soundChunk = new SoundChunk(tempSound);

		//Change Volume depending on the given volume in the parameters
		Mix_VolumeChunk(tempSound, musicVolume); //volume = between [0 - 128], 64 = neutral

		//soundChunk->Play();
		//and let SoundChunk remember its channel (which doesn't work correctly yet)
		soundChunk->Play();

		//put SoundChunk into the playingChunks list
		std::pair<SoundEffectType, SoundChunk*> typeChunk(type, soundChunk);
		playingChunks.insert(typeChunk);
	}
}

//Fyi, this action is also toggle-ish, when something is already playing, it will fade out and start the new BGM
void SoundBank::PlayAtChannel(int channel, SoundEffectType type) {
	if (sfxEnabled) {
		//Get the appropriate SoundChunk depending on the SoundEffectType
		Mix_Chunk* tempSound = Mix_LoadWAV(soundPathList.at(type));
		SoundChunk* soundChunk = new SoundChunk(tempSound);

		//Change Volume depending on the given volume in the parameters
		Mix_VolumeChunk(tempSound, musicVolume); //volume = between [0 - 128], 64 = neutral

		//soundChunk->Play();
		//and let SoundChunk remember its channel (which doesn't work correctly yet)
		soundChunk->PlayAtChannel(channel);

		//put SoundChunk into the playingChunks list
		std::pair<SoundEffectType, SoundChunk*> typeChunk(type, soundChunk);
		playingChunks.insert(typeChunk);
	}
}

//BackGroundMusic, volume = between [0 - 128], 64 = neutral
void SoundBank::PlayBGM(SoundBgmType type) {
	if (musicEnabled) {
		Mix_Music* tempMusic = Mix_LoadMUS(bgmPathList.at(type));
		if (!Mix_PlayingMusic()) { //there is no music playing yet
			Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
			Mix_VolumeMusic(sfxVolume);
			currentBGM = type;
		}
		else if(!Mix_PausedMusic()) { //there is already music playing
			Mix_FadeOutMusic(1000);
			Mix_FadeInMusic(Mix_LoadMUS(bgmPathList.at(type)), -1, 1000);
			Mix_VolumeMusic(sfxVolume);
			currentBGM = type;
		}
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

void SoundBank::ToggleMusic() {
	if (musicEnabled) {
		musicEnabled = false;
		StopMusic();
	}
	else {
		musicEnabled = true;
		PlayBGM(currentBGM);
	}
}

void SoundBank::ToggleSFX() {
	if (sfxEnabled) {
		sfxEnabled = false;
	}
	else {
		sfxEnabled = true;
	}
}

bool SoundBank::IsEnabledMusic() {
	return musicEnabled;
}

bool SoundBank::IsEnabledSFX() {
	return sfxEnabled;
}