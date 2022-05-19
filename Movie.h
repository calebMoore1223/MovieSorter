#ifndef mv
#define mv
#include <iostream>
#include <string>
#include <sstream>
struct Movie {
    std::string title;              /// Movie title
    unsigned short year = 0;            /// Movie release year
    std::string director;           /// Director's name
    std::string rating;             /// Movie audience rating

    Movie(std::istream& infile);  /// construct given an input stream
    void write(std::ostream& outfile) const;
};
std::ostream& operator<<(std::ostream& outfile, const Movie& movie);
#endif