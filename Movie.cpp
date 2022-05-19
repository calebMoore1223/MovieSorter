#include "Movie.h"
#include "MovieNode.h"
Movie::Movie(std::istream& infile)
{ // Input format - Blade Runner 2049|2017|Denis Villeneuve|R
	std::string getLine;
	std::getline(infile, title, '|'); // skip first
	std::getline(infile, getLine, '|');
	std::istringstream iss(getLine);
	iss >> year;
	std::getline(infile, director, '|');
	std::getline(infile, rating);
	std::cout << title << " " << year << " " << director << " " << rating << "\n";
}

void Movie::write(std::ostream& outfile) const
{ // Output format - Blade Runner 2049 (2017) R - Denis Villeneuve
	outfile << title << " (" << year << ") "
		<< rating << " - " << director << std::endl;
}

std::ostream& operator<<(std::ostream& outfile, const Movie& movie)
{
	movie.write(outfile);
	return outfile;
}
