#ifndef mnh
#define mnh
#include "Movie.h"

class MovieNode {
public:
	MovieNode(const Movie& obj)
		: payload{ obj } {}
	MovieNode* get_next();
	void set_next(MovieNode* obj);
	Movie get_movie();
	std::ostream& write(std::ostream& fout) const;
	bool operator < (const MovieNode& rhs) const;
	~MovieNode();
private:
	Movie payload;
	MovieNode* next = nullptr;
};

#endif