#include <iostream>
#include "Album.h"
#include "Song.h"
#include "Genre.h"
#include "CheckInputInt.h"

using namespace std;

void ReadAlbumFromConsole(Album& album)
{
	setlocale(LC_ALL, "ru");
	cout << "������� �������� �������: ";
	getline(cin, album.Name);

	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
		{
			cout << "������� ��� �������: ";
			int year;
			CheckInputInt(&year);
			if (year < 0 || year > 2020)
			{
				throw exception("������������ ��� �������! ��������� ����.");
			}
			album.Year = year;
			CheckYear = true;
		}
		catch (const std::exception&)
		{
			cout << "������������ ��� �������! ��������� ����." << endl;
		}
	}

	bool CheckCountSongs = false;
	while (CheckCountSongs == false)
	{
		try
		{
			cout << "������� ���������� ����� � �������: ";
			int count;
			CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("���������� �� ����� ���� ������ 0! ��������� ����.");
			}
			album.countSong = count;
			CheckCountSongs = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� �� ����� ���� ������ 0! ��������� ����." << endl;
		}
	}
	cin.ignore(32767, '\n');

	album.Songs = new Song[album.countSong];
	for (int i = 0; i < album.countSong; i++)
	{
		cout << "������� �������� ����� �" << i + 1 << ":" << endl;
		ReadSongFromConsole(album.Songs[i]);
	}
	
}

void WriteAlbumFromConsole(Album& album)
{
	cout << "������: " << album.Name << endl;
	cout << "��� �������: " << album.Year << endl;
	cout << "� ������ ������� ������ " << album.countSong << " ������:" << endl;

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


