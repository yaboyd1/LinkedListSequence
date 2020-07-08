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
		assert(is_item());
		++many_nodes;
	}
	void sequence::attach(const value_type& entry) {
		assert(is_item());
		++many_nodes;
	}
	void sequence::remove_current() {
		assert(is_item());
		if (current_ptr == head_ptr) {
			list_head_remove(head_ptr);
		} else {
			list_remove(current_ptr);
		}
		--many_nodes;
	}
	
	void sequence::operator =(const sequence& source) {
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
	}
}
