#include "SoundMemory.h"
#include "CSoundBank.h"

void SoundMemory::sound1() {
	CSoundBank::SoundControl.OnLoad("../Assets/dingding.wav");
	Mix_Chunk* tempSound = Mix_LoadWAV("../Assets/dingding.wav");
	Mix_Music* durr = Mix_LoadMUS("../Assets/lastcave.mp3");

}

void SoundMemory::sound2() {
	CSoundBank::SoundControl.OnLoad("../Assets/soundcorrect.wav");
}