#include <iostream>
#include "Album.h"
#include "Band.h"
#include "CheckInputInt.h"

using namespace std;

void ReadBandFromConsole(Band& band)
{
	setlocale(LC_ALL, "ru");
	cout << "������� �������� ������: ";
	getline(cin, band.Name);
	cout << "������� ������� ��������, ������� ������:" << endl;
	getline(cin, band.History);

	bool CheckCountMembers = false;
	while (CheckCountMembers == false)
	{
		try
		{
			cout << "������� ���������� ���������� ������: ";
			int count;
			CheckInputInt(&count);
			if (count <= 0)
			{
				throw exception("���������� �� ����� ���� ������ ������! ��������� ����.");
			}
			band.countMembers = count;
			CheckCountMembers = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� �� ����� ���� ������ ������! ��������� ����." << endl;
		}
	}
	cin.ignore(32767, '\n');

	band.Members = new string[band.countMembers];
	for (int i = 0; i < band.countMembers; i++)
	{
		cout << "������� ��� " << i + 1 << "-�� ���������: ";
		getline(cin, band.Members[i]);
	}

	bool CheckCountAlbums = false;
	while (CheckCountAlbums == false)
	{
		try
		{
			cout << "������� ���������� �������� ������: ";
			int count;
			CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("���������� �� ����� ���� ������ 0! ��������� ����.");
			}
			band.countAlbums = count;
			CheckCountAlbums = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� �� ����� ���� ������ 0! ��������� ����." << endl;
		}
	}
	cin.ignore(32767, '\n');

	band.Albums = new Album[band.countAlbums];
	for (int i = 0; i < band.countAlbums; i++)
	{
		cout << "������� ������ " << i + 1 << "-�� �������:" << endl;
		ReadAlbumFromConsole(band.Albums[i]);
	}

}

void WriteBandFromConsole(Band& band)
{
	cout << "�������� ������: " << band.Name << endl;
	cout << "������� ������� ������:\n" << band.History << endl;
	cout << "������ ������� �� ";
	if (band.countMembers == 1)
	{
		cout << "������ ��������: " << band.Members[0] << endl;
	}
	else
	{
		cout << band.countMembers << " �������:" << endl;
		for (int i = 0; i < band.countMembers; i++)
		{
			cout << i + 1 << " - "<< band.Members[i] << endl;
		}
	}

	cout << "������ ����� ";
	if (band.countAlbums == 1)
	{
		cout << "���� ������: " << endl;
		WriteAlbumFromConsole(band.Albums[0]);
	}
	else
	{
		cout << band.countAlbums << " ��������:" << endl;
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

	cout << "������� �������� �����: ";
	string searchSong;
	getline(cin, searchSong);

	Song* searchResultSong = FindSong(band, searchSong);
	if (searchResultSong == nullptr)
	{
		cout << "����� �� �������" << endl;
	}
	else
	{
		WriteSongFromConsole(*searchResultSong);

		Album* searchResultAlbum = FindAlbum(band, searchResultSong);
		if (searchResultAlbum == nullptr)
		{
			cout << "������ � ������ �� ������." << endl;
		}
		else
		{
			cout << "����� " << searchSong << " ������� � �������:" << endl;
			WriteAlbumFromConsole(*searchResultAlbum);
		}
	}

	for (int i = 0; i < band.countAlbums; i++)
	{
		band.allSongsCount = band.allSongsCount + band.Albums[i].countSong;
	}
	
	band.AllSongsStorage = new Song[band.allSongsCount];
	GetAllSongs(band);
	cout << "����� � ������ " << band.Name << " " << band.allSongsCount << " �����. ��� ����� ������ ������:" << endl;
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

//���������� ���������� ��� ��������


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
