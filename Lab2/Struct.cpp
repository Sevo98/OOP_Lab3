#include <iostream>
#include "Struct.h"

using namespace std;

void Exchange(Rectangle& rectangle1, Rectangle& rectangle2);
void FindRectangle(Rectangle* rectangles, int count);
void FindMaxRectangle(Rectangle* rectangles, int count);
void FindShorterFlights(Flight* flights, int count);

Rectangle* MakeRectangle(double lenght, double width, string color);
Rectangle* CopyRectangle(Rectangle rectangles);

Flight* MakeFlight(string DepaturePoint, string Destination, int DurationTimeMin);
Flight* CopyFlight(Flight flights);

Movie* MakeMovie(string Title, string Genre, int YeasIssue, int DurationTimeMin, double Rating);
Movie* CopyMovie(Movie movies);

Time* MakeTime(int Hour, int Min, int Sec);
Time* CopyTime(Time times);

struct Rectangle
{
	double length = 0, width = 0;
	string color = "";
};

struct Flight
{
	string DeparturePoint = "", Destination = "";
	int DurationTimeMin = 0;
};

struct Movie
{
	string Title = "", Genre = "";
	int YearIssue = 0, DurationMovieMin = 0;
	double Rating = 0;
};

struct Time
{
	int Hour = 0, Min = 0, Sec = 0;
};

struct Contact
{
	string Name = "", Email = "", AddInf = "";
	int Number = 0;
};

struct Song
{
	string SongName = "", Artist = "";
	int DurationSongSec = 0;
};

struct Discipline
{
	string NameDiscipline = "", TeacherName = "";
	int DurationDispH = 0, StudRating = 0;
};

void DemoRectangle()
{	
	while (true)
	{
		int value = 0;

		cout << "1. Задание 2.2.3.1, 2.2.3.2, 2.2.4.1 и 2.2.4.2" << endl;
		cout << "2. Задание 2.2.3.3, 2.2.5.5 и 2.2.5.6" << endl;
		cout << "3. Задание 2.2.5.4" << endl;
		cout << "4. Задания 2.2.7.2 и 2.2.7.3" << endl;

		cin >> value;

		switch (value)
		{
		case 1: 
			{
				Rectangle NewRectangle;

				cout << "Введите длину прямоугольника (положительное число):" << endl;
				cin >> NewRectangle.length;
				cout << "\nВведите ширину прямоугольника (положительное число):" << endl;
				cin >> NewRectangle.width;
				
				cout << "\nПрямоугольник имеет размеры: " << NewRectangle.length << "X" << NewRectangle.width << endl;

				//2.2.4.1
				Rectangle* FirstPointer;
				FirstPointer = &NewRectangle;

				cout << "2.2.4.1 \nПрямоугольник имеет размеры: " 
					<< FirstPointer->length << "X" << FirstPointer->width 
					<< "\nПрямоугольник имеет цвет: " << FirstPointer->color << endl;

				Rectangle* SecondPointer;
				SecondPointer = &NewRectangle;

				cout << "Значение первого указателя: " << FirstPointer << "\nЗначение второго указателя: " << SecondPointer << endl;

				delete FirstPointer, SecondPointer;
				 
				 
			} break;
		case 2:
			{
			int size;
			cout << "Введите размер массива: ";
			cin >> size;
			Rectangle* StorRectangle = new Rectangle[size];
			
			for (int i = 0; i < size; i++)
			{
				cout << "Введите длину " << i+1 << "-го" << " прямоугольника (положительное число):" << endl;
				cin >> StorRectangle[i].length;
				cout << "\nВведите ширину " << i+1 << "-го" << " прямоугольника (положительное число):" << endl;
				cin >> StorRectangle[i].width;
			}
			for (int i = 0; i < size; i++)
			{
				cout << "\nПрямоугольник " << i+1 << " имеет размеры: " << StorRectangle[i].length << "X" << StorRectangle[i].width << endl;
			}

			FindRectangle(StorRectangle, size);
			FindMaxRectangle(StorRectangle, size);

			delete[] StorRectangle;
			 
			 
			} break;

		case 3:
			{
			int size = 2;
			Rectangle* rectangle = new Rectangle[size];

			for (int i = 0; i < 2; i++)
			{
				cout << "Введите длину " << i+1 << "-го" << " прямоугольника (положительное число):" << endl;
				cin >> rectangle[i].length;
				cout << "\nВведите ширину " << i + 1 << "-го" << " прямоугольника (положительное число):" << endl;
				cin >> rectangle[i].width;
			}
			
			for (int i = 0; i < 2; i++)
			{
				cout << "\nПрямоугольник " << i + 1 << " имеет размеры: " << rectangle[i].length << "X" << rectangle[i].width << endl;
			}
			Exchange(rectangle[0], rectangle[1]);

			for (int i = 0; i < 2; i++)
			{
				cout << "\nПрямоугольник " << i + 1 << " имеет размеры: " << rectangle[i].length << "X" << rectangle[i].width << endl;
			}
			delete[] rectangle;
			 
			 
			} break;

		case 4:
			{
			Rectangle* rectangle1 = MakeRectangle(4.7, 5, "Black");
			Rectangle* rectangle2 = MakeRectangle(32, 46, "Orange");
			Rectangle* rectangle3 = MakeRectangle(7.6, 6.1, "Yellow");

			Rectangle* copyRectangle1 = CopyRectangle(*rectangle1);
			Rectangle* copyRectangle2 = CopyRectangle(*rectangle2);
			Rectangle* copyRectangle3 = CopyRectangle(*rectangle3);

			cout << "Прямоугольник имеет размеры: "
				<< rectangle1->length << "X" << rectangle1->width
				<< " и цвет: " << rectangle1->color << endl;

			cout << "Копия прямоугольника имеет размеры: "
				<< copyRectangle1->length << "X" << copyRectangle1->width
				<< " и цвет: " << copyRectangle1->color << endl;

			delete rectangle1, rectangle2, rectangle3;
			delete copyRectangle1, copyRectangle2, copyRectangle3;
			 
			 
			} break;
		}
		
	}
}

void DemoFlight()
{
	while (true)
	{
		int value = 0;

		cout << "1. Задание 2.2.3.1, 2.2.3.2, 2.2.4.1 и 2.2.4.2" << endl;
		cout << "2. Задание 2.2.3.3" << endl;
		cout << "3. Задания 2.2.7.2 и 2.2.7.3" << endl;

		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Flight NewFlight;
				cout << "Введите пункт вылета: " << endl;
				getline(cin, NewFlight.DeparturePoint);
				cout << "\nВведите пункт назначения: " << endl;
				getline(cin, NewFlight.Destination);
				cout << "\nВведите время полета в минутах: " << endl;
				cin >> NewFlight.DurationTimeMin;

				cout << "Время полета рейса " << NewFlight.DeparturePoint << " - "
					<< NewFlight.Destination << " составляет " << NewFlight.DurationTimeMin << " минут." << endl;

				//2.2.4.1
				Flight* FirstPointer;
				FirstPointer = &NewFlight;
				
				cout << "2.2.4.1 \nПункт вылета: " << FirstPointer->DeparturePoint
					<< "\nПункт назначения: " << FirstPointer->Destination
					<< "\nВремя полета в минутах: " << FirstPointer->DurationTimeMin << endl;

				Flight* SecondPointer;
				SecondPointer = &NewFlight;

				cout << "Значение первого указателя: " << FirstPointer << "\nЗначение второго указателя: " << SecondPointer << endl;
				
				delete FirstPointer, SecondPointer;
				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "Введите размер массива: ";
				cin >> size;
				Flight* StorFlight = new Flight[size];
				cin.ignore(32767, '\n');

				for (int i = 0; i < size; i++)
				{
					cout << "Введите пункт вылета "<< i <<"-го рейса: " << endl;
					getline(cin, StorFlight[i].DeparturePoint);
					cout << "\nВведите пункт назначения: " << i << "-го рейса:" << endl;
					getline(cin, StorFlight[i].Destination);
					cout << "\nВведите время полета в минутах: " << endl;
					cin >> StorFlight[i].DurationTimeMin;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "Время полета рейса №" << i+1 << endl << StorFlight[i].DeparturePoint << " - "
						<< StorFlight[i].Destination << " составляет " << StorFlight[i].DurationTimeMin << " минут." << endl;
				}

				delete[] StorFlight;
				 
				 
			} break;
			case 3:
			{
				Flight* flight1 = MakeFlight("Москва", "Санкт-Петербург", 45);
				Flight* flight2 = MakeFlight("Алматы", "Новосибирск", 120);

				Flight* copyFlight1 = CopyFlight(*flight1);
				Flight* copyFlight2 = CopyFlight(*flight2);

				delete flight1, flight2;
				delete copyFlight1, copyFlight2;
				 

			}break;
		}
	}
}

void DemoMovie()
{
	while (true)
	{
		int value = 0;

		cout << "1. Задание 2.2.3.1, 2.2.3.2, 2.2.4.1 и 2.2.4.2" << endl;
		cout << "2. Задание 2.2.3.3" << endl;
		cout << "3. Задания 2.2.7.2 и 2.2.7.3" << endl;

		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Movie NewMovie;
				cout << "Введите название фильма: " << endl;
				getline(cin, NewMovie.Title);
				cout << "\nВведите жанр фильма: " << endl;
				getline(cin, NewMovie.Genre);
				cout << "\nВведите год выпуска фильма: " << endl;
				cin >> NewMovie.YearIssue;
				cout << "\nВведите продолжительность фильма: " << endl;
				cin >> NewMovie.DurationMovieMin;
				cout << "\nВведите рейтинг фильма: " << endl;
				cin >> NewMovie.Rating;
				
				cout << "Фильм " << NewMovie.Title << " в жанре " <<
					NewMovie.Genre << " с оценкой " 
					<< NewMovie.Rating << " длится " 
					<< NewMovie.DurationMovieMin << " минут." << endl;

				//2.2.4.1
				Movie* FirstPointer;
				FirstPointer = &NewMovie;

				cout << "2.2.4.1 \nФильм " << FirstPointer->Title << " в жанре " <<
					FirstPointer->Genre << " с оценкой "
					<< FirstPointer->Rating << " длится "
					<< FirstPointer->DurationMovieMin << " минут." << endl;

				Movie* SecondPointer;
				SecondPointer = &NewMovie;

				cout << "Значение первого указателя: " << FirstPointer << "\nЗначение второго указателя: " << SecondPointer << endl;

				delete FirstPointer, SecondPointer;
				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "Введите размер массива: ";
				cin >> size;
				Movie* StorMovie = new Movie[size];
				cin.ignore(32767, '\n');

				for (int i = 0; i < size; i++)
				{
					cout << "Введите название "<< i <<"-го фильма: " << endl;
					getline(cin, StorMovie[i].Title);
					cout << "\nВведите жанр фильма: " << endl;
					getline(cin, StorMovie[i].Genre);
					cout << "\nВведите год выпуска фильма: " << endl;
					cin >> StorMovie[i].YearIssue;
					cout << "\nВведите продолжительность фильма: " << endl;
					cin >> StorMovie[i].DurationMovieMin;
					cout << "\nВведите рейтинг фильма: " << endl;
					cin >> StorMovie[i].Rating;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "Фильм " << StorMovie[i].Title << " в жанре " <<
						StorMovie[i].Genre << " с оценкой "
						<< StorMovie[i].Rating << " длится "
						<< StorMovie[i].DurationMovieMin << " минут." << endl;
				}
				 
				 
			} break;
			case 3:
			{
				Movie* movie1 = MakeMovie("Крестный отец", "Драма/Криминальный фильм", 1972, 175, 8.7);
				Movie* movie2 = MakeMovie("Криминальное чтиво", "Триллер, Комедия, Криминал", 1994, 154, 8.6);

				Movie* copyMovie1 = CopyMovie(*movie1);
				Movie* copyMovie2 = CopyMovie(*movie2);

				delete movie1, movie2;
				delete copyMovie1, copyMovie2;
				 
				 
			} break;
		}
	}
}

void DemoTime()
{
	while (true)
	{
		int value = 0;

		cout << "1. Задание 2.2.3.2" << endl;
		cout << "2. Задание 2.2.3.3" << endl;
		cout << "3. Задания 2.2.7.2 и 2.2.7.3" << endl;

		cin >> value;
		switch (value)
		{
			case 1:
			{
				Time NewTime;
				cout << "Введите часы: (не более 24)" << endl;
				cin >> NewTime.Hour;
				if (NewTime.Hour	>	24)
				{
					cout << "\nНеправильный формат времени!" << endl;
					break;
				}
				cout << "\nВведите минуты: (не более 60)" << endl;
				cin >> NewTime.Min;
				if (NewTime.Min > 60)
				{
					cout << "\nНеправильный формат времени!" << endl;
					break;
				}
				cout << "\nВведите секунды: (не более 60)" << endl;
				cin >> NewTime.Sec;
				if (NewTime.Sec > 60)
				{
					cout << "\nНеправильный формат времени!" << endl;
					break;
				}

				cout << endl << NewTime.Hour << ":" 
					<< NewTime.Min << ":" << NewTime.Sec << endl;
				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "Введите размер массива: ";
				cin >> size;
				Time* StorTime = new Time[size];

				for (int i = 0; i < size; i++)
				{
					cout << "Введите часы: (не более 24)" << endl;
					cin >> StorTime[i].Hour;
					if (StorTime[i].Hour > 24)
					{
						cout << "\nНеправильный формат времени!" << endl;
						break;
					}
					cout << "\nВведите минуты: (не более 60)" << endl;
					cin >> StorTime[i].Min;
					if (StorTime[i].Min > 60)
					{
						cout << "\nНеправильный формат времени!" << endl;
						break;
					}
					cout << "\nВведите секунды: (не более 60)" << endl;
					cin >> StorTime[i].Sec;
					if (StorTime[i].Sec > 60)
					{
						cout << "\nНеправильный формат времени!" << endl;
						break;
					}
				}

				for (int i = 0; i < size; i++)
				{
					cout << endl << i << ". " << StorTime[i].Hour << ":"
						<< StorTime[i].Min << ":" << StorTime[i].Sec << endl;
				}
				delete[] StorTime;
				 
				 
			} break;
			case 3:
			{
				Time* time1 = MakeTime(22, 45, 15);
				Time* time2 = MakeTime(17, 24, 37);

				Time* copyTime1 = CopyTime(*time1);
				Time* copyTime2 = CopyTime(*time2);

				delete time1, time2;
				delete copyTime1, copyTime2;
				 
				 
			} break;
		}
	}
}

void DemoContact()
{
	while (true)
	{
		int value = 0;

		cout << "1. Задание 2.2.3.2" << endl;
		cout << "2. Задание 2.2.3.3" << endl;
		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Contact NewContact;
				cout << "Введите имя контакта: " << endl;
				getline(cin, NewContact.Name);
				cout << "\nВведите телефонный номер: " << endl;
				cin >> NewContact.Number;
				cin.ignore(32767, '\n');
				cout << "\nВведите Email" << endl;
				getline(cin, NewContact.Email);
				cout << "\nВведите дополнительную информацию" << endl;
				getline(cin, NewContact.AddInf);

				cout << "Имя: " << NewContact.Name <<
					"\nТелефон: " << NewContact.Number <<
					"\nEmail: " << NewContact.Email <<
					"\nДополнительная информация: \n"
					<< NewContact.AddInf << endl;

				 
				 
			} break;

			case 2:
			{
				int size;
				cout << "Введите размер массива: ";
				cin >> size;
				cin.ignore(32767, '\n');
				Contact* ContactBook = new Contact[size];

				for (int i = 0; i < size; i++)
				{
					cout << "Введите имя контакта: " << endl;
					getline(cin,ContactBook[i].Name);
					cout << "\nВведите телефонный номер: " << endl;
					cin >> ContactBook[i].Number;
					cin.ignore(32767, '\n');
					cout << "\nВведите Email" << endl;
					getline(cin, ContactBook[i].Email);
					cout << "\nВведите дополнительную информацию" << endl;
					getline(cin, ContactBook[i].AddInf);

					 
					 
				}

				for (int i = 0; i < size; i++)
				{
					cout << "__________________________________________ \n" <<
						"Имя: " << ContactBook[i].Name <<
						"\nТелефон: " << ContactBook[i].Number <<
						"\nEmail: " << ContactBook[i].Email <<
						"\nДополнительная информация: \n"
						<< ContactBook[i].AddInf << endl;
				}
				delete[] ContactBook;

				 
				 
			} break;
		}
	}
}

void DemoSong()
{
	while (true)
	{
		int value = 0;

		cout << "1. Задание 2.2.3.2" << endl;
		cout << "2. Задание 2.2.3.3" << endl;
		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Song NewSong;
				cout << "Введите название трека: " << endl;
				getline(cin, NewSong.SongName);
				cout << "\nВведите исполнителя: " << endl;
				getline(cin, NewSong.Artist);
				cout << "\nВведите продолжительность трека в секундах: " << endl;
				cin >> NewSong.DurationSongSec;

				cout << "Название:\n" << NewSong.SongName <<
					"\nИсполнитель:\n" << NewSong.Artist <<
					"\nПродолжительность:\n" << NewSong.DurationSongSec << endl;

				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "Введите размер плейлиста: ";
				cin >> size;
				cin.ignore(32767, '\n');
				Song* Playlist = new Song[size];

				for (int i = 0; i < size; i++)
				{
					cout << "Введите название трека: " << endl;
					getline(cin, Playlist[i].SongName);
					cout << "\nВведите исполнителя: " << endl;
					getline(cin, Playlist[i].Artist);
					cout << "\nВведите продолжительность трека в секундах: " << endl;
					cin >> Playlist[i].DurationSongSec;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "__________________________________________ \n" <<
						"Название:\n" << Playlist[i].SongName <<
						"\nИсполнитель:\n" << Playlist[i].Artist <<
						"\nПродолжительность:\n" << Playlist[i].DurationSongSec << endl;
				}
				delete[] Playlist;

				 
				 
			} break;
		}
	}
}

void DemoDiscipline()
{
	while (true)
	{
		int value = 0;

		cout << "1. Задание 2.2.3.2" << endl;
		cout << "2. Задание 2.2.3.3" << endl;
		cin >> value;
		switch (value)
		{
			case 1:
			{
				Discipline NewDiscipline;
				cout << "Введите название дисциплины: " << endl;
				getline(cin, NewDiscipline.NameDiscipline);
				cout << "\nВведите имя преподавателя: " << endl;
				getline(cin, NewDiscipline.TeacherName);
				cout << "\nВведите количество часов на дисциплину: " << endl;
				cin >> NewDiscipline.DurationDispH;
				cout << "\nВведите оценку за предмет: " << endl;
				cin >> NewDiscipline.StudRating;

				cout << "Дисциплина: " << NewDiscipline.NameDiscipline <<
					"\nПреподаватель: " << NewDiscipline.TeacherName <<
					"\nЧасы: " << NewDiscipline.DurationDispH <<
					"\nОценка: " << NewDiscipline.DurationDispH << endl;

				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "Введите размер массива: ";
				cin >> size;
				cin.ignore(32767, '\n');
				Discipline* StorDiscipline = new Discipline[size];
				for (int i = 0; i < size; i++)
				{
					cout << "Введите название дисциплины: " << endl;
					getline(cin, StorDiscipline[i].NameDiscipline);
					cout << "\nВведите имя преподавателя: " << endl;
					getline(cin, StorDiscipline[i].TeacherName);
					cout << "\nВведите количество часов на дисциплину: " << endl;
					cin >> StorDiscipline[i].DurationDispH;
					cout << "\nВведите оценку за предмет: " << endl;
					cin >> StorDiscipline[i].StudRating;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "__________________________________________ \n" <<
						"Дисциплина: " << StorDiscipline[i].NameDiscipline <<
						"\nПреподаватель: " << StorDiscipline[i].TeacherName <<
						"\nЧасы: " << StorDiscipline[i].DurationDispH <<
						"\nОценка: " << StorDiscipline[i].DurationDispH << endl;
				}
				delete[] StorDiscipline;

				 
				 
			} break;
		}
	}
}

//2.2.4.4
void WrongPointers()
{
	Flight flight;
	Movie movie;

	Flight* flightPointer;
	flightPointer = &flight;

	Movie* moviePointer;
	moviePointer = &movie;

	//flightPointer = &movie;
	//moviePointer = &flight;
}

void WriteRectangle(Rectangle& rectangle)
{
	cout << "Прямоугольник имеет размер: " << rectangle.length << "x" << rectangle.width << endl;
}

void ReadRectangle(Rectangle& rectangle)
{
	cout << "Введите длину прямоугольника: " << endl;
	cin >> rectangle.length;
	cout << "\nВведите ширину прямоугольника: " << endl;
	cin >> rectangle.width;
	WriteRectangle(rectangle);
}

void DemoReadAndWriteRectangles()
{
	Rectangle rectangle[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "\nПрямоугольник №" << i + 1 << endl;
		ReadRectangle(rectangle[i]);
	}
}

void Exchange(Rectangle& rectangle1, Rectangle& rectangle2)
{
	double tempLenght1 = rectangle1.length, tempWidht1 = rectangle1.width;
	double tempLenght2 = rectangle2.length, tempWidht2 = rectangle2.width;

	rectangle1.length = tempLenght2;
	rectangle1.width = tempWidht2;

	rectangle2.length = tempLenght1;
	rectangle2.width = tempWidht1;
}

void FindRectangle(Rectangle* rectangles, int count)
{
	double maxLength = 0.0;
	int maxIndex = 0;

	for (int i = 0; i < count; i++)
	{
		if (maxLength < rectangles[i].length)
		{
			maxLength = rectangles[i].length;
			maxIndex = i;
		}
	}

	cout << "Прямоугольник с максимальной длиной: " << rectangles[maxIndex].length
		<< "x" << rectangles[maxIndex].width << endl;
}

void FindMaxRectangle(Rectangle* rectangles, int count)
{
	double maxRectangle = 0.0;
	int maxRectangleIndex = 0;

	for (int i = 0; i < count; i++)
	{
		if (maxRectangle < rectangles[i].length * rectangles[i].width)
		{
			maxRectangle = rectangles[i].length * rectangles[i].width;
			maxRectangleIndex = i;
		}
	}

	cout << endl << "Прямоугольник с максимальной площадью имеет размер: "
		<< rectangles[maxRectangleIndex].length << " X " << rectangles[maxRectangleIndex].width << " = "
		<< rectangles[maxRectangleIndex].length * rectangles[maxRectangleIndex].width << endl;
}

void DemoDynamicFlight()
{
	Flight* flight = new Flight;
	
	flight->DeparturePoint = "Москва";
	flight->Destination = "Санкт-Петербург";
	flight->DurationTimeMin = 45;

	cout << "Рейс " << flight->DeparturePoint
		<< " - " << flight->Destination
		<< " находится в полете " << flight->DurationTimeMin << " минут." << endl;
	delete flight;
}

void DemoDynamicFlights()
{
	Flight* StorFlight = new Flight[4];

	for (int i = 0; i < 4; i++)
	{
		cin.ignore(32767, '\n');
		cout << "Введите данные " << i + 1 << "-го рейса:" << endl;
		cout << "Точка отправления:" << endl;
		getline(cin, StorFlight[i].DeparturePoint);
		cout << "\nТочка назначения:" << endl;
		getline(cin, StorFlight[i].Destination);
		cout << "\nВремя полета:" << endl;
		cin >> StorFlight[i].DurationTimeMin;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "Рейс " << i+1 << " " << StorFlight[i].DeparturePoint
			<< " - " << StorFlight[i].Destination
			<< " находится в полете " << StorFlight[i].DurationTimeMin << " минут." << endl;
	}

	FindShorterFlights(StorFlight, 4);

	delete[] StorFlight;
}

void FindShorterFlights(Flight* flights, int count)
{
	int tempShort = flights[0].DurationTimeMin;
	int tempShortIndex;

	for (int i = 0; i < count; i++)
	{
		if (tempShort > flights[i].DurationTimeMin)
		{
			tempShort = flights[i].DurationTimeMin;
			tempShortIndex = i;
		}
	}

	cout << "\nСамый короткий рейс №" << flights[tempShortIndex].DeparturePoint
		<< " - " << flights[tempShortIndex].Destination
		<< " Время полета: " << flights[tempShortIndex].DurationTimeMin << endl;
}

Rectangle* MakeRectangle(double lenght, double width, string color)
{
	Rectangle* rectangle = new Rectangle();
	rectangle->length = lenght;
	rectangle->width = width;
	rectangle->color = color;
	return rectangle;
}

Rectangle* CopyRectangle(Rectangle rectangles)
{
	Rectangle* copiedRectangle = new Rectangle();
	copiedRectangle->length = rectangles.length;
	copiedRectangle->width = rectangles.width;
	copiedRectangle->color = rectangles.color;
	return copiedRectangle;
}

Flight* MakeFlight(string DepaturePoint, string Destination, int DurationTimeMin)
{
	Flight* flights = new Flight();
	flights->DeparturePoint = DepaturePoint;
	flights->Destination = Destination;
	flights->DurationTimeMin = DurationTimeMin;
	return flights;
}

Flight* CopyFlight(Flight flights)
{
	Flight* copiedFlights = new Flight();
	copiedFlights->DeparturePoint = flights.DeparturePoint;
	copiedFlights->Destination = flights.Destination;
	copiedFlights->DurationTimeMin = flights.DurationTimeMin;
	return copiedFlights;
}

Movie* MakeMovie(string Title, string Genre, int YeasIssue, int DurationTimeMin, double Rating)
{
	Movie* movies = new Movie();
	movies->Title = Title;
	movies->Genre = Genre;
	movies->YearIssue = YeasIssue;
	movies->DurationMovieMin = DurationTimeMin;
	movies->Rating = Rating;
	return movies;
}

Movie* CopyMovie(Movie movies)
{
	Movie* copiedMovies = new Movie();
	copiedMovies->Title = movies.Title;
	copiedMovies->Genre = movies.Genre;
	copiedMovies->YearIssue = movies.YearIssue;
	copiedMovies->DurationMovieMin = movies.DurationMovieMin;
	copiedMovies->Rating = movies.Rating;
	return copiedMovies;
}

Time* MakeTime(int Hour, int Min, int Sec)
{
	Time* times = new Time();
	times->Hour = Hour;
	times->Min = Min;
	times->Sec = Sec;
	return times;
}

Time* CopyTime(Time times)
{
	Time* copiedTimes = new Time();
	copiedTimes->Hour = times.Hour;
	copiedTimes->Min = times.Min;
	copiedTimes->Sec = times.Sec;
	return copiedTimes;
}
