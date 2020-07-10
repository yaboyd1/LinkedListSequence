#include <cassert> // Provides assert()
#include <cstdlib> // Provides NULL and size_t
using namespace std;

#include "node2.h" // Provides linked list toolkit
#include "sequence2.h"
using namespace assignment_sequence2;

namespace assignment_sequence2 {
	// CONSTRUCTORS and DESTRUCTOR
	sequence::sequence() {
		head = NULL;
		tail = NULL;
		cursor = NULL;
		precursor = NULL;
		many_nodes = 0;
	}

	sequence::sequence(const sequence& source) {
		list_copy(source.head, head, tail);
		many_nodes = source.many_nodes;
		cursor = source.cursor;
		precursor = source.precursor;
	}

	sequence::~sequence() {
		list_clear(head);
		precursor = NULL;
		cursor = NULL;
		many_nodes = 0;
	}

	// MODIFICARION MEMBER FUNCTIONS
	void sequence::start() {
		precursor = NULL;
		cursor = head;
	}

	void sequence::advance() {
		precursor = cursor;
		cursor = cursor->link();
	}

	void sequence::insert(const value_type& entry) {
		/* If empty, set the tail */
		if (many_nodes == 0) {
			precursor = NULL;
			list_head_insert(head, entry);
			cursor = head;
			tail = head; /* Set tail */
		} 
		/* If no item or cursor points to the first item, insert at head */
		else if (is_item() == false || cursor == head) {
			list_head_insert(head, entry);
			precursor = NULL;
			cursor = head;
		}
		/* Inserts at the middle of the list */
		else {
			list_insert(precursor, entry);
			precursor = precursor->link();
			cursor = cursor->link();
		}
		++many_nodes;
	}

	void sequence::attach(const value_type& entry) {
		/* If empty, set tail */
		if (many_nodes == 0) {
			precursor = head;
			list_head_insert(head, entry);
			cursor = head;
			tail = head; /* Set tail */
		} 
		/* If no item or cursor points to the last item, insert at tail */
		else if (is_item() == false || cursor == tail) {
			precursor = tail;
			list_insert(tail, entry);
			tail = tail->link(); /* Update tail */
			cursor = tail;
		} 
		/* Attaches at the middle of the list */
		else {
			precursor = cursor;
			list_insert(cursor, entry);
			cursor = cursor->link();
		}
		++many_nodes;
	}

	void sequence::remove_current() {
		assert(is_item());
		/* If just one node, remove at head */
		if (many_nodes == 1) {
			list_head_remove(head);
			precursor = NULL;
			cursor = NULL;
			tail = NULL;
		}
		/* If first item, remove at head, set cursor to head */
		else if (cursor == head) {
			precursor = NULL;
			list_head_remove(head);
			cursor = head;
		} 
		/* If last item, remove at tail, set cursor as NULL, update tail */
		else if (cursor == tail) {
			tail = precursor; /* Update tail */
			list_remove(tail);
			cursor = NULL;
		}
		/* Remove at middle */
		else {
			list_remove(cursor);
			cursor = cursor->link();
		}
		--many_nodes;
	}
	
	void sequence::operator =(const sequence& source) {
		list_copy(source.head, head, tail);
		many_nodes = source.many_nodes;
		cursor = source.cursor;
		precursor = source.cursor;
	}
}
