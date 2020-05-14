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
};


void ReadBandFromConsole(Band& band);
void WriteBandFromConsole(Band& band);

void DemoBand();