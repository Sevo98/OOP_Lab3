#include <iostream>
#include "Album.h"
#include "Band.h"
#include "CheckInputInt.h"

using namespace std;

void ReadBandFromConsole(Band& band)
{
	setlocale(LC_ALL, "ru");
	cout << "Введите название группы: ";
	getline(cin, band.Name);
	cout << "Введите краткое описание, историю группы:" << endl;
	getline(cin, band.History);

	bool CheckCountMembers = false;
	while (CheckCountMembers == false)
	{
		try
		{
			cout << "Введите количество участников группы: ";
			int count;
			CheckInputInt(&count);
			if (count <= 0)
			{
				throw exception("Участников не может быть меньше одного! Повторите ввод.");
			}
			band.countMembers = count;
			CheckCountMembers = true;
		}
		catch (const std::exception&)
		{
			cout << "Участников не может быть меньше одного! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	band.Members = new string[band.countMembers];
	for (int i = 0; i < band.countMembers; i++)
	{
		cout << "Введите имя " << i + 1 << "-го участника: ";
		getline(cin, band.Members[i]);
	}

	bool CheckCountAlbums = false;
	while (CheckCountAlbums == false)
	{
		try
		{
			cout << "Введите количество альбомов группы: ";
			int count;
			CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("Количество не может быть меньше 0! Повторите ввод.");
			}
			band.countAlbums = count;
			CheckCountAlbums = true;
		}
		catch (const std::exception&)
		{
			cout << "Количество не может быть меньше 0! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	band.Albums = new Album[band.countAlbums];
	for (int i = 0; i < band.countAlbums; i++)
	{
		cout << "Введите данные " << i + 1 << "-го альбома:" << endl;
		ReadAlbumFromConsole(band.Albums[i]);
	}

}

void WriteBandFromConsole(Band& band)
{
	cout << "Название группы: " << band.Name << endl;
	cout << "Краткая история группы:\n" << band.History << endl;
	cout << "Группа состоит из ";
	if (band.countMembers == 1)
	{
		cout << "одного человека: " << band.Members[0] << endl;
	}
	else
	{
		cout << band.countMembers << " человек:" << endl;
		for (int i = 0; i < band.countMembers; i++)
		{
			cout << i + 1 << " - "<< band.Members[i] << endl;
		}
	}

	cout << "Группа имеет ";
	if (band.countAlbums == 1)
	{
		cout << "один альбом: " << endl;
		WriteAlbumFromConsole(band.Albums[0]);
	}
	else
	{
		cout << band.countAlbums << " альбомов:" << endl;
		for (int i = 0; i < band.countAlbums; i++)
		{
			WriteAlbumFromConsole(band.Albums[i]);
		}
	}

	
}

void DemoBand()
{
	Band band;
	ReadBandFromConsole(band);
	WriteBandFromConsole(band);

	cout << "Введите название песни: ";
	string searchSong;
	getline(cin, searchSong);

	Song* searchResultSong = FindSong(band, searchSong);
	if (searchResultSong == nullptr)
	{
		cout << "Песня не найдена" << endl;
	}
	else
	{
		WriteSongFromConsole(*searchResultSong);

		Album* searchResultAlbum = FindAlbum(band, searchResultSong);
		if (searchResultAlbum == nullptr)
		{
			cout << "Альбом с песней не найден." << endl;
		}
		else
		{
			cout << "Песня " << searchSong << " найдена в альбоме:" << endl;
			WriteAlbumFromConsole(*searchResultAlbum);
		}
	}

	for (int i = 0; i < band.countAlbums; i++)
	{
		band.allSongsCount = band.allSongsCount + band.Albums[i].countSong;
	}
	
	band.AllSongsStorage = new Song[band.allSongsCount];
	GetAllSongs(band);
	cout << "Всего у группы " << band.Name << " " << band.allSongsCount << " песен. Все песни данной группы:" << endl;
	for (int i = 0; i < band.allSongsCount; i++)
	{
		cout << i + 1 << " - ";
		WriteSongFromConsole(band.AllSongsStorage[i]);
	}


	delete[] band.Members;
	delete[] band.Albums;
	delete[] band.AllSongsStorage;
	delete searchResultSong;
}

Song* FindSong(Band& band, string songTitle)
{
	for (int i = 0; i < band.countAlbums; i++)
	{
		for (int j = 0; j < band.Albums[i].countSong; j++)
		{
			if (songTitle == band.Albums[i].Songs[j].Name)
			{
				band.searchSongResult = band.Albums[i].Songs[j];
				return &band.searchSongResult;
			}
		}
	}
	return nullptr;
}

Album* FindAlbum(Band& band, Song* song)
{
	for (int i = 0; i < band.countAlbums; i++)
	{
		for (int j = 0; j < band.Albums[i].countSong; j++)
		{
			if (song->Name == band.Albums[i].Songs[j].Name)
			{
				band.searchAlbumResult = band.Albums[i];
				return &band.searchAlbumResult;
			}
		}
	}
	return nullptr;
}

//глобальная переменная для счетчика


void GetAllSongs(Band& band)
{	
	int g = 0;
	for (int i = 0; i < band.countAlbums; i++)
	{
		for (int j = 0; j < band.Albums[i].countSong; j++)
		{
			band.AllSongsStorage[g] = band.Albums[i].Songs[j];
			g++;
		}
		
	}
	
}
