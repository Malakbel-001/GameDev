#include "SettingsConfig.h"

SettingsConfig::SettingsConfig() {

}

SettingsConfig::~SettingsConfig() {

}

map<string, bool> SettingsConfig::LoadSettings() {
	ifstream settings;
	settings.open(optionSettingsChar);
	string line;
	map<string, bool> settingsMap = map<string, bool>();
	if (settings.is_open()) {
		while (getline(settings, line)) {
			istringstream is_line(line);
			string key;
			if (getline(is_line, key, '=')) {
				//TODO error handling on key, catch filthy people that will break the system
				string value;
				if (getline(is_line, value)) {
					if (value.size() != 1 || value[0] < '0' || value[0] > '1') { //error handling value/bool
						cout << "Error, couldn't read value" << endl;
						//no console though, throw exception error?
					}
					else {
						bool booleanValue = (value[0] == '1');
						settingsMap.insert(make_pair(key, booleanValue));
					}
				}
			}
		}
	}
	else {
		cout << "Unable to open file/settings" << endl;
	}
	return settingsMap;
}

void SettingsConfig::SaveSettings(bool musicBool, bool sfxBool, bool fullScreenBool) {
	ofstream settings;
	settings.open(optionSettingsChar);
	if (settings.is_open()) {
		//save all settings (will automatically overwrite previous settings)
		settings << musicChar << musicBool << endl; //SoundBank Music On/Off
		settings << sfxChar << sfxBool << endl; //SoundBank SFX On/Off
		settings << fullscreenChar << fullScreenBool << endl; //Fullscreen On/Off

		settings.close();
	}
	else {
		cout << "Unable to open file/settings" << endl;
	}
}