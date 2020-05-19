#include <iostream>
#include "BandClass.h"
#include "AlbumClass.h"
#include "SongClass.h"
#include "CheckInputInt.h"
using namespace std;


void BandClass::ReadBandFromConsole()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите название группы: ";
	getline(cin, this->Name);
	cout << "Введите краткое описание, историю группы:" << endl;
	getline(cin, this->History);

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
			this->countMembers = count;
			CheckCountMembers = true;
		}
		catch (const std::exception&)
		{
			cout << "Участников не может быть меньше одного! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Members = new string[this->countMembers];
	for (int i = 0; i < this->countMembers; i++)
	{
		cout << "Введите имя " << i + 1 << "-го участника: ";
		getline(cin, this->Members[i]);
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
			this->countAlbums = count;
			CheckCountAlbums = true;
		}
		catch (const std::exception&)
		{
			cout << "Количество не может быть меньше 0! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Albums = new AlbumClass[this->countAlbums];
	for (int i = 0; i < this->countAlbums; i++)
	{
		cout << "Введите данные " << i + 1 << "-го альбома:" << endl;
		this->Albums[i].ReadAlbumFromConsole();
	}
}

void BandClass::WriteBandFromConsole()
{
	cout << "Название группы: " << this->Name << endl;
	cout << "Краткая история группы:\n" << this->History << endl;
	cout << "Группа состоит из ";
	if (this->countMembers == 1)
	{
		cout << "одного человека: " << this->Members[0] << endl;
	}
	else
	{
		cout << this->countMembers << " человек:" << endl;
		for (int i = 0; i < this->countMembers; i++)
		{
			cout << i + 1 << " - " << this->Members[i] << endl;
		}
	}

	cout << "Группа имеет ";
	if (this->countAlbums == 1)
	{
		cout << "один альбом: " << endl;
		this->Albums[0].WriteAlbumFromConsole();
	}
	else
	{
		cout << this->countAlbums << " альбомов:" << endl;
		for (int i = 0; i < this->countAlbums; i++)
		{
			this->Albums[i].WriteAlbumFromConsole();
		}
	}

	for (int i = 0; i < this->countAlbums; i++)
	{
		this->AllRockCount = this->AllRockCount + this->Albums[i].RockCount;
		this->AllMetallCount = this->AllMetallCount + this->Albums[i].MetallCount;
		this->AllHipHopCount = this->AllHipHopCount + this->Albums[i].HipHopCount;
		this->AllRapCount = this->AllRapCount + this->Albums[i].RapCount;
		this->AllJazzCount = this->AllJazzCount + this->Albums[i].JazzCount;
		this->AllClassicCount = this->AllClassicCount + this->Albums[i].ClassicCount;
	}
}

SongClass* BandClass::FindSong(string songTitle)
{
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			if (songTitle == this->Albums[i].Songs[j].Name)
			{
				this->searchSongResult = this->Albums[i].Songs[j];
				return &this->searchSongResult;
			}
		}
	}
	return nullptr;
}

AlbumClass* BandClass::FindAlbum(SongClass* song)
{
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			if (song->Name == this->Albums[i].Songs[j].Name)
			{
				this->searchAlbumResult = this->Albums[i];
				return &this->searchAlbumResult;
			}
		}
	}
	return nullptr;
}

void BandClass::GetAllSongs()
{
	int g = 0;
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			this->AllSongsStorage[g] = this->Albums[i].Songs[j];
			g++;
		}
	}
}

void BandClass::GetAllGenreSongs(Genre findingGenre)
{
	int rockCount = 0;
	int metallCount = 0;
	int hiphopCount = 0;
	int rapCount = 0;
	int jazzCount = 0;
	int classicCount = 0;
	for (int i = 0; i < this->allSongsCount; i++)
	{
		if (this->AllSongsStorage[i].Genre == Rock)
		{
			this->RockStorage[rockCount] = this->AllSongsStorage[i];
			rockCount++;
		}

		if (this->AllSongsStorage[i].Genre == Metall)
		{
			this->MetallStorage[metallCount] = this->AllSongsStorage[i];
			metallCount++;
		}

		if (this->AllSongsStorage[i].Genre == HipHop)
		{
			this->HipHopStorage[hiphopCount] = this->AllSongsStorage[i];
			hiphopCount++;
		}

		if (this->AllSongsStorage[i].Genre == Rap)
		{
			this->RapStorage[rapCount] = this->AllSongsStorage[i];
			rapCount++;
		}

		if (this->AllSongsStorage[i].Genre == Jazz)
		{
			this->JazzStorage[jazzCount] = this->AllSongsStorage[i];
			jazzCount++;
		}

		if (this->AllSongsStorage[i].Genre == Classic)
		{
			this->ClassicStorage[classicCount] = this->AllSongsStorage[i];
			classicCount++;
		}
	}
	//поиск рока
	if (findingGenre == Rock && this->AllRockCount != 0)
	{
		for (int i = 0; i < this->AllRockCount; i++)
		{
			this->RockStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Rock && this->AllRockCount == 0)
	{
		cout << "Песни в жанре Рок не найдены" << endl;
	}
	//поиск металла
	if (findingGenre == Metall && this->AllMetallCount != 0)
	{
		for (int i = 0; i < this->AllMetallCount; i++)
		{
			this->MetallStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Metall && this->AllMetallCount == 0)
	{
		cout << "Песни в жанре Металл не найдены" << endl;
	}
	//поиск хип-хопа
	if (findingGenre == HipHop && this->AllHipHopCount != 0)
	{
		for (int i = 0; i < this->AllHipHopCount; i++)
		{
			this->HipHopStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == HipHop && this->AllHipHopCount == 0)
	{
		cout << "Песни в жанре Хип-хоп не найдены" << endl;
	}
	//поиск рэпа
	if (findingGenre == Rap && this->AllRapCount != 0)
	{
		for (int i = 0; i < this->AllRapCount; i++)
		{
			this->RapStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Rap && this->AllRapCount == 0)
	{
		cout << "Песни в жанре Рэп не найдены" << endl;
	}
	//поиск джаза
	if (findingGenre == Jazz && this->AllJazzCount != 0)
	{
		for (int i = 0; i < this->AllJazzCount; i++)
		{
			this->JazzStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Jazz && this->AllJazzCount == 0)
	{
		cout << "Песни в жанре Джаз не найдены" << endl;
	}
	//поиск классики
	if (findingGenre == Classic && this->AllClassicCount != 0)
	{
		for (int i = 0; i < this->AllClassicCount; i++)
		{
			this->ClassicStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Classic && this->AllClassicCount == 0)
	{
		cout << "Песни в жанре Классика не найдены" << endl;
	}
}

void BandClass::DemoBand()
{
	ReadBandFromConsole();
	WriteBandFromConsole();

	cout << "Введите название песни: ";
	string searchSong;
	getline(cin, searchSong);

	SongClass* searchResultSong = FindSong(searchSong);
	if (searchResultSong == nullptr)
	{
		cout << "Песня не найдена" << endl;
	}
	else
	{
		searchResultSong->WriteSongFromConsole();

		AlbumClass *searchResultAlbum = FindAlbum(searchResultSong);
		if (searchResultAlbum == nullptr)
		{
			cout << "Альбом с песней не найден." << endl;
		}
		else
		{
			cout << "Песня " << searchSong << " найдена в альбоме:" << endl;
			searchResultAlbum->WriteAlbumFromConsole();
		}
	}

	for (int i = 0; i < this->countAlbums; i++)
	{
		this->allSongsCount = this->allSongsCount + this->Albums[i].countSong;
	}

	this->AllSongsStorage = new SongClass[this->allSongsCount];
	GetAllSongs();
	cout << "Всего у группы " << this->Name << " " << this->allSongsCount << " песен. Все песни данной группы:" << endl;
	for (int i = 0; i < this->allSongsCount; i++)
	{
		cout << i + 1 << " - ";
		this->AllSongsStorage[i].WriteSongFromConsole();
	}

	this->RockStorage = new SongClass[this->AllRockCount];
	this->MetallStorage = new SongClass[this->AllMetallCount];
	this->HipHopStorage = new SongClass[this->AllHipHopCount];
	this->RapStorage = new SongClass[this->AllRapCount];
	this->JazzStorage = new SongClass[this->AllJazzCount];
	this->ClassicStorage = new SongClass[this->AllClassicCount];

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
	GetAllGenreSongs(findGenre);

	delete[] this->Members;
	delete[] this->Albums;
	delete[] this->AllSongsStorage;
	delete[] this->RockStorage;
	delete[] this->MetallStorage;
	delete[] this->HipHopStorage;
	delete[] this->RapStorage;
	delete[] this->JazzStorage;
	delete[] this->ClassicStorage;
	delete searchResultSong;
}