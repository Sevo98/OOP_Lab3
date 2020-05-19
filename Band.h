#pragma once
#include <string>
#include "Song.h"
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
	int allSongsCount = 0;
	Song* AllSongsStorage;
	int AllRockCount = 0, AllMetallCount = 0, AllHipHopCount = 0, AllRapCount = 0, AllJazzCount = 0, AllClassicCount = 0;
	Song* RockStorage;
	Song* MetallStorage;
	Song* HipHopStorage;
	Song* RapStorage;
	Song* JazzStorage;
	Song* ClassicStorage;
};


void ReadBandFromConsole(Band& band);
void WriteBandFromConsole(Band& band);
Song* FindSong(Band& band, string songTitle);
Album* FindAlbum(Band& band, Song* song);
void GetAllSongs(Band& band);
void GetAllGenreSongs(Band& band, Genre findingGenre);

void DemoBand();