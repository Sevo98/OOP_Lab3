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

		cout << "1. ������� 2.2.3.1, 2.2.3.2, 2.2.4.1 � 2.2.4.2" << endl;
		cout << "2. ������� 2.2.3.3, 2.2.5.5 � 2.2.5.6" << endl;
		cout << "3. ������� 2.2.5.4" << endl;
		cout << "4. ������� 2.2.7.2 � 2.2.7.3" << endl;

		cin >> value;

		switch (value)
		{
		case 1: 
			{
				Rectangle NewRectangle;

				cout << "������� ����� �������������� (������������� �����):" << endl;
				cin >> NewRectangle.length;
				cout << "\n������� ������ �������������� (������������� �����):" << endl;
				cin >> NewRectangle.width;
				
				cout << "\n������������� ����� �������: " << NewRectangle.length << "X" << NewRectangle.width << endl;

				//2.2.4.1
				Rectangle* FirstPointer;
				FirstPointer = &NewRectangle;

				cout << "2.2.4.1 \n������������� ����� �������: " 
					<< FirstPointer->length << "X" << FirstPointer->width 
					<< "\n������������� ����� ����: " << FirstPointer->color << endl;

				Rectangle* SecondPointer;
				SecondPointer = &NewRectangle;

				cout << "�������� ������� ���������: " << FirstPointer << "\n�������� ������� ���������: " << SecondPointer << endl;

				delete FirstPointer, SecondPointer;
				 
				 
			} break;
		case 2:
			{
			int size;
			cout << "������� ������ �������: ";
			cin >> size;
			Rectangle* StorRectangle = new Rectangle[size];
			
			for (int i = 0; i < size; i++)
			{
				cout << "������� ����� " << i+1 << "-��" << " �������������� (������������� �����):" << endl;
				cin >> StorRectangle[i].length;
				cout << "\n������� ������ " << i+1 << "-��" << " �������������� (������������� �����):" << endl;
				cin >> StorRectangle[i].width;
			}
			for (int i = 0; i < size; i++)
			{
				cout << "\n������������� " << i+1 << " ����� �������: " << StorRectangle[i].length << "X" << StorRectangle[i].width << endl;
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
				cout << "������� ����� " << i+1 << "-��" << " �������������� (������������� �����):" << endl;
				cin >> rectangle[i].length;
				cout << "\n������� ������ " << i + 1 << "-��" << " �������������� (������������� �����):" << endl;
				cin >> rectangle[i].width;
			}
			
			for (int i = 0; i < 2; i++)
			{
				cout << "\n������������� " << i + 1 << " ����� �������: " << rectangle[i].length << "X" << rectangle[i].width << endl;
			}
			Exchange(rectangle[0], rectangle[1]);

			for (int i = 0; i < 2; i++)
			{
				cout << "\n������������� " << i + 1 << " ����� �������: " << rectangle[i].length << "X" << rectangle[i].width << endl;
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

			cout << "������������� ����� �������: "
				<< rectangle1->length << "X" << rectangle1->width
				<< " � ����: " << rectangle1->color << endl;

			cout << "����� �������������� ����� �������: "
				<< copyRectangle1->length << "X" << copyRectangle1->width
				<< " � ����: " << copyRectangle1->color << endl;

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

		cout << "1. ������� 2.2.3.1, 2.2.3.2, 2.2.4.1 � 2.2.4.2" << endl;
		cout << "2. ������� 2.2.3.3" << endl;
		cout << "3. ������� 2.2.7.2 � 2.2.7.3" << endl;

		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Flight NewFlight;
				cout << "������� ����� ������: " << endl;
				getline(cin, NewFlight.DeparturePoint);
				cout << "\n������� ����� ����������: " << endl;
				getline(cin, NewFlight.Destination);
				cout << "\n������� ����� ������ � �������: " << endl;
				cin >> NewFlight.DurationTimeMin;

				cout << "����� ������ ����� " << NewFlight.DeparturePoint << " - "
					<< NewFlight.Destination << " ���������� " << NewFlight.DurationTimeMin << " �����." << endl;

				//2.2.4.1
				Flight* FirstPointer;
				FirstPointer = &NewFlight;
				
				cout << "2.2.4.1 \n����� ������: " << FirstPointer->DeparturePoint
					<< "\n����� ����������: " << FirstPointer->Destination
					<< "\n����� ������ � �������: " << FirstPointer->DurationTimeMin << endl;

				Flight* SecondPointer;
				SecondPointer = &NewFlight;

				cout << "�������� ������� ���������: " << FirstPointer << "\n�������� ������� ���������: " << SecondPointer << endl;
				
				delete FirstPointer, SecondPointer;
				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "������� ������ �������: ";
				cin >> size;
				Flight* StorFlight = new Flight[size];
				cin.ignore(32767, '\n');

				for (int i = 0; i < size; i++)
				{
					cout << "������� ����� ������ "<< i <<"-�� �����: " << endl;
					getline(cin, StorFlight[i].DeparturePoint);
					cout << "\n������� ����� ����������: " << i << "-�� �����:" << endl;
					getline(cin, StorFlight[i].Destination);
					cout << "\n������� ����� ������ � �������: " << endl;
					cin >> StorFlight[i].DurationTimeMin;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "����� ������ ����� �" << i+1 << endl << StorFlight[i].DeparturePoint << " - "
						<< StorFlight[i].Destination << " ���������� " << StorFlight[i].DurationTimeMin << " �����." << endl;
				}

				delete[] StorFlight;
				 
				 
			} break;
			case 3:
			{
				Flight* flight1 = MakeFlight("������", "�����-���������", 45);
				Flight* flight2 = MakeFlight("������", "�����������", 120);

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

		cout << "1. ������� 2.2.3.1, 2.2.3.2, 2.2.4.1 � 2.2.4.2" << endl;
		cout << "2. ������� 2.2.3.3" << endl;
		cout << "3. ������� 2.2.7.2 � 2.2.7.3" << endl;

		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Movie NewMovie;
				cout << "������� �������� ������: " << endl;
				getline(cin, NewMovie.Title);
				cout << "\n������� ���� ������: " << endl;
				getline(cin, NewMovie.Genre);
				cout << "\n������� ��� ������� ������: " << endl;
				cin >> NewMovie.YearIssue;
				cout << "\n������� ����������������� ������: " << endl;
				cin >> NewMovie.DurationMovieMin;
				cout << "\n������� ������� ������: " << endl;
				cin >> NewMovie.Rating;
				
				cout << "����� " << NewMovie.Title << " � ����� " <<
					NewMovie.Genre << " � ������� " 
					<< NewMovie.Rating << " ������ " 
					<< NewMovie.DurationMovieMin << " �����." << endl;

				//2.2.4.1
				Movie* FirstPointer;
				FirstPointer = &NewMovie;

				cout << "2.2.4.1 \n����� " << FirstPointer->Title << " � ����� " <<
					FirstPointer->Genre << " � ������� "
					<< FirstPointer->Rating << " ������ "
					<< FirstPointer->DurationMovieMin << " �����." << endl;

				Movie* SecondPointer;
				SecondPointer = &NewMovie;

				cout << "�������� ������� ���������: " << FirstPointer << "\n�������� ������� ���������: " << SecondPointer << endl;

				delete FirstPointer, SecondPointer;
				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "������� ������ �������: ";
				cin >> size;
				Movie* StorMovie = new Movie[size];
				cin.ignore(32767, '\n');

				for (int i = 0; i < size; i++)
				{
					cout << "������� �������� "<< i <<"-�� ������: " << endl;
					getline(cin, StorMovie[i].Title);
					cout << "\n������� ���� ������: " << endl;
					getline(cin, StorMovie[i].Genre);
					cout << "\n������� ��� ������� ������: " << endl;
					cin >> StorMovie[i].YearIssue;
					cout << "\n������� ����������������� ������: " << endl;
					cin >> StorMovie[i].DurationMovieMin;
					cout << "\n������� ������� ������: " << endl;
					cin >> StorMovie[i].Rating;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "����� " << StorMovie[i].Title << " � ����� " <<
						StorMovie[i].Genre << " � ������� "
						<< StorMovie[i].Rating << " ������ "
						<< StorMovie[i].DurationMovieMin << " �����." << endl;
				}
				 
				 
			} break;
			case 3:
			{
				Movie* movie1 = MakeMovie("�������� ����", "�����/������������ �����", 1972, 175, 8.7);
				Movie* movie2 = MakeMovie("������������ �����", "�������, �������, ��������", 1994, 154, 8.6);

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

		cout << "1. ������� 2.2.3.2" << endl;
		cout << "2. ������� 2.2.3.3" << endl;
		cout << "3. ������� 2.2.7.2 � 2.2.7.3" << endl;

		cin >> value;
		switch (value)
		{
			case 1:
			{
				Time NewTime;
				cout << "������� ����: (�� ����� 24)" << endl;
				cin >> NewTime.Hour;
				if (NewTime.Hour	>	24)
				{
					cout << "\n������������ ������ �������!" << endl;
					break;
				}
				cout << "\n������� ������: (�� ����� 60)" << endl;
				cin >> NewTime.Min;
				if (NewTime.Min > 60)
				{
					cout << "\n������������ ������ �������!" << endl;
					break;
				}
				cout << "\n������� �������: (�� ����� 60)" << endl;
				cin >> NewTime.Sec;
				if (NewTime.Sec > 60)
				{
					cout << "\n������������ ������ �������!" << endl;
					break;
				}

				cout << endl << NewTime.Hour << ":" 
					<< NewTime.Min << ":" << NewTime.Sec << endl;
				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "������� ������ �������: ";
				cin >> size;
				Time* StorTime = new Time[size];

				for (int i = 0; i < size; i++)
				{
					cout << "������� ����: (�� ����� 24)" << endl;
					cin >> StorTime[i].Hour;
					if (StorTime[i].Hour > 24)
					{
						cout << "\n������������ ������ �������!" << endl;
						break;
					}
					cout << "\n������� ������: (�� ����� 60)" << endl;
					cin >> StorTime[i].Min;
					if (StorTime[i].Min > 60)
					{
						cout << "\n������������ ������ �������!" << endl;
						break;
					}
					cout << "\n������� �������: (�� ����� 60)" << endl;
					cin >> StorTime[i].Sec;
					if (StorTime[i].Sec > 60)
					{
						cout << "\n������������ ������ �������!" << endl;
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

		cout << "1. ������� 2.2.3.2" << endl;
		cout << "2. ������� 2.2.3.3" << endl;
		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Contact NewContact;
				cout << "������� ��� ��������: " << endl;
				getline(cin, NewContact.Name);
				cout << "\n������� ���������� �����: " << endl;
				cin >> NewContact.Number;
				cin.ignore(32767, '\n');
				cout << "\n������� Email" << endl;
				getline(cin, NewContact.Email);
				cout << "\n������� �������������� ����������" << endl;
				getline(cin, NewContact.AddInf);

				cout << "���: " << NewContact.Name <<
					"\n�������: " << NewContact.Number <<
					"\nEmail: " << NewContact.Email <<
					"\n�������������� ����������: \n"
					<< NewContact.AddInf << endl;

				 
				 
			} break;

			case 2:
			{
				int size;
				cout << "������� ������ �������: ";
				cin >> size;
				cin.ignore(32767, '\n');
				Contact* ContactBook = new Contact[size];

				for (int i = 0; i < size; i++)
				{
					cout << "������� ��� ��������: " << endl;
					getline(cin,ContactBook[i].Name);
					cout << "\n������� ���������� �����: " << endl;
					cin >> ContactBook[i].Number;
					cin.ignore(32767, '\n');
					cout << "\n������� Email" << endl;
					getline(cin, ContactBook[i].Email);
					cout << "\n������� �������������� ����������" << endl;
					getline(cin, ContactBook[i].AddInf);

					 
					 
				}

				for (int i = 0; i < size; i++)
				{
					cout << "__________________________________________ \n" <<
						"���: " << ContactBook[i].Name <<
						"\n�������: " << ContactBook[i].Number <<
						"\nEmail: " << ContactBook[i].Email <<
						"\n�������������� ����������: \n"
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

		cout << "1. ������� 2.2.3.2" << endl;
		cout << "2. ������� 2.2.3.3" << endl;
		cin >> value;
		cin.ignore(32767, '\n');
		switch (value)
		{
			case 1:
			{
				Song NewSong;
				cout << "������� �������� �����: " << endl;
				getline(cin, NewSong.SongName);
				cout << "\n������� �����������: " << endl;
				getline(cin, NewSong.Artist);
				cout << "\n������� ����������������� ����� � ��������: " << endl;
				cin >> NewSong.DurationSongSec;

				cout << "��������:\n" << NewSong.SongName <<
					"\n�����������:\n" << NewSong.Artist <<
					"\n�����������������:\n" << NewSong.DurationSongSec << endl;

				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "������� ������ ���������: ";
				cin >> size;
				cin.ignore(32767, '\n');
				Song* Playlist = new Song[size];

				for (int i = 0; i < size; i++)
				{
					cout << "������� �������� �����: " << endl;
					getline(cin, Playlist[i].SongName);
					cout << "\n������� �����������: " << endl;
					getline(cin, Playlist[i].Artist);
					cout << "\n������� ����������������� ����� � ��������: " << endl;
					cin >> Playlist[i].DurationSongSec;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "__________________________________________ \n" <<
						"��������:\n" << Playlist[i].SongName <<
						"\n�����������:\n" << Playlist[i].Artist <<
						"\n�����������������:\n" << Playlist[i].DurationSongSec << endl;
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

		cout << "1. ������� 2.2.3.2" << endl;
		cout << "2. ������� 2.2.3.3" << endl;
		cin >> value;
		switch (value)
		{
			case 1:
			{
				Discipline NewDiscipline;
				cout << "������� �������� ����������: " << endl;
				getline(cin, NewDiscipline.NameDiscipline);
				cout << "\n������� ��� �������������: " << endl;
				getline(cin, NewDiscipline.TeacherName);
				cout << "\n������� ���������� ����� �� ����������: " << endl;
				cin >> NewDiscipline.DurationDispH;
				cout << "\n������� ������ �� �������: " << endl;
				cin >> NewDiscipline.StudRating;

				cout << "����������: " << NewDiscipline.NameDiscipline <<
					"\n�������������: " << NewDiscipline.TeacherName <<
					"\n����: " << NewDiscipline.DurationDispH <<
					"\n������: " << NewDiscipline.DurationDispH << endl;

				 
				 
			} break;
			case 2:
			{
				int size;
				cout << "������� ������ �������: ";
				cin >> size;
				cin.ignore(32767, '\n');
				Discipline* StorDiscipline = new Discipline[size];
				for (int i = 0; i < size; i++)
				{
					cout << "������� �������� ����������: " << endl;
					getline(cin, StorDiscipline[i].NameDiscipline);
					cout << "\n������� ��� �������������: " << endl;
					getline(cin, StorDiscipline[i].TeacherName);
					cout << "\n������� ���������� ����� �� ����������: " << endl;
					cin >> StorDiscipline[i].DurationDispH;
					cout << "\n������� ������ �� �������: " << endl;
					cin >> StorDiscipline[i].StudRating;
				}

				for (int i = 0; i < size; i++)
				{
					cout << "__________________________________________ \n" <<
						"����������: " << StorDiscipline[i].NameDiscipline <<
						"\n�������������: " << StorDiscipline[i].TeacherName <<
						"\n����: " << StorDiscipline[i].DurationDispH <<
						"\n������: " << StorDiscipline[i].DurationDispH << endl;
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
	cout << "������������� ����� ������: " << rectangle.length << "x" << rectangle.width << endl;
}

void ReadRectangle(Rectangle& rectangle)
{
	cout << "������� ����� ��������������: " << endl;
	cin >> rectangle.length;
	cout << "\n������� ������ ��������������: " << endl;
	cin >> rectangle.width;
	WriteRectangle(rectangle);
}

void DemoReadAndWriteRectangles()
{
	Rectangle rectangle[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "\n������������� �" << i + 1 << endl;
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

	cout << "������������� � ������������ ������: " << rectangles[maxIndex].length
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

	cout << endl << "������������� � ������������ �������� ����� ������: "
		<< rectangles[maxRectangleIndex].length << " X " << rectangles[maxRectangleIndex].width << " = "
		<< rectangles[maxRectangleIndex].length * rectangles[maxRectangleIndex].width << endl;
}

void DemoDynamicFlight()
{
	Flight* flight = new Flight;
	
	flight->DeparturePoint = "������";
	flight->Destination = "�����-���������";
	flight->DurationTimeMin = 45;

	cout << "���� " << flight->DeparturePoint
		<< " - " << flight->Destination
		<< " ��������� � ������ " << flight->DurationTimeMin << " �����." << endl;
	delete flight;
}

void DemoDynamicFlights()
{
	Flight* StorFlight = new Flight[4];

	for (int i = 0; i < 4; i++)
	{
		cin.ignore(32767, '\n');
		cout << "������� ������ " << i + 1 << "-�� �����:" << endl;
		cout << "����� �����������:" << endl;
		getline(cin, StorFlight[i].DeparturePoint);
		cout << "\n����� ����������:" << endl;
		getline(cin, StorFlight[i].Destination);
		cout << "\n����� ������:" << endl;
		cin >> StorFlight[i].DurationTimeMin;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "���� " << i+1 << " " << StorFlight[i].DeparturePoint
			<< " - " << StorFlight[i].Destination
			<< " ��������� � ������ " << StorFlight[i].DurationTimeMin << " �����." << endl;
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

	cout << "\n����� �������� ���� �" << flights[tempShortIndex].DeparturePoint
		<< " - " << flights[tempShortIndex].Destination
		<< " ����� ������: " << flights[tempShortIndex].DurationTimeMin << endl;
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
