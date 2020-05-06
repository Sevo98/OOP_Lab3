#include <iostream>
#include <Windows.h>
#include "Book.h"
#include "Route.h"
#include "CheckInputInt.h"
#include "Point.h"
#include "Rectangles.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");

	DemoRectangleWithPoint();

	while (true)
	{
		int number = 0; 
		cout << "Введите от 1 до …" << endl;
		cout << "1. Структуры с полями-массивами" << endl;
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
				} break;
		}
	}

	//DemoRoute();
    //DemoBook();
	

	/*Book book;
	ReadBookFromConsole(book);
	WriteBookFromConsole(book);*/

}
