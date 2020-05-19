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

	band.RockStorage = new Song[band.AllRockCount];
	band.MetallStorage = new Song[band.AllMetallCount];
	band.HipHopStorage = new Song[band.AllHipHopCount];
	band.RapStorage = new Song[band.AllRapCount];
	band.JazzStorage = new Song[band.AllJazzCount];
	band.ClassicStorage = new Song[band.AllClassicCount];

	cout << "�������� ���� ��� ������:" << endl;
	cout << "1. ���" << endl;
	cout << "2. �����" << endl;
	cout << "3. ���-���" << endl;
	cout << "4. ���" << endl;
	cout << "5. ����" << endl;
	cout << "6. ��������" << endl;
	string genre;
	Genre findGenre;

	bool CheckGenre = false;
	while (CheckGenre == false)
	{
		try
		{
			getline(cin, genre);
			if (genre == "1" || genre == "���" || genre == "���")
			{
				findGenre = Rock;
			}
			else if (genre == "2" || genre == "�����" || genre == "�����" || genre == "������" || genre == "������")
			{
				findGenre = Metall;
			}

			else if (genre == "3" || genre == "���-���" || genre == "���-���" || genre == "��� ���" || genre == "��� ���")
			{
				findGenre = HipHop;
			}

			else if (genre == "4" || genre == "���" || genre == "���" || genre == "���" || genre == "���")
			{
				findGenre = Rap;
			}

			else if (genre == "5" || genre == "����" || genre == "����")
			{
				findGenre = Jazz;
			}

			else if (genre == "6" || genre == "��������" || genre == "��������")
			{
				findGenre = Classic;
			}
			else
			{
				throw exception("������ ���� �� ������! ��������� ����.");
			}
			CheckGenre = true;

		}
		catch (const std::exception&)
		{
			cout << "������ ���� �� ������! ��������� ����." << endl;
		}
	}
	
	cout << "��� ����� ������� �����:" << endl;
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
	//����� ����
	if (findingGenre == Rock && band.AllRockCount != 0)
	{
		for (int i = 0; i < band.AllRockCount; i++)
		{
			WriteSongFromConsole(band.RockStorage[i]);
		}
	}
	else if (findingGenre == Rock && band.AllRockCount == 0)
	{
		cout << "����� � ����� ��� �� �������" << endl;
	}
	//����� �������
	if (findingGenre == Metall && band.AllMetallCount != 0)
	{
		for (int i = 0; i < band.AllMetallCount; i++)
		{
			WriteSongFromConsole(band.MetallStorage[i]);
		}
	}
	else if (findingGenre == Metall && band.AllMetallCount == 0)
	{
		cout << "����� � ����� ������ �� �������" << endl;
	}
	//����� ���-����
	if (findingGenre == HipHop && band.AllHipHopCount != 0)
	{
		for (int i = 0; i < band.AllHipHopCount; i++)
		{
			WriteSongFromConsole(band.HipHopStorage[i]);
		}
	}
	else if (findingGenre == HipHop && band.AllHipHopCount == 0)
	{
		cout << "����� � ����� ���-��� �� �������" << endl;
	}
	//����� ����
	if (findingGenre == Rap && band.AllRapCount != 0)
	{
		for (int i = 0; i < band.AllRapCount; i++)
		{
			WriteSongFromConsole(band.RapStorage[i]);
		}
	}
	else if (findingGenre == Rap && band.AllRapCount == 0)
	{
		cout << "����� � ����� ��� �� �������" << endl;
	}
	//����� �����
	if (findingGenre == Jazz && band.AllJazzCount != 0)
	{
		for (int i = 0; i < band.AllJazzCount; i++)
		{
			WriteSongFromConsole(band.JazzStorage[i]);
		}
	}
	else if (findingGenre == Jazz && band.AllJazzCount == 0)
	{
		cout << "����� � ����� ���� �� �������" << endl;
	}
	//����� ��������
	if (findingGenre == Classic && band.AllClassicCount != 0)
	{
		for (int i = 0; i < band.AllClassicCount; i++)
		{
			WriteSongFromConsole(band.ClassicStorage[i]);
		}
	}
	else if (findingGenre == Classic && band.AllClassicCount == 0)
	{
		cout << "����� � ����� �������� �� �������" << endl;
	}
}
