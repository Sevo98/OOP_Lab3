#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Book 
{
	string Name;
	int PublishYear;
	int Pages;
	int AuthorNumbers;
	string Authors[10];
};

void DemoBook();

void ReadBookFromConsole(Book& book);
void WriteBookFromConsole(Book& book);
int FindBookByAuthor(Book* books, int booksCount, string author);