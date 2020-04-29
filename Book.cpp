#include <iostream>
#include "Book.h"

using namespace std;

void DemoBook()
{
	Book books[3];
	for (int i = 0; i < 3; i++)
	{
		ReadBookFromConsole(books[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		WriteBookFromConsole(books[i]);
	}

	/*Book book1;
	book1.Name = "Head First Java";
	book1.PublishYear = 2020;
	book1.Pages = 717;
	book1.AuthorNumbers = 2;
	book1.Authors[0] = "���� ������";
	book1.Authors[1] = "���� �����";

	cout << book1.Name << endl;
	cout << book1.PublishYear << endl;
	cout << book1.Pages << endl;
	cout << book1.AuthorNumbers << endl;
	for (int i = 0; i < book1.AuthorNumbers; i++)
	{
		cout << book1.Authors[i] << endl;
	}*/

}

void ReadBookFromConsole(Book& book)
{
	setlocale(LC_ALL, "ru");
	cout << "������� �������� �����: ";
	getline(cin, book.Name);
	
	
	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
			{
				cout << "������� ��� �������: ";
				int year;
				cin >> year;
				if (year < 0 || year > 2020)
				{
					throw exception("������������ ��� �������! ��������� ����.");
				}
				book.PublishYear = year;
				CheckYear = true;
			}
			catch (const std::exception&)
			{
				cout << "������������ ��� �������! ��������� ����." << endl;
			}
	}
	
	bool CheckPage = false;
	while (CheckPage == false)
	{
		try
		{
			cout << "������� ���������� �������: ";
			int pages;
			cin >> pages;
			if (pages <= 1)
			{
				throw exception("���������� ������� �� ������ ���� ������ 1! ��������� ����.");
			}
			book.Pages = pages;
			CheckPage = true;
		}
		catch (const exception&)
		{
			cout << "���������� ������� �� ������ ���� ������ 1! ��������� ����." << endl;
 		}
	}

	bool CheckAuthor = false;
	while (CheckAuthor == false)
	{
		try
		{
			cout << "������� ���������� �������: ";
			int authors;
			cin >> authors;

			if (authors < 1 || authors > 10)
			{
				throw exception("���������� ������� ������ ���� � ��������� 1-10. ��������� ����.");
			}
			book.AuthorNumbers = authors;
			CheckAuthor = true;
		}
		catch (const exception&)
		{
			cout << "���������� ������� ������ ���� � ��������� 1-10. ��������� ����." << endl;
		}
	}

	cin.ignore(32767, '\n');
	for (int i = 0; i < book.AuthorNumbers; i++)
	{ 
		int j = i;
		cout << "\n������� ������ �" << j + 1 << ": ";
		getline(cin, book.Authors[i]);
	}

}

void WriteBookFromConsole(Book& book)
{
	setlocale(LC_ALL, "ru");
	for (int i = 0; i < book.AuthorNumbers; i++)
	{
		cout << book.Authors[i];
		if (i < book.AuthorNumbers - 1)
		{
			cout << ", ";
		}
		else if (i == book.AuthorNumbers - 1)
		{
			cout << ". ";
		}
	}

	cout << book.Name << ". ";
	cout << book.PublishYear << ". - " << book.Pages << "c." << endl;
}
