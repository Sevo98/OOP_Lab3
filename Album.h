#pragma once
#include <string>
#include "Song.h"

using namespace std;

struct Album
{
	string Name;
	int Year;
	int countSong;
	Song* Songs;// = new Song[countSong];

};

void ReadAlbumFromConsole(Album& album);
void WriteAlbumFromConsole(Album& album);

void DemoAlbum();