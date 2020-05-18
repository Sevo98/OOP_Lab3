#pragma once
#include <string>
#include "Song.h"

using namespace std;

struct Album
{
	string Name;
	int Year;
	int countSong = 0;
	Song* Songs;
	int RockCount = 0, MetallCount = 0, HipHopCount = 0, RapCount = 0, JazzCount = 0, ClassicCount = 0;
};

void ReadAlbumFromConsole(Album& album);
void WriteAlbumFromConsole(Album& album);