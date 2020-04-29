#include <iostream>
#include <Windows.h>
#include "Book.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");

    DemoBook();
	
	Book book;
	ReadBookFromConsole(book);
	WriteBookFromConsole(book);

}
