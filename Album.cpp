#include <iostream>
#include "Album.h"
#include "Song.h"
#include "Genre.h"
#include "CheckInputInt.h"

using namespace std;

void ReadAlbumFromConsole(Album& album)
{
	setlocale(LC_ALL, "ru");
	cout << "Введите название альбома: ";
	getline(cin, album.Name);

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
			album.Year = year;
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
			album.countSong = count;
			CheckCountSongs = true;
		}
		catch (const std::exception&)
		{
			cout << "Количество не может быть меньше 0! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	album.Songs = new Song[album.countSong];
	for (int i = 0; i < album.countSong; i++)
	{
		cout << "Введите название песни №" << i + 1 << ":" << endl;
		ReadSongFromConsole(album.Songs[i]);
	}
	
}

void WriteAlbumFromConsole(Album& album)
{
	cout << "Альбом: " << album.Name << endl;
	cout << "Год выпуска: " << album.Year << endl;
	cout << "В состав альбома входит " << album.countSong << " треков:" << endl;

	for (int i = 0; i < album.countSong; i++)
	{
		cout << i + 1 << "-";
		WriteSongFromConsole(album.Songs[i]);
	}

	
}

void DemoAlbum()
{
	Album album;
	ReadAlbumFromConsole(album);
	WriteAlbumFromConsole(album);
	delete[] album.Songs;
}


