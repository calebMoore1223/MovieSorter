#include "OrderedMovieList.h"

std::ostream& OrderedMovieList::write(std::ostream& fout) const
{
	MovieNode* current = head;
	while (current != nullptr) {
		current->write(fout);
		current = current->get_next();
	}
	return fout;
}

Movie OrderedMovieList::remove_front()
{
	if (head == nullptr) {
		throw std::length_error{ "Cannot remove from an empty list." };
	}
	MovieNode* ohead = head;
	Movie result = this->head->get_movie();
	head = head->get_next();
	delete ohead;
	totalNodes -= 1;
	return result;
}

void OrderedMovieList::insert(const Movie& obj)
{
	MovieNode* newNode = new MovieNode{ obj };
	if (head == nullptr) {
		head = newNode;
		return;
	}
	MovieNode* current = head;
	MovieNode* prev = head;
	while (*current < *newNode) {				// loop until we reach 			 
		if (current->get_next() != nullptr) {   // ideal spot
			prev = current;
			current = current->get_next();
		}
		else {
			break;
		}
	}
	if (current == head) { // if fits at head or empty list
		newNode->set_next(head);
		head = newNode;
	}
	else { // fits elsewhere in list
		prev->set_next(newNode);
		newNode->set_next(current);
	}
}


void OrderedMovieList::erase()
{
	MovieNode* next = head; // add next to fix access errors
	while (head != nullptr) {
		{
			next = head->get_next();
			remove_front();
			head = next;
			if (!head->get_next()) {
				head = nullptr;
			}
		}
	}
	totalNodes = 0;
}

bool OrderedMovieList::is_empty() {
	bool empty = false;
	if (head == nullptr) {
		empty = true;
	}
	return empty;
}
   
std::ostream& operator<<(std::ostream& fout, const OrderedMovieList& list)
{
	list.write(fout);
	return fout;
}
