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
	for (size_t i = 0; i < band.countMembers; i++)
	{
		cout << "������� ��� " << i + 1 << "-�� ���������: ";
		getline(cin, band.Members[i]);
	}

	bool CheckCountAlbums = false;
	while (CheckCountAlbums == false)
	{
		try
		{
			cout << "������� �������� ������: ";
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

	Song* searchResult = FindSong(band, searchSong);
	if (searchResult == nullptr)
	{
		cout << "����� �� �������" << endl;
	}
	else
	{
		WriteSongFromConsole(*searchResult);
	}
	

	delete[] band.Members;
	delete[] band.Albums;
	//delete band.searchSongResult;
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