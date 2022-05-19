#include <iostream>
#include <fstream>
#include "Movie.h"
#include "OrderedMovieList.h"

int main() {
	OrderedMovieList movie_list;
	std::cout << "\nMovies before sorting:\n";
	std::ifstream    movie_db{ "movies.txt" };
	if (movie_db) {
		while (movie_db.good()) {
			movie_list.insert(Movie{ movie_db });
		}
		movie_db.close();
		std::cout << "\nMovies after sorting:\n"
			<< movie_list << "\n\n";
	}
	else {
		std::cout << "\nCannot open file...\n";
	}
	return 0;
}


