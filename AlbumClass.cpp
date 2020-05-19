#include <iostream>
#include "AlbumClass.h"
#include "Genre.h"
#include "CheckInputInt.h"
using namespace std;

void AlbumClass::ReadAlbumFromConsole()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите название альбома: ";
	getline(cin, this->Name);

	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
		{
			cout << "Введите год выпуска: ";
			int year;
			CheckInputInt(&year);
			if (year < 0 || year > 2020)
			{
				throw exception("Неправильный год выпуска! Повторите ввод.");
			}
			this->Year = year;
			CheckYear = true;
		}
		catch (const std::exception&)
		{
			cout << "Неправильный год выпуска! Повторите ввод." << endl;
		}
	}

	bool CheckCountSongs = false;
	while (CheckCountSongs == false)
	{
		try
		{
			cout << "Введите количество песен в альбоме: ";
			int count;
			CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("Количество не может быть меньше 0! Повторите ввод.");
			}
			this->countSong = count;
			CheckCountSongs = true;
		}
		catch (const std::exception&)
		{
			cout << "Количество не может быть меньше 0! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Songs = new SongClass[this->countSong];
	for (int i = 0; i < this->countSong; i++)
	{
		cout << "Введите название песни №" << i + 1 << ":" << endl;
		this->Songs[i].ReadSongFromConsole();
	}

	for (int i = 0; i < this->countSong; i++)
	{
		if (this->Songs[i].Genre == Rock)
		{
			this->RockCount++;
		}
		if (this->Songs[i].Genre == Metall)
		{
			this->MetallCount++;
		}
		if (this->Songs[i].Genre == HipHop)
		{
			this->HipHopCount++;
		}
		if (this->Songs[i].Genre == Rap)
		{
			this->RapCount++;
		}
		if (this->Songs[i].Genre == Jazz)
		{
			this->JazzCount++;
		}
		if (this->Songs[i].Genre == Classic)
		{
			this->ClassicCount++;
		}
	}
}

void AlbumClass::WriteAlbumFromConsole()
{
	cout << "Альбом: " << this->Name << endl;
	cout << "Год выпуска: " << this->Year << endl;
	cout << "В состав альбома входит " << this->countSong << " треков:" << endl;

	for (int i = 0; i < this->countSong; i++)
	{
		cout << i + 1 << "-";
		this->Songs[i].WriteSongFromConsole();
	}
}
