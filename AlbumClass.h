#pragma once
#include "SongClass.h"
#include <string>
using namespace std;

class AlbumClass
{
public:
	string Name;
	int Year;
	SongClass* Songs;
	int countSong = 0;
	int RockCount = 0, MetallCount = 0, HipHopCount = 0, RapCount = 0, JazzCount = 0, ClassicCount = 0;
	void ReadAlbumFromConsole();
	void WriteAlbumFromConsole();
};

