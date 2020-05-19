#include <iostream>
#include <Windows.h>
#include "Book.h"
#include "Route.h"
#include "CheckInputInt.h"
#include "Rectangles.h"
#include "Flight.h"
#include "Album.h"
#include "Band.h"
#include "RectangleClass.h"
#include "FlightClass.h"
#include "BandClass.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");
	
	while (true)
 {
		int number = 0; 
		cout << "Введите от 1 до 4" << endl;
		cout << "1. Структуры с полями-массивами" << endl;
		cout << "2. Агрегирование" << endl;
		cout << "3. Агрегирование один ко многим" << endl;
		cout << "4. Классы" << endl;
		CheckInputInt(&number);
		switch (number)
		{
			case 1:
			{
				while (true)
				{
					int number = 0;
					cout << "Введите от 1 до 3" << endl;
					cout << "1. Задание 3.2.1, создание стуктуры Book" << endl;
					cout << "2. Задания 3.2.2-3.2.5, работа с функциями Book.h" << endl;
					cout << "3. Задание 3.2.6, работа с Route" << endl;
					CheckInputInt(&number);
					switch (number)
					{
						//3.2.1
					case 1:
						{
							Book book;
							ReadBookFromConsole(book);
							WriteBookFromConsole(book);
						} break;
					//3.2.2-3.2.5
					case 2:
						{
						DemoBook();
						} break;
						//3.2.6
					case 3:
						{
						DemoRoute();
						} break;
					}
				} break;
			}
			case 2:
			{
				while (true)
				{
					int number = 0;
					cout << "Введите от 1 до .." << endl;
					cout << "1. Задание 3.3.4-3.3.5, структура Rectangle" << endl;
					cout << "2. Задание 3.3.7-3.3.11, структура Flight" << endl;
					CheckInputInt(&number);
					switch (number)
					{
						//3.3.4-3.3.5
					case 1:
						{
							DemoRectangleWithPoint();
						} break;
					//
					case 2:
						{
							DemoFlightWithTime();
						} break;
					} break;
				}
			}
			case 3: 
			{
				DemoBand();
			} break;
			case 4:
			{
				while (true)
				{
					int number = 0;
					cout << "Введите от 1 до 3" << endl;
					cout << "1. Класс Rectangle" << endl;
					cout << "2. Класс Flight" << endl;
					cout << "3. Класс Band" << endl;
					CheckInputInt(&number);
					switch (number)
					{
						case 1:
						{
							RectangleClass Rectangle;
							Rectangle.DemoRectangleWithPoint();
						} break;

						case 2:
						{
							FlightClass Flight;
							Flight.DemoFlightWithTime();
						} break;
						case 3: 
						{
							BandClass band;
							band.DemoBand();
						} break;
					} break;
				}
			}
		}
	}
	//DemoRoute();
    //DemoBook();
	
	/*Book book;
	ReadBookFromConsole(book);
	WriteBookFromConsole(book);*/
}
