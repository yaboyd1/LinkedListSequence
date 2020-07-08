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
		if (many_nodes == 0) {
			precursor = head;
			list_head_insert(head);
			cursor = head;
		} 
		else if (is_item() == false) {
			list_head_insert(head);
			precursor = NULL;
			cursor = head;
		}
		else {
			list_insert(precursor);
			precursor = precursor->link();
			cursor = cursor->link();
		}
		++many_nodes;
	}

	void sequence::attach(const value_type& entry) {
		if (many_nodes == 0) {
			precursor = head;
			list_head_insert(head);
			cursor = head;
		} 
		else if (is_item() == false) {
			precursor = tail;
			list_insert(tail);
			cursor = tail;
		} 
		else {
			precursor = precursor->link();
			list_insert(cursor);
			cursor = cursor->link();
		}
		++many_nodes;
	}

	void sequence::remove_current() {
		assert(is_item());
		if (many_nodes == 1) {
			list_head_remove(head);
			precursor = NULL;
			cursor = NULL;
		}
		else if (cursor == head) {
			precursor = NULL;
			list_head_remove(head);
			cursor = head;
		} 
		else if (cursor == tail) {
			tail = precursor;
			list_remove(tail);
			cursor = NULL;
		}
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
