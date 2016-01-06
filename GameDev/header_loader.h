#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <rapidxml-1.13\rapidxml.hpp>
//Uncomment the following line to turn on Visual Leak Detector. (Needs to be installed!)
#include <vld.h> 

static const std::string BASEPATH = SDL_GetBasePath();
static const std::string RESOURCEPATH = BASEPATH + "Resources\\";
static const std::string SAVEPATH = BASEPATH + "Saves\\";
//static const double OPTIMALRESOLUTIONW = 1600;
//static const double OPTIMALRESOLUTIONH = 900;
#include <rapidxml-1.13\rapidxml.hpp>
