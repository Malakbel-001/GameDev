#include "FileIO.h"

FileIO::FileIO()
{
	x = 0, y = -1;
}

FileIO::~FileIO()
{ }

void FileIO::ReadFile(std::string levelFile)
{
	std::string line;
	std::ifstream myfile(levelFile.c_str());
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			this->ReadLine(line);
			++this->y;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to open file" << levelFile;
	}

	// print arrays
	for (size_t i = 0; i < this->level.size(); i++)
	{
		for (size_t j = 0; j < this->level[0].size(); j++)
		{
			std::cout << this->level[i][j] << ", ";
		}
		std::cout << "\n";
	}

	this->WriteLevelToFile(this->level);
	std::cin.get();
}

void FileIO::ReadLine(std::string line)
{
	std::istringstream ss(line);
	std::string token;

	while (std::getline(ss, token, ':'))
	{
		this->ProcessToken(token);
		++this->x;
	}
	this->x = 0;
}

void FileIO::ProcessToken(std::string line)
{
	std::string height = "height;";
	std::string width = "width;";
	std::istringstream ss(line);

	if (line.substr(0, height.size()) == height)
	{
		int i = atoi(line.substr(height.size(), line.size()).c_str());
		this->level.resize(i);
	}
	else if (line.substr(0, width.size()) == width)
	{
		int j = atoi(line.substr(width.size(), line.size()).c_str());
		for (size_t i = 0; i < level.size(); ++i)
			this->level[i].resize(j);
	}
	else
	{
		int test = atoi(line.c_str());
		if (test > 0)
		{
			this->level[y][x] = test;
		}
	}
}

void FileIO::WriteLevelToFile(std::vector< std::vector<int> > level)
{
	int height = static_cast<int>(level.size());
	int width = static_cast<int>(level[0].size());

	// setting up first line
	std::ostringstream sStream;
	sStream << "height;" << height << ":width;" << width << "\n";
	std::string firstLine = sStream.str();

	std::ofstream output_file;
	output_file.open("testFile.txt");

	output_file << firstLine;
	for (size_t i = 0; i < level.size(); i++)
	{
		for (size_t j = 0; j < level[0].size(); j++)
		{
			if (j < level[0].size() - 1)
			{
				output_file << level[i][j] << ":";
				std::cout << level[i][j] << ":";
			}
			else
			{
				output_file << level[i][j];
				std::cout << level[i][j];
			}
		}
		output_file << "\n";
		std::cout << "\n";
	}
	output_file.close();

	std::cin.get();
}
