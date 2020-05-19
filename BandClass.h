#pragma once
#include <string>
#include "AlbumClass.h"
#include "SongClass.h"
using namespace std;

class BandClass
{
	string Name;
	string History;
	int countMembers;
	string* Members;
	int countAlbums;
	AlbumClass* Albums;
	SongClass searchSongResult;
	AlbumClass searchAlbumResult;
	int allSongsCount = 0;
	SongClass* AllSongsStorage;
	int AllRockCount = 0, AllMetallCount = 0, AllHipHopCount = 0, AllRapCount = 0, AllJazzCount = 0, AllClassicCount = 0;
	SongClass* RockStorage;
	SongClass* MetallStorage;
	SongClass* HipHopStorage;
	SongClass* RapStorage;
	SongClass* JazzStorage;
	SongClass* ClassicStorage;

public:
	void ReadBandFromConsole();
	void WriteBandFromConsole();
	SongClass* FindSong(string songTitle);
	AlbumClass* FindAlbum(SongClass* song);
	void GetAllSongs();
	void GetAllGenreSongs(Genre findingGenre);

	void DemoBand();
};

