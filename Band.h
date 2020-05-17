#pragma once
#include <string>
#include "Song.h"
#include "Band.h"
#include "Album.h"

using namespace std;

struct Band
{
	string Name;
	string History;
	int countMembers;
	string* Members;
	int countAlbums;
	Album* Albums;
	Song searchSongResult;
	Album searchAlbumResult;
};


void ReadBandFromConsole(Band& band);
void WriteBandFromConsole(Band& band);
Song* FindSong(Band& band, string songTitle);
Album* FindAlbum(Band& band, Song* song);

void DemoBand();