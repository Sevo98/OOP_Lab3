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
};

void ReadAlbumFromConsole(Album& album);
void WriteAlbumFromConsole(Album& album);