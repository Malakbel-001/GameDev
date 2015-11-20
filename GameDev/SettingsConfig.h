#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class SettingsConfig {
private:
	const char* optionSettings = "settings.txt";

public:
	SettingsConfig();
	~SettingsConfig();

	void SaveSettings();
	void LoadSettings();
};