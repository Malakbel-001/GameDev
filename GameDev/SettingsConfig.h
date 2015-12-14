#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

class SettingsConfig {
private:
	const char* optionSettingsChar		= "Resources/settings/settings.txt";
	const char* musicChar				= "music=";
	const char* sfxChar					= "sfx=";
	const char* fullscreenChar			= "fullscreen=";

public:
	SettingsConfig();
	~SettingsConfig();

	void SaveSettings(bool musicBool, bool sfxBool, bool fullScreenBool);
	map<string, bool> LoadSettings();
};