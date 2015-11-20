#include "SettingsConfig.h"

SettingsConfig::SettingsConfig() {

}

SettingsConfig::~SettingsConfig() {

}

void SettingsConfig::LoadSettings() {

}

void SettingsConfig::SaveSettings() {
	ofstream settings;
	settings.open(optionSettings);
	if (settings.is_open()) {
		//clear settings


		//save all settings
		settings << "music=true" << endl; //SoundBank Music On/Off
		settings << "sfx=true" << endl; //SoundBank SFX On/Off
		settings << "fullscreen=true" << endl; //Fullscreen On/Off

		settings.close();
	}
	else {
		cout << "Unable to open settings" << endl;
	}
}