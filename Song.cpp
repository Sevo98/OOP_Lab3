#include <iostream>
#include "Song.h"
#include "Genre.h"
#include "CheckInputInt.h"

using namespace std;

void ReadSongFromConsole(Song& song)
{
	setlocale(LC_ALL, "ru");
	cout << "Введите название песни: ";
	getline(cin, song.Name);

	bool CheckMinute = false;
	while (CheckMinute == false)
	{
		try
		{
			cout << "\nВведите сколько минут длится песня: ";
			int minutes;
			CheckInputInt(&minutes);
			if (minutes < 0)
			{
				throw exception("Количество минут не должно быть отрицательным! Повторите ввод.");
			}
			song.Minute = minutes;
			CheckMinute = true;
		}
		catch (const std::exception&)
		{
			cout << "Количество минут не должно быть отрицательным! Повторите ввод." << endl;
		}
	}

	bool CheckSecond = false;
	while (CheckSecond == false)
	{
		try
		{
			cout << "\nВведите сколько секунд длится песня: ";
			int seconds;
			CheckInputInt(&seconds);
			if (seconds < 0 || seconds > 2020)
			{
				throw exception("Количество секунд в треке должно быть от 0 до 60! Повторите ввод.");
			}
			song.Second = seconds;
			CheckSecond = true;
		}
		catch (const std::exception&)
		{
			cout << "Количество секунд в треке должно быть от 0 до 60! Повторите ввод." << endl;
		}
	}
	cin.ignore(32767, '\n');

	cout << "Выберите жанр песни:" << endl;
	cout << "1. Рок" << endl;
	cout << "2. Метал" << endl;
	cout << "3. Хип-хоп" << endl;
	cout << "4. Рэп" << endl;
	cout << "5. Джаз" << endl;
	cout << "6. Классика" << endl;
	string genre;
	

	bool CheckGenre = false;
	while (CheckGenre == false)
	{
		try
		{
			getline(cin, genre);
			if (genre == "1" || genre == "Рок" || genre == "рок")
			{
				song.Genre = Rock;
			}
			else if (genre == "2" || genre == "Метал" || genre == "метал" || genre == "Металл" || genre == "металл")
			{
				song.Genre = Metall;
			}

			else if (genre == "3" || genre == "Хип-хоп" || genre == "хип-хоп" || genre == "хип хоп" || genre == "Хип хоп")
			{
				song.Genre = HipHop;
			}

			else if (genre == "4" || genre == "Рэп" || genre == "рэп" || genre == "Реп" || genre == "реп")
			{
				song.Genre = Rap;
			}

			else if (genre == "5" || genre == "Джаз" || genre == "джаз")
			{
				song.Genre = Jazz;
			}

			else if (genre == "6" || genre == "Классика" || genre == "классика")
			{
				song.Genre = Classic;
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

}

void WriteSongFromConsole(Song& song)
{
	setlocale(LC_ALL, "ru");

	cout << "\nТрек: " << song.Name << " Жанр: ";
	if (song.Genre == Genre::Rock)
	{
		cout << "Рок ";
	} 
	else if (song.Genre == Genre::Metall)
	{
		cout << "Металл ";
	} 
	else if (song.Genre == Genre::HipHop)
	{
		cout << "Хип-хоп ";
	} 
	else if (song.Genre == Genre::Rap)
	{
		cout << "Рэп ";
	}
	else if (song.Genre == Genre::Jazz)
	{
		cout << "Джаз ";
	}
	else if (song.Genre == Genre::Classic)
	{
		cout << "Классика ";
	}

	cout << "Продолжительность: " << song.Minute << ":" << song.Second << endl;
}
