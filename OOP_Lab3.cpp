#include <iostream>
#include <Windows.h>
#include "Book.h"
#include "Route.h"
#include "CheckInputInt.h"
#include "CheckInputDouble.h"
#include "Rectangles.h"
#include "Flight.h"
#include "Album.h"
#include "Band.h"
#include "RectangleClass.h"
#include "FlightClass.h"
#include "BandClass.h"
#include "Point3D.h"
#include "Polygon.h"
#include "Models3D.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");
	
	while (true)
 {
		int number = 0; 
		cout << "Введите от 1 до 5" << endl;
		cout << "1. Структуры с полями-массивами" << endl;
		cout << "2. Агрегирование" << endl;
		cout << "3. Агрегирование один ко многим" << endl;
		cout << "4. Классы" << endl;
		cout << "5. Индивидуальное задание" << endl;
		CheckInputInt(&number);
		switch (number)
		{
			case 1:
			{
				while (true)
				{
					int number = 0;
					cout << "Введите от 1 до 3" << endl;
					cout << "1. Задание 3.2.1, создание структуры Book" << endl;
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
			case 5:
			{
				const int coutPolygons = 1;
				Polygons* polygons[coutPolygons];
				for (int i = 0; i < coutPolygons; i++)
				{
					cout << "Создание " << i + 1 << " полигона." << endl;
					double X, Y, Z;
					cout << "Введите координаты для первой точки:" << endl;
					cout << "Введите координаты Х: ";
					CheckInputDouble(&X);
					cout << "Введите координаты Y: ";
					CheckInputDouble(&Y);
					cout << "Введите координаты Z: ";
					CheckInputDouble(&Z);
					Point3D point1 = Point3D(X, Y, Z);

					cout << "Введите координаты для второй точки:" << endl;
					cout << "Введите координаты Х: ";
					CheckInputDouble(&X);
					cout << "Введите координаты Y: ";
					CheckInputDouble(&Y);
					cout << "Введите координаты Z: ";
					CheckInputDouble(&Z);
					Point3D point2 = Point3D(X, Y, Z);

					cout << "Введите координаты для третьей точки:" << endl;
					cout << "Введите координаты Х: ";
					CheckInputDouble(&X);
					cout << "Введите координаты Y: ";
					CheckInputDouble(&Y);
					cout << "Введите координаты Z: ";
					CheckInputDouble(&Z);
					Point3D point3 = Point3D(X, Y, Z);

					polygons[i] = new Polygons(point1, point2, point3);
				}

				Models3D Model = Models3D(*polygons, coutPolygons);

				cout << "Модель имеет координаты полигонов:" << endl;
				Polygons* tempPolygon = Model.GetPolygons();
				for (int i = 0; i < coutPolygons; i++)
				{
					Point3D point1, point2, point3;
					point1 = tempPolygon->GetPoint1();
					point2 = tempPolygon->GetPoint2();
					point3 = tempPolygon->GetPoint3();
					double X1, Y1, Z1, X2, Y2, Z2, X3, Y3, Z3;
					X1 = point1.GetX();
					Y1 = point1.GetY();
					Z1 = point1.GetZ();

					X2 = point2.GetX();
					Y2 = point2.GetY();
					Z2 = point2.GetZ();

					X3 = point3.GetX();
					Y3 = point3.GetY();
					Z3 = point3.GetZ();
					cout << "Координаты " << i + 1 << "-го полигона:" << endl;
					cout << "Точка 1: " << X1 << ", " << Y1 << ", " << Z1 << endl;
					cout << "Точка 2: " << X1 << ", " << Y2 << ", " << Z2 << endl;
					cout << "Точка 3: " << X3 << ", " << Y3 << ", " << Z3 << endl;
				}

				
			} break;

		}
	}
	//DemoRoute();
    //DemoBook();
	
	/*Book book;
	ReadBookFromConsole(book);
	WriteBookFromConsole(book);*/
}
