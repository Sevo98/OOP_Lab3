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

	for (int i = 0; i < band.countAlbums; i++)
	{
		band.AllRockCount = band.AllRockCount + band.Albums[i].RockCount;
		band.AllMetallCount = band.AllMetallCount + band.Albums[i].MetallCount;
		band.AllHipHopCount = band.AllHipHopCount + band.Albums[i].HipHopCount;
		band.AllRapCount = band.AllRapCount + band.Albums[i].RapCount;
		band.AllJazzCount = band.AllJazzCount + band.Albums[i].JazzCount;
		band.AllClassicCount = band.AllClassicCount + band.Albums[i].ClassicCount;
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

	band.RockStorage = new Song[band.AllRockCount];
	band.MetallStorage = new Song[band.AllMetallCount];
	band.HipHopStorage = new Song[band.AllHipHopCount];
	band.RapStorage = new Song[band.AllRapCount];
	band.JazzStorage = new Song[band.AllJazzCount];
	band.ClassicStorage = new Song[band.AllClassicCount];

	cout << "Выберите жанр для поиска:" << endl;
	cout << "1. Рок" << endl;
	cout << "2. Метал" << endl;
	cout << "3. Хип-хоп" << endl;
	cout << "4. Рэп" << endl;
	cout << "5. Джаз" << endl;
	cout << "6. Классика" << endl;
	string genre;
	Genre findGenre;

	bool CheckGenre = false;
	while (CheckGenre == false)
	{
		try
		{
			getline(cin, genre);
			if (genre == "1" || genre == "Рок" || genre == "рок")
			{
				findGenre = Rock;
			}
			else if (genre == "2" || genre == "Метал" || genre == "метал" || genre == "Металл" || genre == "металл")
			{
				findGenre = Metall;
			}

			else if (genre == "3" || genre == "Хип-хоп" || genre == "хип-хоп" || genre == "хип хоп" || genre == "Хип хоп")
			{
				findGenre = HipHop;
			}

			else if (genre == "4" || genre == "Рэп" || genre == "рэп" || genre == "Реп" || genre == "реп")
			{
				findGenre = Rap;
			}

			else if (genre == "5" || genre == "Джаз" || genre == "джаз")
			{
				findGenre = Jazz;
			}

			else if (genre == "6" || genre == "Классика" || genre == "классика")
			{
				findGenre = Classic;
			}
			else
			{
				throw exception("Данный жанр не найден! Повторите ввод.");
			}
			CheckGenre = true;

		}
		catch (const std::exception&)
		{
			cout << "Данный жанр не найден! Повторите ввод." << endl;
		}
	}
	
	cout << "Все песни данного жанра:" << endl;
	GetAllGenreSongs(band, findGenre);

	delete[] band.Members;
	delete[] band.Albums;
	delete[] band.AllSongsStorage;
	delete[] band.RockStorage;
	delete[] band.MetallStorage;
	delete[] band.HipHopStorage;
	delete[] band.RapStorage;
	delete[] band.JazzStorage;
	delete[] band.ClassicStorage;
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

void GetAllGenreSongs(Band& band, Genre findingGenre)
{
	int rockCount = 0;
	int metallCount = 0;
	int hiphopCount = 0;
	int rapCount = 0;
	int jazzCount = 0;
	int classicCount = 0;
	for (int i = 0; i < band.allSongsCount; i++)
	{
		if (band.AllSongsStorage[i].Genre == Rock)
		{
			band.RockStorage[rockCount] = band.AllSongsStorage[i];
			rockCount++;
		}
		
		if (band.AllSongsStorage[i].Genre == Metall)
		{
			band.MetallStorage[metallCount] = band.AllSongsStorage[i];
			metallCount++;
		}
		
		if (band.AllSongsStorage[i].Genre == HipHop)
		{
			band.HipHopStorage[hiphopCount] = band.AllSongsStorage[i];
			hiphopCount++;
		}
		
		if (band.AllSongsStorage[i].Genre == Rap)
		{
			band.RapStorage[rapCount] = band.AllSongsStorage[i];
			rapCount++;
		}
		
		if (band.AllSongsStorage[i].Genre == Jazz)
		{
			band.JazzStorage[jazzCount] = band.AllSongsStorage[i];
			jazzCount++;
		}
		
		if (band.AllSongsStorage[i].Genre == Classic)
		{
			band.ClassicStorage[classicCount] = band.AllSongsStorage[i];
			classicCount++;
		}
	}
	//поиск рока
	if (findingGenre == Rock && band.AllRockCount != 0)
	{
		for (int i = 0; i < band.AllRockCount; i++)
		{
			WriteSongFromConsole(band.RockStorage[i]);
		}
	}
	else if (findingGenre == Rock && band.AllRockCount == 0)
	{
		cout << "Песни в жанре Рок не найдены" << endl;
	}
	//поиск металла
	if (findingGenre == Metall && band.AllMetallCount != 0)
	{
		for (int i = 0; i < band.AllMetallCount; i++)
		{
			WriteSongFromConsole(band.MetallStorage[i]);
		}
	}
	else if (findingGenre == Metall && band.AllMetallCount == 0)
	{
		cout << "Песни в жанре Металл не найдены" << endl;
	}
	//поиск хип-хопа
	if (findingGenre == HipHop && band.AllHipHopCount != 0)
	{
		for (int i = 0; i < band.AllHipHopCount; i++)
		{
			WriteSongFromConsole(band.HipHopStorage[i]);
		}
	}
	else if (findingGenre == HipHop && band.AllHipHopCount == 0)
	{
		cout << "Песни в жанре Хип-хоп не найдены" << endl;
	}
	//поиск рэпа
	if (findingGenre == Rap && band.AllRapCount != 0)
	{
		for (int i = 0; i < band.AllRapCount; i++)
		{
			WriteSongFromConsole(band.RapStorage[i]);
		}
	}
	else if (findingGenre == Rap && band.AllRapCount == 0)
	{
		cout << "Песни в жанре Рэп не найдены" << endl;
	}
	//поиск джаза
	if (findingGenre == Jazz && band.AllJazzCount != 0)
	{
		for (int i = 0; i < band.AllJazzCount; i++)
		{
			WriteSongFromConsole(band.JazzStorage[i]);
		}
	}
	else if (findingGenre == Jazz && band.AllJazzCount == 0)
	{
		cout << "Песни в жанре Джаз не найдены" << endl;
	}
	//поиск классики
	if (findingGenre == Classic && band.AllClassicCount != 0)
	{
		for (int i = 0; i < band.AllClassicCount; i++)
		{
			WriteSongFromConsole(band.ClassicStorage[i]);
		}
	}
	else if (findingGenre == Classic && band.AllClassicCount == 0)
	{
		cout << "Песни в жанре Классика не найдены" << endl;
	}
}
