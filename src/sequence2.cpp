#include <cassert> // Provides assert()
#include <cstdlib> // Provides NULL and size_t
using namespace std;

#include "node2.h" // Provides linked list toolkit
#include "sequence2.h"
using namespace assignment_sequence2;

namespace assignment_sequence2 {
	// CONSTRUCTORS and DESTRUCTOR
	sequence::sequence() {
		head_ptr = NULL;
		tail_ptr = NULL;
		current_ptr = NULL;
		many_nodes = 0;
	}

	sequence::sequence(const sequence& source) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		current_ptr = source.current_ptr;
	}

	sequence::~sequence() {
		list_clear(head_ptr);
	}

	// MODIFICARION MEMBER FUNCTIONS
	void sequence::start() {
		current_ptr = head_ptr;
	}

	void sequence::advance() {
		current_ptr = current_ptr -> link();
	}

	void sequence::insert(const value_type& entry) {
		if (many_nodes == 0) {
			list_head_insert(head_ptr);
			current_ptr = NULL;
		} 
		else if (is_item() == false) {
			list_insert(tail_ptr);
			current_ptr = head_ptr;
		} 
		else {
			list_insert(current_ptr);
			current_ptr = current_ptr -> link();
		}
		++many_nodes;
	}

	void sequence::attach(const value_type& entry) {
		if (many_nodes == 0) {
			list_head_insert(head_ptr);
			current_ptr = head_ptr;
		} 
		else if (is_item() == false) {
			list_head_insert(head_ptr);
			current_ptr = tail_ptr;
		}
		else {
			list_insert(current_ptr);
			current_ptr = current_ptr -> link();
		}
		++many_nodes;
	}

	void sequence::remove_current() {
		assert(is_item());
		if (many_nodes == 1) {
			list_head_remove(head_ptr);
			current_ptr = NULL;
		}
		else if (current_ptr == head_ptr) {
			list_head_remove(head_ptr);
			current_ptr = head_ptr;
		} else if (current_ptr == tail_ptr) {
			list_remove(tail_ptr);
			current_ptr = tail_ptr;
		}
		else {
			list_remove(current_ptr);
			current_ptr = current_ptr -> link();
		}
		--many_nodes;
	}
	
	void sequence::operator =(const sequence& source) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		current_ptr = source.current_ptr;
	}
}
