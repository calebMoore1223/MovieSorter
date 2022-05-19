#ifndef omlh
#define omlh
#include "MovieNode.h"
class OrderedMovieList {
public:
    OrderedMovieList() = default;
    std::ostream& write(std::ostream& fout) const;
    Movie remove_front();                // can change the list and ruin it
    void erase();
    bool is_empty();
    void insert(const Movie& obj);
private:
    MovieNode* head = nullptr;
    int totalNodes = 0; // for potential looping
};
std::ostream& operator<<(std::ostream& fout, const OrderedMovieList& list);
#endif