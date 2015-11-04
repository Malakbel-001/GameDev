#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

class FileIO
{
private:
	int x, y;
	std::vector< std::vector<int> > level;

	void ReadLine(std::string line);
	void ProcessToken(std::string line);

protected:
	// stuff

public:
	FileIO();
	virtual ~FileIO();

	void ReadFile(std::string levelFile);
	void WriteLevelToFile(std::vector< std::vector<int> > level);
};
