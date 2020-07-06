#include <cassert> // Provides assert()
#include <cstdlib> // Provides NULL and size_t
using namespace std;

#include "node2.h" // Provides linked list toolkit
#include "sequence2.h"
using namespace assignment_sequence2;

namespace assignment_sequence2 {
	// CONSTRUCTORS and DESTRUCTOR
	sequence::sequence();
	sequence::sequence(const sequence& source);
	sequence::~sequence();
    // MODIFICATION MEMBER FUNCTIONS
	void sequence::start();
	void sequence::advance();
	void sequence::insert(const value_type& entry);
	void sequence::attach(const value_type& entry);
	void sequence::remove_current();
	void sequence::operator =(const sequence& source);
}