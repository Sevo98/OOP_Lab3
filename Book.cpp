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
	book1.Authors[0] = "Кэти Сьерра";
	book1.Authors[1] = "Берт Бейтс";

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
	cout << "Введите название книги: ";
	getline(cin, book.Name);
	
	
	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
			{
				cout << "Введите год издания: ";
				int year;
				cin >> year;
				if (year < 0 || year > 2020)
				{
					throw exception("Неправильный год издания! Повторите ввод.");
				}
				book.PublishYear = year;
				CheckYear = true;
			}
			catch (const std::exception&)
			{
				cout << "Неправильный год издания! Повторите ввод." << endl;
			}
	}
	
	bool CheckPage = false;
	while (CheckPage == false)
	{
		try
		{
			cout << "Введите количество страниц: ";
			int pages;
			cin >> pages;
			if (pages <= 1)
			{
				throw exception("Количество страниц не должно быть меньше 1! Повторите ввод.");
			}
			book.Pages = pages;
			CheckPage = true;
		}
		catch (const exception&)
		{
			cout << "Количество страниц не должно быть меньше 1! Повторите ввод." << endl;
 		}
	}

	bool CheckAuthor = false;
	while (CheckAuthor == false)
	{
		try
		{
			cout << "Введите количество авторов: ";
			int authors;
			cin >> authors;

			if (authors < 1 || authors > 10)
			{
				throw exception("Количество авторов должно быть в диапазоне 1-10. Повторите ввод.");
			}
			book.AuthorNumbers = authors;
			CheckAuthor = true;
		}
		catch (const exception&)
		{
			cout << "Количество авторов должно быть в диапазоне 1-10. Повторите ввод." << endl;
		}
	}

	cin.ignore(32767, '\n');
	for (int i = 0; i < book.AuthorNumbers; i++)
	{ 
		int j = i;
		cout << "\nВведите автора №" << j + 1 << ": ";
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
