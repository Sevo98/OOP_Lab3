#include <iostream>
#include "Song.h"
#include "Genre.h"
#include "CheckInputInt.h"

using namespace std;

void ReadSongFromConsole(Song& song)
{
	setlocale(LC_ALL, "ru");
	cout << "������� �������� �����: ";
	getline(cin, song.Name);

	bool CheckMinute = false;
	while (CheckMinute == false)
	{
		try
		{
			cout << "\n������� ������� ����� ������ �����: ";
			int minutes;
			CheckInputInt(&minutes);
			if (minutes < 0)
			{
				throw exception("���������� ����� �� ������ ���� �������������! ��������� ����.");
			}
			song.Minute = minutes;
			CheckMinute = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� ����� �� ������ ���� �������������! ��������� ����." << endl;
		}
	}

	bool CheckSecond = false;
	while (CheckSecond == false)
	{
		try
		{
			cout << "\n������� ������� ������ ������ �����: ";
			int seconds;
			CheckInputInt(&seconds);
			if (seconds < 0 || seconds > 2020)
			{
				throw exception("���������� ������ � ����� ������ ���� �� 0 �� 60! ��������� ����.");
			}
			song.Second = seconds;
			CheckSecond = true;
		}
		catch (const std::exception&)
		{
			cout << "���������� ������ � ����� ������ ���� �� 0 �� 60! ��������� ����." << endl;
		}
	}
	cin.ignore(32767, '\n');

	cout << "�������� ���� �����:" << endl;
	cout << "1. ���" << endl;
	cout << "2. �����" << endl;
	cout << "3. ���-���" << endl;
	cout << "4. ���" << endl;
	cout << "5. ����" << endl;
	cout << "6. ��������" << endl;
	string genre;
	

	bool CheckGenre = false;
	while (CheckGenre == false)
	{
		try
		{
			getline(cin, genre);
			if (genre == "1" || genre == "���" || genre == "���")
			{
				song.Genre = Rock;
			}
			else if (genre == "2" || genre == "�����" || genre == "�����" || genre == "������" || genre == "������")
			{
				song.Genre = Metall;
			}

			else if (genre == "3" || genre == "���-���" || genre == "���-���" || genre == "��� ���" || genre == "��� ���")
			{
				song.Genre = HipHop;
			}

			else if (genre == "4" || genre == "���" || genre == "���" || genre == "���" || genre == "���")
			{
				song.Genre = Rap;
			}

			else if (genre == "5" || genre == "����" || genre == "����")
			{
				song.Genre = Jazz;
			}

			else if (genre == "6" || genre == "��������" || genre == "��������")
			{
				song.Genre = Classic;
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

}

void WriteSongFromConsole(Song& song)
{
	setlocale(LC_ALL, "ru");

	cout << "\n����: " << song.Name << " ����: ";
	if (song.Genre == Genre::Rock)
	{
		cout << "��� ";
	} 
	else if (song.Genre == Genre::Metall)
	{
		cout << "������ ";
	} 
	else if (song.Genre == Genre::HipHop)
	{
		cout << "���-��� ";
	} 
	else if (song.Genre == Genre::Rap)
	{
		cout << "��� ";
	}
	else if (song.Genre == Genre::Jazz)
	{
		cout << "���� ";
	}
	else if (song.Genre == Genre::Classic)
	{
		cout << "�������� ";
	}

	cout << "�����������������: " << song.Minute << ":" << song.Second << endl;
}
