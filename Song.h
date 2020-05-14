#pragma once
#include <string>
#include "Genre.h"
using namespace std;


struct Song
{
	string Name;
	int Minute, Second;
	Genre Genre;
};

void ReadSongFromConsole(Song& song);
void WriteSongFromConsole(Song& song);