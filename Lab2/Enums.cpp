#include <iostream>
#include "Enums.h"
using namespace std;

//enum Colors
//{
//	Red,
//	Orange,
//	Yellow,
//	Green,
//	Azure,
//	Blue,
//	Purple
//};
//
//enum Week
//{
//	Monday,
//	Tuesday,
//	Wednesday,
//	Thursday,
//	Friday,
//	Saturday, 
//	Sunday
//};
//
//enum Genre
//{
//	Comedy,
//	Drama,
//	Thriller,
//	Action,
//	Horrors,
//	Blockbuster,
//	Criminal
//};
//
//enum StudyForm
//{
//	Intramural,
//	Extramural,
//	Evening,
//	Distance
//};
//
//enum Manufacturer
//{
//	Samsung,
//	Apple,
//	Xiaomi,
//	OnePlus
//};
//
//enum Season
//{
//	Winter,
//	Spring,
//	Summer,
//	Authumn
//};

//void WriteColors(Colors color);
//int CountRed(Colors* colors, int count);
//int CountColor(Colors* colors, int count, Colors paint);
//void DemoEnums();
//Colors ReadColor();
//
//void DemoEnums()
//{
//	Colors color = Orange;
//	Week day = Saturday;
//	Genre genres = Comedy;
//	StudyForm studyForm = Evening;
//	Manufacturer manufacturer = OnePlus;
//	Season season = Spring;
//
//	Colors StorColors[6]{Red,Orange,Yellow,Green,Blue,Purple};
//	Week Week[7]{ Monday,	Tuesday,	Wednesday,	Thursday,	Friday,	Saturday,	Sunday };
//	Genre StorGenres[4]{ Comedy,	Drama,	Thriller,	Action };
//	StudyForm StudyFormStorage[4]{ Intramural,	Extramural,	Evening,Distance };
//	Manufacturer StorManufacturer[4]{ Samsung,	Apple,	Xiaomi,	OnePlus };
//	Season Seasons[4]{ Winter,	Spring,	Summer,	Authumn };
//}
//
//void WriteColors(Colors color)
//{
//	Colors StorColors[6]{ Red,Orange,Yellow,Green,Blue,Purple };
//	for (int i = 0; i < 6; i++)
//	{
//		switch (color)
//		{
//			case Red:
//			{
//				cout << " расный цвет" << endl;
//				break;
//			} 
//			case Orange:
//			{
//				cout << "ќранжевый цвет" << endl;
//				break;
//			}
//			case Yellow:
//			{
//				cout << "∆елтый цвет" << endl;
//				break;
//			}
//			case Green:
//			{
//				cout << "«еленый цвет" << endl;
//				break;
//			}
//			case Blue:
//			{
//				cout << "—иний цвет" << endl;
//				break;
//			}
//			case Purple:
//			{
//				cout << "‘иолетовый цвет" << endl;
//				break;
//			}
//		}
//	}
//}
//
//Colors ReadColor()
//{
//	int color;
//	cout << "\n¬ведите число от 0 до 6 (0 Ц красный, 1 Ц оранжевый, 2 Ц желтый, 3 Ц зеленый, 4 Ц голубой, 5 Ц синий, 6 Ц фиолетовый): " << endl;
//	cin >> color;
//
//	Colors paint = (Colors)color;
//	return paint;
//}
//
//int CountRed(Colors* colors, int count)
//{
//	int value = 0;
//	for (int i = 0; i < count; i++)
//	{
//		if (colors[i]==Red)
//		{
//			value++;
//		}
//	}
//	return value;
//}
//
//int CountColor(Colors* colors, int count, Colors paint)
//{
//	int value = 0;
//	for (int i = 0; i < count; i++)
//	{
//		if (colors[i] == paint)
//		{
//			value++;
//		}
//	}
//	return value;
//}