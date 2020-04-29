#include <iostream>
#include "Struct with enums.h"
#include "Enums.h"
#include "Enums.cpp"
using namespace std;

//With enums
struct Movies
{
	string Title = "";
	Genre genre;
	int YearIssue = 0, DurationMovieMin = 0;
	double Rating = 0;
};
Movies* MakeMovies(string Title, Genre Genre, int YeasIssue, int DurationTimeMin, double Rating);
int CountMoviesByGenre(Movies* movies, int count, Genre findGenre);
Movies* FindBestGenreMovie(Movies* movies, int count, Genre findgenre);

//With enums
void DemoMovieWithGenre()
{
	Movies movie;
	movie.Title = "Крестный отец";
	movie.genre = Criminal;
	movie.YearIssue = 1972;
	movie.DurationMovieMin = 175;
	movie.Rating = 8.733;

	Movies* StorMovies = new Movies[4];

	StorMovies[0] = *MakeMovies("Криминальное чтиво", Criminal, 1994, 154, 8.619);
	StorMovies[1] = *MakeMovies("Заклятие", Horrors, 2013, 112, 7.367);
	StorMovies[2] = *MakeMovies("Господин Никто", Drama, 2009, 138, 7.906);
	StorMovies[3] = *MakeMovies("Большой куш", Criminal, 2000, 104, 8.536);

	int countMovies = CountMoviesByGenre(StorMovies, 3, Criminal);
	cout << "Фильмов с жанром Criminal: " << countMovies << endl;

	Movies* BestMovie = FindBestGenreMovie(StorMovies, 4, Criminal);
	cout << "Название фильма с самым высоким рейтингом среди фильмов с жанром Criminal: " << BestMovie->Title << endl;

	delete[] StorMovies;
}
//With enums
Movies* MakeMovies(string Title, Genre Genre, int YeasIssue, int DurationTimeMin, double Rating)
{
	Movies* movies = new Movies();
	movies->Title = Title;
	movies->genre = Genre;
	movies->YearIssue = YeasIssue;
	movies->DurationMovieMin = DurationTimeMin;
	movies->Rating = Rating;
	return movies;
	delete movies;
}
//With enums
int CountMoviesByGenre(Movies* movies, int count, Genre findGenre)
{
	int value = 0;
	for (int i = 0; i < count; i++)
	{
		if (movies[i].genre == findGenre)
		{
			value++;
		}
	}
	return value;
}

Movies* FindBestGenreMovie(Movies* movies, int count, Genre findgenre)
{
	double maxRating = -1;
	int maxRatingIndex = 0;

	for (int i = 0; i < count; i++)
	{
		if (movies[i].genre == findgenre)
		{
			if (movies[i].Rating > maxRating)
			{
				maxRating = movies[i].Rating;
				maxRatingIndex = i;
			}
		}
	}

	if (maxRating < 0)
	{
		return nullptr;
	}
	else
	{
		return &movies[maxRatingIndex];
	}
}